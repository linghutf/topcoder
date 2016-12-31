#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

#include <boost/foreach.hpp>

#include "bin_search.h"

int bin_search_not_first(int a[],size_t n,int key)
{
    if(a==NULL||n==0)
    {
        return -1;
    }
    int low = 0, high = n;
    int mid;
    while(low<=high)
    {
        mid = low+(high-low)/2;
        // 找到的不是第一次出现的位置
        if(key==a[mid]) return mid;
        else if(key<a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int bin_search(int a[],size_t n,int key)
{
    if(a==NULL||n==0)
    {
        return -1;
    }
    int low = 0, high = n;
    int mid;
    while(low<high)
    {
        //mid = (low+high)/2;// overflow problem
        mid = low+(high-low)/2;
        // 找到的不是第一次出现的位置
        /*
        if(key==a[mid]) return mid;
        else if(key<a[mid]) high = mid - 1;
        else if(key>a[mid]) low = mid + 1;
        */
        if(key==a[mid])
        {
            return mid;
        }
        if(a[low]<=a[mid])
        {
            if(a[low]<=key && key<a[mid])
                high = mid;
            else
                low = mid + 1;
        }
        else
        {
            if(a[mid]<key && key<=a[high-1])
                low = mid + 1;
            else
                high = mid;
        }
    }
    return -1;
}

int compare(const void * a,const void * b)
{
    return *(int *)a-*(int*)b;
}

int main(int argc, char *argv[])
{
    int a[]={2,2,3,5,6,6,6,7,7};
    int len = sizeof(a)/sizeof(a[0]);

    int num = atoi(argv[1]);
    int idx = bin_search(a,len,num);
    int idx_err = bin_search_not_first(a,len,num);
    Solution sol;
    int idxr = sol.search(a,len,num);

    int * pos = (int*)bsearch(&num,a,len,sizeof(a[0]),compare);

    if(idx!=-1 || idx_err!=-1 || idxr != -1 || pos!=a+len)
    {
        assert(a[idx]==num);
        printf("pos:%4ld,idxr:%4d,idx:%4d,idx_err:%4d\n",pos-a,idxr,idx,idx_err);
        int i = 0;
        BOOST_FOREACH(int & n,a)
        {
            printf("%4d(%d)",n,i++);
        }
        printf("\n");
    }

    return 0;
}
