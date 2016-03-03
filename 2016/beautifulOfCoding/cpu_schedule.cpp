#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>

using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool run = false;

void task();

int main(int argc, char *argv[])
{
    if(argc<2){
        cout<<argv[0]<<" cpu-busy-degree[1~100]."<<endl;
        return -1;
    }
    int range = 100;
    int t;
    int s=atoi(argv[1]);
    srand(time(NULL));
    std::thread ths(task);
    while(true){
        t = rand()%range;
        //cout<<"rand num:"<<t<<endl;
        if(t<s){
            run = true;
            cv.notify_one();
        }else{
            run = false;
        }
    }
    return 0;
}

void task()
{
    std::unique_lock<std::mutex> lcx(mtx);
    while(run);
    cv.wait(lcx);
    //sleep
    //while(!run) cv.wait(lcx);
}
