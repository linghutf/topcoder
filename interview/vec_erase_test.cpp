#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v = {1,2,3,5,7};
    auto it = v.end()-1;
    //auto iter = v.()-2;
    while(v.size()>1){
        it = v.end()-1;
        for(auto iter = v.end()-2;iter!=v.begin()-1;--iter)
            if(*iter!=*it){
                v.erase(it);
                v.erase(iter);
                break;
            }
    }
    for_each(v.begin(),v.end(),[](auto i){cout<<i<<"\t";});
    cout<<endl;
    return 0;
}
