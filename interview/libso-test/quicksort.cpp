#include "quicksort.h"

int RandomInRange(int s,int e)
{
    return rand()%(e-s+1)+s;
}
/**
 * start = 0
 * end = length -1
 *
 */
int Partition(int data[],int length,int start,int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >=length)
        throw std::runtime_error("Invalid Parameters");

    int index = RandomInRange(start,end);
    std::swap(data[index],data[end]);

    int small = start -1;
    for(index = start;index < end;++index)
    {
        if(data[index] < data[end])
        {
            ++small;
            if(small != index)
                std::swap(data[index],data[small]);
        }
    }

    ++small;
    std::swap(data[small],data[end]);
    return small;
}

void QuickSort(int data[],int length,int start,int end)
{
    if(start==end)
        return;
    int index = Partition(data,length,start,end);
    if(index>start)
        QuickSort(data,length,start,index-1);
    if(index<end)
        QuickSort(data,length,index+1,end);
}

void quicksort(int data[],int length)
{
    if(data==NULL||length<=0)
        return;
    QuickSort(data,length,0,length-1);
}
