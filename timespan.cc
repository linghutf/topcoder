#include <boost/date_time/gregorian/gregorian.hpp>

#include <iostream>

int main(int argc, char *argv[])
{
    boost::gregorian::date d(2017,5,27);
    boost::gregorian::date today;
    if(argc>=2){
        today = boost::gregorian::from_string(argv[1]);
    }else{
        today = boost::gregorian::day_clock::local_day();
    }
    std::cout<<"left:"<<(d-today)<<std::endl;
    return 0;
}
