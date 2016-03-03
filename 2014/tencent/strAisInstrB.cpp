#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * s: main str
 * t: sub test str
 */
bool isIn(const string &s,const string &t,bool casessenstivie=true)
{
    //string a(s),b(t);
    //std::sort(a.begin(),a.end());
    //std::sort(b.begin(),b.end());
    unordered_set<char> set;
    size_t len = 0;
    std::for_each(s.begin(),s.end(),[&set,casessenstivie](char c){
            if(!casessenstivie) c= toupper(c);
            set.insert(c);});
    std::for_each(set.begin(),set.end(),[](char c){cout<<c;});
    cout<<endl;
    len = set.size();
    std::for_each(t.begin(),t.end(),[&set,casessenstivie](char c){
            if(!casessenstivie) c=toupper(c);
            set.insert(c);});
    std::for_each(set.begin(),set.end(),[](char c){cout<<c;});
    cout<<endl;
    return len == set.size();
}

int main(int argc, char *argv[])
{
    if(argc<4){
        cerr<<"usage:"<<argv[0]<<"casessenstivie(y|n) test-str main-str.\n";
        return -1;
    }
    bool casessenstivie = (argv[1][0]=='y');
    string t = argv[2];
    string m = argv[3];;
    if(isIn(m,t,casessenstivie))
        cout<<"test isIn main."<<endl;
    else
        cout<<"test Not In main."<<endl;
    return 0;
}
