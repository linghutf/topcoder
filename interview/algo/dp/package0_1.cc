/**
 * 0-1背包，使得能被背包容纳情况下价值最大
 */

#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int> > Matrix;

void InitMatrix(Matrix &mat,int num,int limits);
//计算矩阵
void dfs(Matrix &mat,std::vector<int>& cost,std::vector<int>& value,int limits);
//从矩阵中获取结果
void GetAnsWer(Matrix &mat,std::vector<int> idxs);

int main(int argc, char *argv[])
{

    return 0;
}

void InitMatrix(Matrix &mat,int num,int limits)
{

}

void dfs(Matrix &mat,std::vector<int>& cost,std::vector<int>& value,int limits)
{
    int i,j;
    int n = cost.size();
    for(j=0;j<=limits;++j){
        mat[n][j]=j<cost[n]?0:value[n];
    }


}

void GetAnsWer(Matrix &mat,std::vector<int> idxs)
{
}
