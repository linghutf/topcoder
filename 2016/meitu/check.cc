#include <iostream>
#include <parallel/numeric>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc<7){
        return -1;
    }
    int a[6];
    int k[6]={-15,28,45,5,17,-39};
    int len =6;
    for(int i=1;i<7;++i)
        a[i-1] = atoi(argv[i]);
    cout<<__gnu_parallel::inner_product(k,k+len,a,0)<<endl;
    return 0;
}
