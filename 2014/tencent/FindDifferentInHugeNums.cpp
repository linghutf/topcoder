#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])
{
    int a[]={1,2,2,2,2};
    int r=a[0];
    for(int i=1;i<5;++i)
        r^=a[i];
    cout<<r<<endl;
    return 0;
}
