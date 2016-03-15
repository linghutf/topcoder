#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

std::vector<int> Cost = {1,2,1,3,4,3,6,1,5,4};//每一个背包的代价
std::bitset<100 /*Cost.size()*/> State;//选择状态
std::vector<double> Benifit={1.5,2,1.2,2.7,4.2,3.3,9.0,1.5,7.0,6.0};//每一个背包的收益
const int UpCost = 8;//代价边界
const int UpNums = 5;//数量边界

static double totalbenifit = 0; //最大收益
static std::bitset<100> FinalState;//最大收益选择情况

double TotalBenifit()
{
    double sum = 0;
    for(int i=0;i<UpNums;++i){
        sum+=State[i]*Benifit[i];
    }
    return sum;
}

void printCost(std::bitset<100> &b)
{
    for(int i=0;i<Cost.size();++i)
        if(b[i]){
            cout<<Cost[i]<<'\t';
        }
    cout<<endl<<"Benifit:"<<TotalBenifit()<<endl;
}
//step 步数,不能超过规定的数量
void FindCollections(int step,int &cur_cost)
{
    if(cur_cost>UpCost) return;//没有找到解,返回
    if(cur_cost<=UpCost && step==UpNums){//满足条件,输出
        printCost(State);
        cout<<"Costs:"<<cur_cost<<endl;
        double b = TotalBenifit();
        if(b>totalbenifit){//当前最大收益
            FinalState.reset();
            totalbenifit = b;
            for(int i=0;i<Cost.size();++i){//保存
                FinalState[i]=State[i];
            }
        }
    }else{
        for(int i=0;i<Cost.size();++i){//对一个个背包尝试
            if(!State[i]){
                State[i] = 1;
                cur_cost += Cost[i];
                FindCollections(step+1,cur_cost);
                cur_cost -= Cost[i];
                State[i] = 0;
            }
        }
    }
}

void testcase()
{
    int costs=0;
    FindCollections(0,costs);
    //printCost(FinalState);
    cout<<"Max Benifit:"<<endl;
    for(int i=0;i<Cost.size();++i){
        if(FinalState[i])
            cout<<"id:"<<i<<"\tcost:"<<Cost[i]<<endl;
    }
    cout<<"Benifit:"<<totalbenifit<<endl;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
