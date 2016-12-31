/**
 * 动态规划
 * 背包问题
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
    int n,m;
    std::cin>>n>>m;
    std::vector<int> values(m,0),hurts(m,0);
    for(int i=0;i<m;++i)
    {
        std::cin>>values[i]>>hurts[i];
    }

    std::vector<std::vector<int> > dp(n+1,std::vector<int>(m+1,0));
    int i,j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            // 大于消耗，舍弃
            if(values[j-1]>i)
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j] = std::max(dp[i][j-1],dp[i-values[j-1]][j-1]+hurts[j-1]);
            }
        }
    }

    std::cout<<dp[n][m]<<std::endl;

    return 0;
}
