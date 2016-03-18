/**
 * 位图排序
 * 无重复但是有负数
 */

#include <iostream>
#include <bitset>
#include <algorithm>

#include <boost/dynamic_bitset.hpp>

#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <climits>

using namespace std;

//栈溢出
//std::bitset<INT_MAX> pos_bitmap;//非负数
//std::bitset<INT_MAX> neg_bitmap;//负数

//typedef boost::dynamic_bitset<INT_MAX> bitmap;

//int test[INT_MAX];//测试数据

void generate_N(int a[],int nums)
{
    srand(time(NULL));
    int n;
    for(int i=0;i<nums;++i){
        n = rand()%RAND_MAX;
        a[i]=rand()%2?~n:n;
    }
}

void Sort(int a[],int len,boost::dynamic_bitset<> &pos_bitmap,boost::dynamic_bitset<> &neg_bitmap)
{
    for(int i=0;i<len;++i){
        if(a[i]<0){
            neg_bitmap.set(-a[i],1);
        }else{
            pos_bitmap.set(a[i],1);
        }
    }
}

//升序还是降序
void print(boost::dynamic_bitset<> &pos_bitmap,boost::dynamic_bitset<> &neg_bitmap,int d)
{
    if(d>0){//降序
        for(int i=INT_MAX-1;i>=0;--i)
            if(pos_bitmap[i])
                cout<<i<<'\t';
        for(int i=0;i<INT_MAX;++i)
            if(neg_bitmap[i])
                cout<<-i<<'\t';
        cout<<endl;
    }else{
        for(int i=INT_MAX-1;i>=0;--i)
            if(neg_bitmap[i])
                cout<<i<<'\t';
        for(int i=0;i<INT_MAX;++i)
            if(pos_bitmap[i])
                cout<<-i<<'\t';
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    int len = INT_MAX;
    int *a = new int[len];
    boost::dynamic_bitset<> pos_bitmap(INT_MAX),neg_bitmap(INT_MAX);
    generate_N(a,len);

    Sort(a,len,pos_bitmap,neg_bitmap);

    print(pos_bitmap,neg_bitmap,1);
    delete[] a;
    return 0;
}


