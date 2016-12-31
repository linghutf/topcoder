/**
 * 美团笔试有序数组交替输出数字
 * 1,2,3,4 => 4,1,3,2
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

int main(int argc, char *argv[])
{
    int a[]={1,2,3,4,5,6};
    int len = sizeof(a)/sizeof(a[0]);
    int * p = a;
    int * q = a+len-1;
    while(p<q)
    {
        std::cout<<std::setw(3)<<*q--<<std::setw(3)<<*p++;
    }
    if(len%2!=0)
    {
        std::cout<<std::setw(3)<<*p;
    }
    std::cout<<std::endl;
    return 0;
}
