#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

std::mutex mtx;
std::condition_variable notify,stop;

bool isready = false;

void run(int &a)
{

    std::unique_lock<std::mutex> lck(mtx);

    while(lck.try_lock()){//不断运行.notify没用
        std::this_thread::sleep_for(std::chrono::seconds(2));
        ++a;
        cout<<a<<endl;
        isready = true;
        lck.unlock();
        notify.notify_all();
    }
}

int main(int argc, char *argv[])
{
    int a =10;
    std::thread t = std::thread(std::bind(run,a));

    std::unique_lock<std::mutex> lck(mtx);
    while(lck.try_lock()){
    --a;
    cout<<"a:"<<a<<endl;
    while(!isready) notify.wait(lck);
    }
    t.join();
    --a;
    cout<<"a:"<<a<<endl;
    //stop.notify_all();
    //t.join();//最后主线程退出时线程还在运行，所以需要让主线程等待
    return 0;
}
