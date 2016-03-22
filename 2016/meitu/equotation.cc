/**
 * 多线程,并行处理6元一次方程
 * 计算 -15x1+28x2+45x3+5x4+17x5-39x6 = 0 的解的个数，
 * 其中xi∈[-100,0)U(0,100],i∈[1,6]
 *
 * 写文件时会有竞争条件，需要加锁，或者使用pwrite原子操作
 */

#include <iostream>
#include <algorithm>
#include <parallel/numeric>

#include <mutex>
#include <thread>
#include <vector>

#include <cstdio>

using namespace std;

//std::atomic<int> COUNT = 0;
//static int COUNT = 0;

const int k[]={-15,28,45,5,17,-39};
const int UP = 100;

static FILE *fp = fopen("result.dat","w");
std::mutex mtx;

bool isNotZero(int a[],int len)
{
    for(int i=0;i<len;++i)
        if(a[i]==0) return false;
    return true;
}

//x1,x6和x2-5不能异号?
//解应该是对称的
//减小搜索范围
bool isCond1(int a[],int len)
{
    return ((a[0]>0 &&a[5]>0&& a[1]<0 &&a[2]<0&&a[3]<0&&a[4]<0)||
            (a[0]<0 &&a[5]<0&&a[1]>0&&a[2]>0&&a[3]>0&&a[4]>0));
}

void write(int a[],int len)
{
    mtx.lock();
    fprintf(fp,"%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
    mtx.unlock();
}

void solve(int begin,int end,int &cnt)
{
    int a[6];
    int len = 6;
    for(a[0]=begin;a[0]<end;++a[0])
    for(a[1]=-UP;a[1]<=UP;++a[1])
    for(a[2]=-UP;a[2]<=UP;++a[2])
    for(a[3]=-UP;a[3]<=UP;++a[3])
    for(a[4]=-UP;a[4]<=UP;++a[4])
    for(a[5]=-UP;a[5]<=UP;++a[5])
    {
        if(!isNotZero(a,len)||isCond1(a,len)) continue;
        //int n = std::inner_product(k,k+len,a,0);
        //cout<<n<<endl;
        if(0==__gnu_parallel::inner_product(k,k+len,a,0)){
            //fwrite(a,sizeof(a[0]),len,fp);
            write(a,len);
            ++cnt;
        }
        //cout<<cnt<<endl;
    }
}

int main(int argc, char *argv[])
{
    /*
    int a[6];
    int len = 6;
    for(a[0]=-100;a[0]<=100;++a[0])
    for(a[1]=-100;a[1]<=100;++a[1])
    for(a[2]=-100;a[2]<=100;++a[2])
    for(a[3]=-100;a[3]<=100;++a[3])
    for(a[4]=-100;a[4]<=100;++a[4])
    for(a[5]=-100;a[5]<=100;++a[5])
    {
        if(isZero(a,len)||isCond1(a,len)) continue;
        if(0==std::transform(k,k+len,a,a+len,std::multiplies<int>())){
            //std::for_each(a,a+len,[](int n){cout<<n<<'\t';});
            //cout<<endl;
            ++COUNT;
        };
    }
    */
    std::vector<std::thread> ths;

    int result[201]={0};
    int j = 0;

    for(int i=-UP;i<=UP;++i){
        ths.push_back(std::thread(solve,i,i+1,std::ref(result[j])));
        ++j;
    }

    for(auto it=ths.begin();it!=ths.end();++it)
        it->join();

    int cnts = __gnu_parallel::accumulate(result,result+201,0);
    cout<<"total:"<<cnts<<endl;
    fclose(fp);
    return 0;
}
