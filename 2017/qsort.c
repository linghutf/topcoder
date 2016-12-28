#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap(int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int * a, int left, int right)
{
    int high = right+1;
    int low = left-1;
    int val = a[left];
    while(1)
    {
        while(a[++low]<val);
        while(val < a[--high]);
        if(low>=high) return high;
        swap(a+low,a+high);
    }
}

void quicksort(int * a,int left,int right)
{
    if(left<right)
    {
        int privot = partition(a,left,right);
        quicksort(a,left,privot);
        quicksort(a,privot+1,right);
    }
}

void q_sort(int * a,int len)
{
    if(a==NULL||len<=0) return;
    quicksort(a,0,len);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    const int len = 10;
    int arr[len];
    for(int i=0;i<len;++i){
        arr[i]=rand()%100;
    }

    printf("之前:");
    for(int i=0;i<len;++i){
        printf("%4d",arr[i]);
    }
    printf("\n");

    q_sort(arr,len);

    printf("之后:");
    for(int i=0;i<len;++i){
        printf("%4d",arr[i]);
    }
    printf("\n");

    return 0;
}
