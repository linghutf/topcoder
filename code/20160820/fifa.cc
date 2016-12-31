#include <iostream>
#include <algorithm>

void dfs(int n,int & count)
{
    if(n==0)
    {
        ++count;
    }
    else
    {
        if(n>=1)
            dfs(n-1,count);
        if(n>=2)
            dfs(n-2,count);
        if(n>=3)
            dfs(n-3,count);
    }
}

int main(int argc, char *argv[])
{
    int n;
    std::cin>>n;
    int cnt = 0;
    dfs(n,cnt);
    std::cout<<cnt<<std::endl;
    return 0;
}
