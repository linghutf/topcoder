/**
 * 从给定数字集合中选取数字组成一个整数
 * 整数的每一位都是从相应集合中选取
 *
 * 参考网易笔试题:电子数字的可能组合
 */
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;


std::vector<vector<int>> collections={
    {2,4,6},
    {1,3,5},
    {0}
};

int used[3][10];

int n[100];
int STEP = 3;

void backtrack(int step)
{
    if(step==STEP){
        for_each(n,n+STEP,[](int n){cout<<n;});
        cout<<endl;
    }else{
        vector<int>::iterator iter = collections[step].begin();
        for(;iter!=collections[step].end();++iter)
        {
            if(!used[step][*iter]){
                used[step][*iter]=1;//标记被使用
                n[step]=*iter;
                backtrack(step+1);
                used[step][*iter]=0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    backtrack(0);
    return 0;
}
