/**
 * 采用快排划分的思想将数字按照性质划分
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <algorithm>

#include <boost/foreach.hpp>

template<typename Pred>
void partition(int *a, size_t len)
{
    if(a==NULL||len==0)
        return;
    Pred pred;
    int low = 0;
    int high = len - 1;
    while(low<=high)
    {
        while(pred(a[low])) ++low;
        while(!pred(a[high])) -- high;
        if(low>high) break;
        std::swap(a[low++],a[high--]);
    }
}

struct IsEven{
    bool operator()(int n)
    {
        return n&(n-1)!=0;
    }
};
/*
struct Random{
    int operator()(int n)
    {
        return rand()%n;
    }
};
*/
int myrandom(int i)
{
    return rand()%i;
}

void test_part()
{
    srand(time(NULL));
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(a)/sizeof(a[0]);

    std::random_shuffle(a,a+len,myrandom);
    BOOST_FOREACH(int & n ,a)
    {
        printf("%3d",n);
    }
    printf("\n");

    partition<IsEven>(a,len);

    BOOST_FOREACH(int & n ,a)
    {
        printf("%3d",n);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    test_part();
    return 0;
}
