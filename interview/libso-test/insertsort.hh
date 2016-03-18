#pragma once

#include <algorithm>
//#include <concept>
//array:[low,high)
template<typename T,class Compare> void InsertSort(T &array,int low,int high,Compare comp)
{
    int i,j;
    for(i=low+1;i<high;++i){
        for(j=i;j>0;--j){
            if(comp(array[j],array[j-1])<0)//比之前一个小，插入
                std::swap(array[j],array[j-1]);
            else
                break;//前面已有序，找到了正确位置
        }
    }
}


template<typename T> void InsertSort(T &array,int low,int high)
{
    //InsertSort(array,low,high,[](const T& a,const T& b){return a<b;});//不行
    int i,j;
    for(i=low+1;i<high;++i){
        for(j=i;j>0;--j){
            if(array[j]<array[j-1])//比之前一个小，插入
                std::swap(array[j],array[j-1]);
            else
                break;//前面已有序，找到了正确位置
        }
    }

}
