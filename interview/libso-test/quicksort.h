#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>
#include <algorithm>

#include <cstdlib>
#include <ctime>

int RandomInRange(int s,int e);
int Partition(int data[],int length,int start,int end);
void QuickSort(int data[],int length,int start,int end);
void quicksort(int data[],int length);

#endif
