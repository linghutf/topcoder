/**
 * 多线程 生产者-消费者
 * 线程只能使用全局函数和静态函数
 * 类的成员函数无法传递进线程函数中
 * 信号量condition和互斥量mutex是成对使用，
 * P(V)操作等待V(P)信号量
 * 使用一个mutex会导致死锁，一个在等待而没有释放锁，
 * 另一个得不到锁无法运行
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
//#include <vector>

using namespace std;

int a = 19;//不能使用局部变量传递到到线程函数中，默认会复制一份，即使是使用引用型参数


std::mutex pmtx,vmtx;
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
            if(a>UP){
                //cout<<"P wait..."<<endl;
                pcv.wait(vmtx);//已经锁住
                //cout<<"P begin..."<<endl;
            }
            //std::lock(bufmtx);
            //mtx.unlock();
            pmtx.lock();
            //mtx.unlock();
            //if(mtx.try_lock()){
            cout<<"原有:"<<a;
            produce(a,p);
            std::cout<<"生产了:"<<p<<",总数:"<<a<<endl;
            pmtx.unlock();
            vcv.notify_all();
        }
    }

    static void doComsume(int c){
        while(true){

            if(a<UP){
                //cout<<"V wait..."<<endl;
                vcv.wait(pmtx);
                //mtx.unlock();
                //cout<<"V again..."<<endl;
            }
            //cout<<"come here..."<<endl;
            //mtx.unlock();
            //std::lock(bufmtx);
            vmtx.lock();
            //if(mtx.try_lock()){
            std::cout<<"原有:"<<a;
            consume(a,c);
            std::cout<<"消费了:"<<c<<",总数:"<<a<<endl;
            vmtx.unlock();
            pcv.notify_all();
            //}
        }
    }
};

int main(int argc, char *argv[])
{
    //Observer obs;
    int p = 4,c=5;
    //std::vector<std::thread> v;
    std::thread ths[2];
    ths[0]=std::thread(std::bind(Observer::doProduce,p));
    ths[1]=std::thread(std::bind(Observer::doComsume,c));
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for(auto &t:ths)
        t.join();
    return 0;
}
