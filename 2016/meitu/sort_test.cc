/**
 * 测试STL函数的鲁棒性
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int a[]={-3,1,2};
    std::sort(a,a-1);
    std::for_each(a,a+3,[](int n){cout<<n<<'\t';});
    cout<<endl;
    return 0;
}
