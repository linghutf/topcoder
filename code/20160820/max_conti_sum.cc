/**
 * 最大连续和
 */

#include <iostream>
#include <limits.h>

static bool g_error = false;

int sum(const int * a,size_t len)
{
    if(a==NULL||len==0)
    {
        g_error = true;
        return -1;
    }
    int s = 0;
    int max_s = INT_MIN;
    for(int i=0;i<len;++i)
    {
        if(s<=0)
        {
            s = a[i];
        }
        else
        {
            s+=a[i];
        }
        if(s>max_s)
        {
            max_s = s;
        }
    }
    return max_s;
}

void test_case()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    int len = sizeof(a)/sizeof(a[0]);
    int s = sum(a,len);
    if(!g_error)
    {
        std::cout<<s<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    test_case();

    return 0;
}
