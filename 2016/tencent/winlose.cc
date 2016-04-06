/**
 * 16颗石子,每次取1,3,或6,最后取走的为赢，
 * 分析先手的胜率
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100 //最多步数
#define MAXC 3 //最多选择

typedef std::vector<int> Steps;//记录下棋步数

typedef std::vector<std::vector<int> > Record;//记录取的石子

const std::vector<int> Choice ={1,3,6};//取法

bool used[MAXN][MAXC]={false};

void backtrack(Record &r,Steps& record,Steps& st,int step,int& cnt)
{
    if(step<0){
        return;//不符合
    }
    if(step==0){//刚好取完
        st.push_back(cnt);//记录多少步到达终点
        r.push_back(record);
    }else{
        int i,len=Choice.size();
        for(i=0;i<len;++i){
            if(!used[step][i]){
                used[step][i]=true;
                cnt++;
                record.push_back(Choice.at(i));//记录取走的数目
                backtrack(r,record,st,step-Choice.at(i),cnt);
                cnt--;
                used[step][i]=false;
                record.pop_back();
            }
        }
    }
}

void Print(Record &r,Steps &st)
{
    int odd=0;
    int i=0;
    for(auto it=st.begin();it!=st.end();++it){
        cout<<setw(4)<<*it<<'\t';
        //每种步数的详细情况
        for(auto iter=r.at(i).begin();iter!=r.at(i).end();++iter){
            cout<<setw(3)<<*iter;
        }
        i++;
        if((*it)&0x1) odd++;
        cout<<endl;
    }
    cout<<endl<<"result:"<<odd*1.0/st.size()<<endl;
}

int main(int argc, char *argv[])
{
    Record r;
    Steps st,record;
    int n = 16;
    int cnt = 0;

    backtrack(r,record,st,n,cnt);
    Print(r,st);

    return 0;
}
