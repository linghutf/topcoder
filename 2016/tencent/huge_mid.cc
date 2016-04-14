#include <iostream>
#include <iomanip>
#include <algorithm>

#include <map>

using namespace std;

#define SEGN 65536

//typedef int[SEGN] Map;
int count_prev = 0;
int count_cur = 0;

int findPos(int* m,int bnums)
{
    int count = 0;
    for(int i=0;i<SEGN;++i){
        if((count<bnums) &&(count+m[i]>=bnums)){
            count_cur = m[i];
            count_prev = count;
            return i;
        }
        count+=m[i];
    }
    return 0;//not found
}

int findHigh(int *a,int len,int* high)
{
    for(int i=0;i<len;++i){
        high[a[i]>>16]++;
    }

    return findPos(high,len>>1);
}

int findLow(int *a,int len,int high,int* low)
{
    int count = 0;
    for(int i=0;i<len;++i){
        if(high==(a[i]>>16)){
            low[a[i]&0x0000ffff]++;
            count++;
        }
    }
    for(int i=0;i<50;++i){
        cout<<setw(4)<<low[i];
    }
    cout<<endl<<"count:"<<count<<endl;
    //寻找位置
    int pos = (len>>1)-count_prev+1;
    cout<<"prev:"<<count_prev<<",cur:"<<count_cur<<",pos:"<<pos<<endl;
    return findPos(low,pos);
}

int main()
{
    int a[11];
    int len = 11;
    for(int i=0;i<len;++i){
        cin>>a[i];
    }
    //int len = sizeof(a)/sizeof(a[0]);

    int low[SEGN]={0},high[SEGN]={0};
    int h=findHigh(a,len,high);
    int l=findLow(a,len,h,low);

    cout<<"low:"<<std::hex<<l<<",high:"<<std::hex<<(h<<16)<<endl;
    int num = (h<<16)+l;
    cout<<"mid:"<<std::dec<<num<<endl;
    return 0;
}
