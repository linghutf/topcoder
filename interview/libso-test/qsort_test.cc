#include <iostream>
#include <iomanip>

#include "qsort.hh"

using namespace std;

int main(int argc, char *argv[])
{
    int a[]={7,-1,4,3,5,2};
    int len = sizeof(a)/sizeof(a[0]);

    Qsort(a,len);

    for(int i=0;i<len;++i)
        cout<<setw(3)<<a[i];
    cout<<endl;
    return 0;
}
