#include <iostream>

#include "date.hh"

using namespace std;

void testcase(Date& d,Date &od)
{
    //Date d(2016,2,20);
    //Date now(2016,3,1);
    cout<<"年第几天:"<<d.daysOfYear()<<",now:"<<od.daysOfYear()<<endl;
    cout<<"周:"<<d.weekname()<<",other:"<<od.weekname()<<endl;
    cout<<"span:"<<d.span()<<",now:"<<od.span()<<endl;
    cout<<"diff:"<<daysDiff(d,od)<<endl;
}

int main()
{
    Date d(2016,4,15);
    Date od(2016,4,16);
    testcase(d,od);

    Date pd(-1,12,31);
    Date pod(1,1,1);
    testcase(pd,pod);

    return 0;
}
