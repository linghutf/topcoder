/**
 *
 * 用户应该检查isErrorDate是否是错误的日期，否则调用结果
 * 出现异常，库函数只是识别错误日期
 * 而不会出现异常
 */

#ifndef DATE_HH_
#define DATE_HH_

typedef long timespan;

const static int MONTH[]={
    31,28,31,30,31,30,
    31,31,30,31,30,31
};

const static char WEEKNAME[][5]={
    "Sun","Mon","Tues","Wed","Thur","Fri","Sat"
};
//extern class Date;
//extern timespan daysDiff(Date& d,Date &od);

class Date{
private:
    int year_;
    unsigned short month_;
    unsigned short day_;
    timespan span_;
    timespan days_of_year_;
    unsigned char weekname_;

    bool errorDate_;

    void setErrorDate()
    {
        this->errorDate_ = TestIsLegalDate(this->year_,this->month_,this->day_);
    }

public:
    static unsigned char GetWeek(int y,unsigned short m,unsigned short d)
    {
        if(m<3){
            m+=12;
            --y;
        }
        return (d+1+(m<<1)+3*(m+1)/5+y+(y>>2)-y/100+y/400) % 7;
    }

    static bool TestIsLegalDate(int y,unsigned short m,unsigned short d)
    {
        bool errorDate = false;

        if(y==0||m>12||m<1||d>31||d<1){
            errorDate=true;
        }
        if(Date::isLeapYear(y)){
            if(m==2&&d>29) errorDate = true;
            else if(m!=2&&MONTH[m-1]<d) errorDate = true;
        }else{
            if(MONTH[m-1]<d) errorDate = true;
        }
        return errorDate;
    }

    Date(int y=0,unsigned short m=1,unsigned short d=1):year_(y),month_(m),day_(d),span_(-1){
        this->setErrorDate();
        days_of_year_ = 0;
    }

    Date(Date &d):year_(d.year_),month_(d.month_),day_(d.day_),span_(d.span_),errorDate_(d.errorDate_),days_of_year_(0){}

    Date& operator=(Date &d)
    {
        this->year_=d.year_;
        this->month_=d.month_;
        this->day_=d.day_;
        this->span_=d.span_;
        this->errorDate_=d.errorDate_;
        return *this;
    }

    bool isErrorDate(){return this->errorDate_;}

    int year(){return this->year_;}
    void setYear(int year){this->year_=year;}

    unsigned short month(){return this->month_;}
    void setMonth(int month)
    {
        this->month_=month;
        this->setErrorDate();
    }

    unsigned short day(){return this->day_;}
    void setDay(int day)
    {
        this->day_=day;
        this->setErrorDate();
    }
    //like unix timespan
    timespan span();

    //timediff
    timespan operator-(Date& d);

    timespan daysOfYear();
    const char* weekname();

    static bool isLeapYear(int y)
    {
        return (y%4==0&&y%100!=0)||(y%400==0);
    }
};

//this - d
timespan Date::operator-(Date& d)
{
    return this->span()-d.span();
}

const char* Date::weekname()
{
    if(!this->isErrorDate()){
        this->weekname_ = Date::GetWeek(this->year(),this->month(),this->day());
        return WEEKNAME[this->weekname_];
    }
}

timespan Date::daysOfYear()
{
    if(this->isErrorDate()) return 0;

    Date zero(this->year_,1,1);
    this->days_of_year_ = (*this-zero)/3600/24+1;
    return this->days_of_year_;
}

timespan Date::span()
{
    //出现错误日期
    if(this->isErrorDate()) return 0;

    timespan i,flag=1,result=0;
    if(this->year_<0){
        flag = -1;
        for(i=this->year_;i<0;++i){
            result+=Date::isLeapYear(i)?366:365;
        }
    }else{
        for(i=1;i<this->year_;++i){
            result+=Date::isLeapYear(i)?366:365;
        }
    }
    result*=3600*24;
    timespan days = (this->month_>2&&Date::isLeapYear(this->year_))?1:0;
    for(i=1;i<this->month_;++i){
        days += MONTH[i-1];
    }
    days+=this->day_;
    if(this->year_<0) result-=days*24*3600;
    else result+=days*24*3600;

    this->span_ = flag*result;

    return this->span_;
}

//od - d
timespan daysDiff(Date& d,Date& od)
{
    timespan diff = od-d;
    return (diff/3600/24);
}

timespan weeksDiff(Date& d,Date& od)
{
    return daysDiff(d,od)/7;
}

#endif
