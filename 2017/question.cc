/**
 * 求出最大最小值的差，然后按照10插入数字
 * 保证在三个连续位置，两两之间距离不超过10
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 100
static int QS[MAXN];

const int DIS = 10;
/*
int num_of_compsite(int n)
{
    if(n<=0) return 0;
    return n/3+(n%3?1:0);
}
*/
int least_num(int n)
{
    if(n<=0) return 0;
    if(n<3) return 3-n;
    int i;
    int cnt=0,a,b;
    for(i=0;i<n/3;i+=3)
    {
        a = QS[i+1]-QS[i];
        b = QS[i+2]-QS[i+1];
        if(a>=DIS)
        {
            cnt+=a/DIS;
        }
        if(b>=DIS)
        {
            cnt+=b/DIS;
        }
    }

    return cnt+(n%3?1:0);
}

int main(int argc, char *argv[])
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        std::cin>>QS[i];
    }

    // 先排序
    std::sort(QS,QS+n);

    std::cout<<least_num(n)<<std::endl;
    return 0;
}
