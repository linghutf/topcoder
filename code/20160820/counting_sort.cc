#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void counting_sort(int *ini_arr,int *sorted_arr,int n)
{
    int *count_arr = new int[100];
    int i,j,k;
    memset(count_arr,0,100*sizeof(int));
    for (i = 0; i < n; ++i) {
        count_arr[ini_arr[i]]++;
    }
    for (k = 0; k < 100; ++k) {
        count_arr[k]+=count_arr[k-1];
    }
    for (j = n; j > 0; --j) {
        sorted_arr[count_arr[ini_arr[j-1]]-1] = ini_arr[j-1];
        count_arr[ini_arr[j-1]]--;
    }
    delete[] count_arr;
}

void test_sort()
{
    const int num = 10;
    int arr[num];
    srand(time(NULL));
    for (int i = 0; i < num; ++i) {
        arr[i]=rand()%100;
    }
    std::for_each(arr,arr+num,[](int n){std::cout<<std::setw(4)<<n;});
    std::cout<<std::endl<<"After sort.\n";

    int sorted_arr[num];
    counting_sort(arr,sorted_arr,num);

    std::for_each(sorted_arr,sorted_arr+num,[](int n){std::cout<<std::setw(4)<<n;});
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    test_sort();
    return 0;
}
