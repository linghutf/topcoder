#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iterator>

#include <boost/foreach.hpp>

void autogen(size_t n,std::vector<int> * vec)
{
    if(n==0||vec==NULL)
        return;

    srand(time(NULL));

    for(size_t i=0;i<n;++i)
    {
        vec->push_back(rand()%10);
    }
}

int remove_duplicate(int a[],size_t n)
{
    if(a==NULL||n==0)
    {
        return 0;
    }
    size_t idx = 0;
    for(size_t i=1;i<n;++i)
    {
        if(a[idx]!=a[i])
        {
            a[++idx]=a[i];
        }
    }
    return n-idx-1;
}

void test_c_dupl()
{
    int a[]={2,2,2,3,3};
    int n = sizeof(a)/sizeof(a[0]);
    int num = remove_duplicate(a,n);
    for(int i=0;i<n-num;++i)
    {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    autogen(18,&vec);
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout,"\t"));
    std::cout<<"\n";

    std::sort(vec.begin(),vec.end());
    size_t num = 0;
    std::cout<<"remove numbers:"<<(num = std::distance(vec.begin(),std::unique(vec.begin(),vec.end())))<<std::endl;

    std::copy(vec.begin(),vec.begin()+num,std::ostream_iterator<int>(std::cout,"\t"));
    std::cout<<"\n";

    test_c_dupl();
    return 0;
}
