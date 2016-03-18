#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int>> Arrays;

std::tuple<int,int> search(int key,const Arrays &a)
{
    auto t = std::make_tuple(-1,-1);
    if(a.empty()||a.front().empty())
        return t;

    int i=0,j=a.front().size()-1;
    while(i<a.size()&&j>=0){
        if(a[i][j]==key){
            std::get<0>(t) = i;
            std::get<1>(t) = j;
            break;
        }else if(a[i][j]>key){
            j--;
        }else{
            i++;
        }
    }
    return t;
}
int main(int argc, char const *argv[])
{
    Arrays a = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };
    int key = atoi(argv[1]);

    auto pos = search(key,a);
    cout<<std::get<0>(pos)<<","<<std::get<1>(pos)<<endl;
    return 0;
}
