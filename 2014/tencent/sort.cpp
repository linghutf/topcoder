#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>

using namespace std;

void bublle_sort(int *a,int len)
{
    int i,j;
    for(i=0;i<len-1;++i)
        for(j=i;j<len-1-i;++j)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

void insert_sort(int *a,int len)
{
    int i,j;
    int tmp;
    for(i=0;i<len;++i){
        for(j=0;j<i;++j){
            if(a[j]>a[i]) swap(a[i],a[j]);
        }
    }

}

int partition(int *a,int low,int high)
{
    int priv = a[low];
    while(low<high){
        while(low<high && a[high]>priv) --high;
        a[low]=a[high];//移动比枢纽小的元素

        while(low<high && a[low]<priv) ++low;
        a[high]=a[low];//移动比枢纽大的元素
    }
    return low;//枢纽位置
}
void myqsort(int *a,int low,int high)
{
    if(low<high){
        int priv=partition(a,low,high);//枢纽
        myqsort(a,low,priv-1);
        myqsort(a,priv+1,high);
    }
}

void quick_sort(int *a,int len)
{
    myqsort(a,0,len-1);
    /*
    int i,j,k;
    for(i=1;i<len-1;++i){
        j=0;k=len-1;
        for(;j<i;++j){
            if(a[j]>a[i]) swap(a[j],a[k]);
        }
        for(;k>i;--k){
            if(a[k]<a[i]) swap(a[j],a[k]);
        }
    }*/
}

int main(int argc, char *argv[])
{
    int a[]={2,-1,4,5,2};

    bublle_sort(a,5);
    for_each(a,a+5,[](auto i){cout<<i<<'\t';});
    cout<<endl;

    srand(time(NULL));
    std::random_shuffle(a,a+5);
    auto randfunc = [](int i){return rand()%i;};
    std::random_shuffle(a,a+5,randfunc);

    cout<<"Before:";
    for_each(a,a+5,[](auto i){cout<<i<<'\t';});
    cout<<endl;

    quick_sort(a,5);
    for_each(a,a+5,[](auto i){cout<<i<<'\t';});
    cout<<endl;

    return 0;
}
