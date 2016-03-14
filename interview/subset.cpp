/**
 * 子集生成算法
 * 将每一位的状态，用回溯法生成一个符合边界的序列，
 * 根据序列的状态来决定是否选择该元素选中
 * 2^26-1个非空子集
 */
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>

#include <cstdio>

using namespace std;

const int STEPS = 26+'a';
const int N = 128;
static int COUNT = 0;

std::bitset<N> state;

void PrintSet()
{
    cout<<'(';
    for(int i=0;i<N;++i)
        if(state[i]==1){
            //cout<<(char)i<<',';
            printf("%2c",i);
        }
    cout<<')'<<endl;
    ++COUNT;
}
//测试static 函数不在bss段
/*static*/ void dfs(char c_step)
{

    if(c_step==STEPS){
        PrintSet();
    }else{
        for(int j=0;j<=1;++j){
            state.set(c_step,j);
            dfs(c_step+1);
            //state.set(c_step,j);
        }
    }
}

void DfsNotReccursive(char c)
{
    std::stack<char> s;
    char i;
    s.push(c);
    while(!s.empty()){
        i=s.top();
        if(!state[i]){
            state.set(i);
            for(char j=i+1;j<=STEPS;++j)
                s.push(j);
        }else{
            s.pop();
        }
    }

}
int main(int argc, char *argv[])
{
    //state.reset();
    //dfs('a');
    DfsNotReccursive('a');
    //printf("totals:%d\n",COUNT);
    return 0;
}

