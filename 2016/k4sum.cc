/*
 * k4sum.cc
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "k4sum.h"
 */

#include <iostream>
// #include <string>
#include <cstdio>
#include <algorithm>
// #include <vector>
// #include <memory>
// #include <thread>
//#include <unordered_set>

using namespace std;

//typedef std::unordered_set<int> Set;

void dfs(int a[],bool used[],int len,int step,int psum);
int sumOfArray(int a[],bool used[],int len);
void print(int a[],bool used[],int len);

int main(int argc,char const *argv[])
{
    int a[]={1,3,4,2,6,7,5,5,8,10,9,10,7,17};
    const int len = sizeof(a)/sizeof(a[0]);
    bool used[len]={false};
    sort(a,a+len);
    //int i,j,m,n;
    //int k = 4;

    int sum = 29;
    /*cin>>sum;
    for(i=0;i<len-k;++i){
        for(j=i+1;j<len-k+1;++j){
            m = j+1;
            n = len-1-j-1;
            while(m<n){
                int sm = a[i]+a[j]+a[m]+a[n];
                if(sm==sum){
                    printf("%2d,%2d,%2d,%2d\n",a[i],a[j],a[m],a[n]);
                    m++;
                    n--;
                }else if(sm<sum){
                    m++;
                }else{
                    n--;
                }
            }
        }
    }*/

    dfs(a,used,len,0,sum);

    return 0;
}

void dfs(int a[],bool used[],int len,int step,int psum){
    if(step==len){
        if(psum==sumOfArray(a,used,len)){
            print(a,used,len);
        }
    }else{
        if(psum==sumOfArray(a,used,len)){
            print(a,used,len);
        }else{
            for(int i=0;i<len;++i){
                if(!used[i]){

                    used[i]=true;
                    dfs(a,used,len,step+1,psum);
                    used[i]=false;
                }
            }
        }
    }
}

int sumOfArray(int a[],bool used[],int len)
{
    int s = 0;
    for(int i=0;i<len;++i){
        if(used[i]) s+=a[i];
    }
    return s;
}

void print(int a[],bool used[],int len)
{
    for(int i=0;i<len;++i){
        if(used[i]) printf("%3d",a[i]);
    }
    cout<<endl;
}
