/**
 * 投石子游戏递归算法
 * 未通过
 */
#include <iostream>
#include <algorithm>

using namespace std;

int f(int n){
    if(n<=6){
        switch(n){
            case 6:return f(5)+f(3)+1;
            case 5:return f(2)+f(4)+1;
            case 4:return f(3)+f(1)+1;
            case 3:return f(2)+1;
            case 2:
            case 1:
                   return n;
        }
    }
    int n1=f(n-6);
    int n2=f(n-3);
    int n3=f(n-1);
    return n1+n2+n3+1;
}

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}
