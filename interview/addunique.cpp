/**
 * 每次只能加入一个数，且这个数是
 * 已在序列中两两之差的不同值
 * 参见unique.py
 * 最多n/min(n-m,m)个元素
 */
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

#include <cstdlib>

using namespace std;

void values(unordered_set<int> &s,int a,int b)
{
    s.insert(a);
    s.insert(b);
    if(s.size()==1) return;
    int n;
    std::vector<int> src,dst;
    std::vector<int>::iterator iti,itj;
    std::unordered_set<int> v;
    size_t lastsz=0;
    while(true){
        copy(s.begin(),s.end(),std::back_inserter(src));

        for(iti=src.begin();iti!=src.end();++iti){
            for(itj=src.begin();itj!=src.end();++itj){
                n = *iti-*itj;
                if(n>0)
                    v.insert(n);
            }
        }
        /*
        cout<<"差值[原始]:";
        std::for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
        cout<<endl;
        */
        src.clear();
        copy(v.begin(),v.end(),std::back_inserter(dst));
        copy(s.begin(),s.end(),std::back_inserter(src));

        std::sort(dst.begin(),dst.end());
        std::sort(src.begin(),src.end());
        //unordered_set difference
        std::vector<int> tmp(a/(a-b)+1);
        iti = std::set_difference(dst.begin(),dst.end(),src.begin(),src.end(),tmp.begin());
        tmp.resize(iti-tmp.begin());
        /*
        cout<<"差值:";
        std::for_each(tmp.begin(),tmp.end(),[](int n){cout<<n<<'\t';});
        cout<<endl;
        */
        if(tmp.empty()) break;
        s.insert(*tmp.begin());
        if(s.size()==lastsz) break;
        lastsz = s.size();

        //std::for_each(v.begin(),v.end(),[&s](int n){cout<<n<<'\t';s.insert(n);});
        v.clear();
        src.clear();
        dst.clear();
    }
}

int main(int argc, char *argv[])
{
    std::unordered_set<int> v;
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    if(a<b)
        swap(a,b);
    values(v,a,b);

    std::for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
    cout<<endl;

    return 0;
}
