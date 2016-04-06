#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool test(string &s,string &t)
{
    if(s.empty()&&t.empty()) return true;
    if(s.empty()||t.empty()) return false;
    int ump[200]={0};
    for(auto it=s.begin();it!=s.end();++it)
        ump[*it]++;

    for(auto it=t.begin();it!=t.end();++it)
        ump[*it]--;
    for(int i=0;i<200;++i)
        if(ump[i]) return false;
    return true;
}

int main(int argc, char *argv[])
{
    unordered_map<char,int> ump;
    char s[]="";
    char t[]="";
    ump[s[0]]++;
    ump[t[0]]--;
    for(auto it=ump.begin();it!=ump.end();++it){
        cout<<it->first<<"->"<<it->second<<endl;
    }
    return 0;
}
