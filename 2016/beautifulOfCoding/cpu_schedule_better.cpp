/**
 * 编程之美:cpu占用率测试
 * 想法:
 * 在100内生成随机数,如果大于给定的数字，就程序sleep
 * 否则工作,不断切换达到占用率稳定的程度
 *
 */
#include <iostream>
#include <thread>
#include <chrono>

#include <cstdlib>
#include <ctime>

using namespace std;
/*
void pause(int n)
{
    std::this_thread::sleep_for(std::chrono::microseconds(n));
    std::cout<<"pause time:"<<n<<"us."<<std::endl;
}
*/
int main(int argc, char *argv[])
{
    int area = atoi(argv[1]);
    int t;
    srand(time(NULL));
    while(true){
        t=rand()%100;
        if(t>=area){//sleep
            std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        }
        //work
        cout<<"t:"<<t<<endl;
    }
    return 0;
}
