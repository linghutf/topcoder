#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100000

int gcd(int a,int b)
{

    while(b!=0){
        a=a%b;
        swap(a,b);
        //std::swap(a%b,b);
    }
    return a;
}

int add(int val,int a[],int len)
{
    for(int i=0;i<len;++i){
        if(a[i]<=val) val+=a[i];
        else
            val += gcd(val,a[i]);
    }
    return val;
}

int main(int argc, char *argv[])
{
    int a[MAXN];
    int n,val = 0;
    //while(true){
    cin>>n>>val;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<add(val,a,n)<<endl;
    //}
    return 0;
}
