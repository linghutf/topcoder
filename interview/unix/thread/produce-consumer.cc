/**
 * 多线程 生产者-消费者
 * 线程只能使用全局函数和静态函数
 * 类的成员函数无法传递进线程函数中
 * 信号量condition和互斥量mutex是成对使用，
 * P(V)操作等待V(P)信号量
 * 使用一个mutex会导致死锁，一个在等待而没有释放锁，
 * 另一个得不到锁无法运行
 * 主线程如果退出，子线程还没有被销毁，产生异常
 * join()实现主线程阻塞，知道子线程运行完成
 *
 * 2016-03-19更正
 * 可以重服枷锁，
 * 所以在加锁后判断是否需要等待
 * 只需要一个互斥量和2个信号量
 * 2016-03-20更新观念
 * 条件变量没有被满足时，线程将阻塞,并释放互斥量，
 * 只有wait结束后，才能重新获得互斥量
 * 所以先加锁，然后查看条件变量是否被满足
 */

#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
//#include <vector>

#include <signal.h>

using namespace std;

int a = 19;//不能使用局部变量传递到到线程函数中，默认会复制一份，即使是使用引用型参数


std::mutex mtx;
std::condition_variable_any pcv,vcv;//PV信号量

const int UP =10;

void produce(int &a,int p)
{
    //do produce
    std::this_thread::sleep_for(std::chrono::seconds(1));
    a+=p;
}

void consume(int &a,int c)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    a-=c;
}

struct Observer{

    static void doProduce(int p){
        while(true){
            mtx.lock();
            if(a>UP){
                vcv.wait(mtx);//阻塞，释放互斥量
            }
            //重新获得互斥量
            cout<<"原有:"<<setw(3)<<a;
            produce(a,p);
            std::cout<<"生产了:"<<setw(3)<<p<<",总数:"<<setw(3)<<a<<",id:"<<setw(20)<<std::this_thread::get_id()<<endl;
            mtx.unlock();
            pcv.notify_all();
        }
    }

    static void doComsume(int c){
        while(true){
            mtx.lock();
            if(a<UP){
                pcv.wait(mtx);
            }
            std::cout<<"原有:"<<setw(3)<<a;
            consume(a,c);
            std::cout<<"消费了:"<<setw(3)<<c<<",总数:"<<setw(3)<<a<<",id:"<<setw(20)<<std::this_thread::get_id()<<endl;
            mtx.unlock();
            vcv.notify_all();
        }
    }
};

static void sig_stop(int signo)
{
    if(signo == SIGUSR2){
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[])
{
    //Observer obs;
    int p = 4,c=5;
    //std::vector<std::thread> v;
    std::thread ths[3];
    ths[0]=std::thread(std::bind(Observer::doProduce,p));
    ths[1]=std::thread(std::bind(Observer::doComsume,c));
    ths[2]=std::thread(std::bind(Observer::doComsume,c));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    //listen signal
    signal(SIGUSR2,sig_stop);

    for(auto &t:ths)
        t.join();
    return 0;
}
