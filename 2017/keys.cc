#include <iostream>
#include <algorithm>

static const int ROW = 3,COL=3;

bool is_ok(char a[][COL])
{
    int i,j;
    bool ret = true;
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            if(i==ROW/2 && j==COL/2) return ret;
            if(i==ROW/2)//同一行
            {
                ret = a[i][j]==a[i][COL-1-j];
            }
            else if(j==COL/2)//同一列
            {
                ret = a[i][j]==a[ROW-1-i][j];
            }
            else//轴对称
            {
                ret = a[i][j]==a[ROW-1-i][COL-1-j];
            }
            if(!ret) return ret;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int i,j;
    char a[ROW][COL];
    while(true)
    {
        for(i=0;i<ROW;++i)
        {
            for(j=0;j<COL;++j)
            {
                std::cin>>a[i][j];
            }
        }
        if(is_ok(a))
        {
            std::cout<<"YES\n";
        }
        else
        {
            std::cout<<"NO\n";
        }
    }
    return 0;
}
