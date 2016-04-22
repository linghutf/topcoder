#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef unordered_map<int,int> Result;

const static int P = 6;

void dfs(int step,int n,int sum,Result& r)
{
    if(step==n){
        r[sum]++;
    }else{
        for(int i=1;i<=P;++i){
            dfs(step+1,n,sum+i,r);
        }
    }
}

void PrintResult(Result &r)
{
    for(auto it=r.begin();it!=r.end();++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
}

int main()
{
    Result r;
    int n = 3;
    dfs(0,n,0,r);
    PrintResult(r);

    return 0;
}
