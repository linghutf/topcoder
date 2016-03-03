#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

typedef std::vector<int> Container;

//填充随机数据
void fillNumber(Container &c,int n)
{
    srand(time(NULL));
    for(int i=0;i<n;++i)
        c.push_back(rand()%INT_MAX);
}

void findMaxN(Container &dst,Container &c,int n,bool isMax=true)
{
    time_t start,end;
    time(&start);

    auto func = [](auto a,auto b){return a>b;};
//make_heap默认建的是大顶堆
    if(isMax){
        //大顶堆
        std::make_heap(c.begin(),c.end());
    }else{
        //小顶堆
        std::make_heap(c.begin(),c.end(),func);
    }
    for(int i=0;i<n;++i){
        std::pop_heap(c.begin(),c.end());
        dst.push_back(c.back());
        c.pop_back();

        //小顶堆每次都需要维持堆结构,更耗费时间
        if(!isMax){
            std::make_heap(c.begin(),c.end(),func);
        }
    }
    time(&end);
    cout<<"time elapsed:"<<end-start<<endl;
}

int main(int argc, char *argv[])
{
    if(argc<4){
        cout<<"usage:"<<argv[0]<<"max|min(y/n) number-stage search-numbers."<<endl;
        return -1;
    }
    int n = atoi(argv[2]);
    int findn = atoi(argv[3]);
    bool isMax = argv[1][0]=='y';
//const assert
//    static_assert(isMax==true,"parameter error.");

    if(isMax)
        cout<<"Max Heap."<<endl;
    else
        cout<<"Min Heap."<<endl;
    Container c,result;
    fillNumber(c,n);
    findMaxN(result,c,findn,isMax);

    //按照出堆顺序打印
    std::for_each(result.begin(),result.end(),[](auto i){cout<<i<<endl;});

    return 0;
}
