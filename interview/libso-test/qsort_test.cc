#include <iostream>
#include <iomanip>

#include "qsort.hh"

#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    int a[]={19,15,12,18,21,36,45,10};
    int len = sizeof(a)/sizeof(a[0]);

    Qsort(a,len);

    for(int i=0;i<len;++i)
        cout<<setw(3)<<a[i];
    cout<<endl;
    sleep(100);
    return 0;
}
