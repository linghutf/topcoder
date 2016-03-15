#include <iostream>
#include <algorithm>

#include <bitset>

using namespace std;

std::bitset<10> state;

void permutation(int nums[],int a[],int len,int step)
{
    if(a==NULL||len<=0)
        return;
    if(step==len){//到达边界
        std::for_each(a,a+len,[](int n){cout<<n<<'\t';});
        cout<<endl;
    }else{
        for(int i=0;i<len;++i){//对每一个元素执行操作
            if(!state[i]){//i没有使用
                state[i]=1;//已经使用i值
                a[step]=nums[i];//这一步使用了i
                permutation(nums,a,len,step+1);//处理下一个位置
                state[i]=0;//i恢复未使用状态
            }
        }
    }
}

void testcase()
{
    int nums[]={1,5,2};
    int len = sizeof(nums)/sizeof(nums[0]);
    state.reset();
    int *a = new int[len];//存放结果

    permutation(nums,a,len,0);//从0位置开始
    delete a;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
