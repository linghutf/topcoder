#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

template<typename T> bool check(T &t)
{
    //return std::floor(t)==t && std::ceil(t)==t;
    return t==*(int*)&t;//0的表示相同
}

int main(int argc, char *argv[])
{
    float f=12.0;
    double d = 12.0;
    int a = 0;
 //   cout<<*(int*)&f<<','<<*(int*)&d<<endl;
    cout<<check(f)<<','<<check(d)<<','<<check(a)<<endl;
    printf("%f,%lf,%f\n",f,d,a);
    return 0;
}
