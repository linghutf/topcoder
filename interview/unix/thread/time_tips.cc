/**
 * 倒计时提醒
 */
#include <iostream>
#include <thread>

#include <chrono>
#include <ctime>

#include <string>

#include <boost/date_time/gregorian_calendar.hpp>

using namespace std;
using namespace boost::gregorian;

struct Task{
    int t;
    std::string s;
    Task(const string &s_,int t_):s(s_),t(t_){}
};

void timetick(const char *s,const Task &task)
{
    ptime p = time_from_string(s);//(date(2016,3,20,20,27);

    time_duration td = p.time_of_day();

    time_t now;
    time(&now);

 //lib64   time_t now;
 //   time(&now);

    unsigned int t = timediff(task.t);
    std::this_thread::sleep_until();
    cout<<"["<<task.s<<"]时间到!"<<endl;
}

int main(int argc, char *argv[])
{
    if(argc<2){
        cout<argv[0]<<" timer like 2016-02-03 12:30"<<endl;
        return -1;
    }
    //std::thread()
    Task task;


    struct tm tminfo;
    tminfo.tm_year =
    timetick();
    return 0;
}
