#include <iostream>
#include <algorithm>

using namespace std;

void permutation(int a[],int len,int begin,int end)
{
    if(a==NULL||len<=0||begin>end)
        return;
    if((end-begin)==1){//到达边界
        std::for_each(a,a+len,[](int n){cout<<n<<'\t';});
        cout<<endl;
    }else{
        for(int *p=a+begin;p!=a+end;++p){
            //        if(*p!=*(a+begin))
            std::swap(*p,*(a+begin));//交换位置
            permutation(a,len,begin+1,end);//处理下一个位置
            //        if(*p!=*(a+begin))
            //std::swap(*p,*(a+begin));//返回(复原)
        }
        /*permutation(a,len,0,len-1);
        std::reverse(a,a+end-1);
        std::reverse(a+end-1,a+end);
        std::reverse(a,a+end);
        */
    }
}

void testcase()
{
    int a[]={1,5,1};
    int len = sizeof(a)/sizeof(a[0]);
    permutation(a,len,0,len);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
