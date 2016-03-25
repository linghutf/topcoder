/**
 * 有重复出现的元素 全排列
 * 在bitmap中记录，如果已经选中则换下一个元素尝试
 * 条件:原来的元素需要有序
 */
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define NERVER_APPEAR (1<<31) //从未出现过的数字
const int STEPS = 4;//总共步数
std::bitset<STEPS> used;//是否使用
int solution[STEPS];//解空间

void backtrack(int nums[],int len,int step)
{
    if(step==STEPS){
        std::for_each(solution,solution+STEPS,[](int n){cout<<n<<'\t';});
        cout<<endl;
    }else{
        int last_element = NERVER_APPEAR;
        for(int i=0;i<len;++i){//对每个nums中元素进行尝试
            if(used[i]) continue;//该位置元素已被使用
            if(last_element == nums[i]) continue;//上一个位置已使用

            last_element = nums[i];
            used[i]=1;//标记使用
            solution[step]= nums[i];//这一步选择nums[i]
            backtrack(nums,len,step+1);//下一步
            used[i]=0;//退回
        }
    }
}

void testcase()
{
    int a[]={1,1,1,2};
    int len = sizeof(a)/sizeof(a[0]);
    backtrack(a,len,0);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
