/**
 *
 * 在有序数组中查找3个数的和为k : A+B+C = k
 * 基础题:
 *    在有序数组中查找2个数的和为k : A+B = k
 *
 *    分别指向头指针和尾指针，向中间汇聚
 *
 * 变通:
 *     A+B = k-C,两个循环即可
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int len =10;

    int i,j,k;

    for(i=0;i<len;++i){
        a[i] = i+1;
    }

    int K = 10;
    int sum = 0;
    for(i=0;i<len;++i){//a[i]=C
        j = i+1;
        k = len-1;
        while(j<k){
            sum = a[i]+a[j]+a[k];
            if(sum<K){
                ++j;
            }else if(sum>K){
                --k;
            }else{
                printf("%4d%4d%4d\n",a[i],a[j],a[k]);
                ++j;//测试下一个位置
                --k;
            }
        }
    }

    return 0;
}
