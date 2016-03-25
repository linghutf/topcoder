#ifndef QSORT_HH_
#define QSORT_HH_
//#pragma once

#include <algorithm>
//#include <iostream>
//#include <iomanip>

#include "insertsort.hh"

#define CUTTOINSERT 10


template<typename T,class Compare> int Partition(T &array,int low,int high,Compare comp)
{
    int i = low+1,j=high;
    T r = array[low];
    while(true){
        while(comp(array[i],r)<0){
            if(i==high) break;
            ++i;
        }
        while(comp(array[j],r)>0){
            if(j==low) break;
            --j;
        }
        if(i>=j) break;
        std::swap(array[i],array[j]);
    }
    std::swap(array[j],array[low]);
    return j;
}

template<typename T,class Compare> void QuickSort(T &array,int low,int high,Compare comp)
{
    if(low>=high) return;
    //小序列，直接采用插入排序
    if(high-low<=CUTTOINSERT-1){
        InsertSort(array,low,high+1,comp);
        return;
    }
    int index = Partition(array,low,high,comp);
    QuickSort(array,low,index-1,comp);
    QuickSort(array,index+1,high,comp);
}

template<typename T,class Compare> void Qsort(T &array,int len,Compare comp)
{
    QuickSort(array,0,len-1,comp);
}

template<typename T> int Partition(T &array,int low,int high)
{
    int i = low+1,j=high;
    //T r = (&array)[low];
    while(true){
        while((&array)[i]<(&array[low])){
            if(i==high) break;
            ++i;
        }
        while((&array)[j]>(&array)[low]){
            if(j==low) break;
            --j;
        }
        if(i>=j) break;
        std::swap(array[i],array[j]);
    }
    std::swap(array[j],array[low]);
    return j;
}

template<typename T> void QuickSort(T &array,int low,int high)
{
    if(low>=high) return;
    //小序列，直接采用插入排序
    if(high-low<=CUTTOINSERT-1){
        InsertSort(array,low,high+1);
        return;
    }
    int index = Partition(array,low,high);
    //std::for_each(&array+low,&array+high+1,[](T &n){std::cout<<std::setw(3)<<n;});
    //std::cout<<std::endl;

    QuickSort(array,low,index-1);
    QuickSort(array,index+1,high);
}

template<typename T> void Qsort(T &array,int len)
{
    QuickSort(array,0,len-1);
}
#endif
