#include <stdio.h>

int get_sec_max(int *a,int len)
{
    if(len<2)
    {
        return -1;
    }
    int first = a[0];
    int second = a[1];
    for(int i=1;i<len;++i)
    {
        if(a[i]>first)
        {
            second = first;
            first = a[i];
        }
        else if(a[i]>second)
        {
            second = a[i];
        }
    }
    return second;
}
