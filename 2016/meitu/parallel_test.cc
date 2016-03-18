#include <iostream>
#include <parallel/numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int k[2]={1,2};
    int len = 2;
    cout<<__gnu_parallel::inner_product(k,k+len,k,0)<<endl;
    return 0;
}
