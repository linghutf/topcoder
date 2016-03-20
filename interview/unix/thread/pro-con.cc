/**
 *
 * 读写锁带来了新问题:
 * 不够减和加满之后还会再加
 * 而且增减数目显示不正确
 * 使用一个互斥量则没有这种问题
 */
#include <iostream>
#include <iomanip>
#include <signal.h>
#include <cstdlib>
#include <queue>
#include <thread>
//#include <mutex>

#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/condition_variable.hpp>

//#include <condition_variable>
#include <chrono>

using namespace std;

typedef std::queue<int> Buffer;
//full
const int BUFFLEN = 12;

boost::shared_mutex mtx;
//std::mutex mtx;
//boost::unique_lock<boost::shared_mutex> wlock(mtx,boost::defer_lock);//写锁
//boost::shared_lock<boost::shared_mutex> rlock(mtx,boost::defer_lock);//读锁

//boost::condition_variable_any;
boost::condition_variable_any emptycv,fullcv;//full,empty


void Produce(Buffer& buf,int addnum,unsigned int timeofunit)
{
    while(true){
        //get read lock
        mtx.lock_shared();
        //boost::lock(rlock,wlock);
        if(buf.size()>BUFFLEN){
            mtx.unlock_shared();
            mtx.lock();//grab mutex
            fullcv.wait(mtx);//阻塞自己，释放互斥量,知道条件变量获得满足,然后获取互斥量
        }else{
            mtx.unlock_shared();
            mtx.lock();
        }
        //boost::unlock(rlock);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeofunit));
        int i;
        for(i=0;i<addnum;++i){
            if(buf.size()>BUFFLEN) break;
            buf.push(1);
        }
        cout<<"["<<setw(20)<<std::this_thread::get_id()<<"]: 增加了:"<<setw(4)<<i<<",现有:"<<setw(6)<<buf.size()<<endl;
        //boost::unlock(wlock);
        mtx.unlock();
        emptycv.notify_all();//notify consumer
    }
}

void Consume(Buffer& buf,int subnum,unsigned int timeofunit)
{
    while(true){
        mtx.lock_shared();
        if(buf.size()<subnum){
            mtx.unlock_shared();
            mtx.lock();//write lock
            emptycv.wait(mtx);
        }else{
            mtx.unlock_shared();
            mtx.lock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(timeofunit));
        //如果不够则让出
        int i;
        for(i=0;i<subnum;++i){
            if(buf.empty()) break;
            buf.pop();
        }

        cout<<"["<<setw(20)<<std::this_thread::get_id()<<"]: 消耗了:"<<setw(4)<<i<<",现有:"<<setw(6)<<buf.size()<<endl;
        mtx.unlock();
        fullcv.notify_all();//notify producer
    }
}

void Observe(const Buffer& buf)
{
    while(true){
        mtx.lock_shared();//get read lock
        cout<<"["<<setw(20)<<std::this_thread::get_id()<<"]: 监测值:"<<setw(6)<<buf.size()<<endl;
        mtx.unlock_shared();//release read lock
        std::this_thread::sleep_for(std::chrono::seconds(3));//every 5s check
    }
}

void thread_exit(std::thread* ths,int num)
{
    std::thread *p = ths;
    while(p<ths+num){
        p->detach();
        ++p;
    }
}

void stop(int signo)
{
    if(signo==SIGUSR2){
        cout<<"进程退出!"<<endl;
        exit(EXIT_SUCCESS);
        //thread_exit(ths,num);
    }
}

int main(int argc, char *argv[])
{
    //init
    int add = 4,sub = 5;
    unsigned int timeofpro = 500,timeofcon = 400;
    Buffer buffer;
    std::thread ths[5];
    ths[0] = std::thread(Produce,std::ref(buffer),add,timeofpro);
    ths[1] = std::thread(Consume,std::ref(buffer),sub,timeofcon);
    ths[2] = std::thread(Consume,std::ref(buffer),sub,timeofcon);
    ths[3] = std::thread(Produce,std::ref(buffer),add,timeofpro);
    ths[4] = std::thread(Observe,std::ref(buffer));
    //进程接受自定义退出信号
    signal(SIGUSR2,stop);
    //std::thread(,std::ref(ths),)
    for(auto &t:ths)
        t.join();
    return 0;
}


