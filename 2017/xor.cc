#include <iostream>
#include <algorithm>

#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXN 100000
int ARRAY[MAXN];

int num_of_xor(int arr[],int n,int m)
{
    int cnt = 0;
    if(arr==NULL||n<=0) return cnt;

    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if((arr[i]^arr[j])>m)
            {
                ++cnt;
            }
        }
    }
    return cnt;
}

void testcase()
{
    srand(time(NULL));

    int n = 100000;
    for(int i = 0;i<n;++i)
    {
        ARRAY[i]=rand()%n+1;
    }
    int m = rand()%n+1;

    struct timeval s,t;
    gettimeofday(&s,NULL);
    int res = num_of_xor(ARRAY,n,m);
    gettimeofday(&t,NULL);

    std::cout<<res<<",time:"<<(t.tv_sec-s.tv_sec)*1000+(t.tv_usec-s.tv_usec)/1000<<std::endl;
}

int main(int argc, char *argv[])
{
/*
    int n,m;
    std::cin>>n>>m;

    for(int i=0;i<n;++i)
    {
        std::cin>>ARRAY[i];
    }

    std::cout<<num_of_xor(ARRAY,n,m)<<std::endl;
*/
    testcase();
    return 0;
}
