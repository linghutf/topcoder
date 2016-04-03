/**
 * 连续和最大的序列
 */
#include <iostream>
#include <algorithm>

using namespace std;

void maxsub(int a[],int len,int &start,int &end)
{
    start = 0;
    end = 1;
    int sum = 0,presum = 0;
    if(a==NULL||len<=1) return;
    //如果sum在增长,end+1
    //如果sum在减少,start+1
    //如果sum
    while(end<=len&&start<end){

    }
}
