#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool replace(string &s,char c,const string &rep)
{
    if(s.empty()||rep.empty())
        return false;

    for(int i=s.size()-1;i>=0;--i){
        if(s[i]==c){
            //s[i]=rep[0];
            //s.insert(s.begin()+i,rep.begin()+1,rep.end());
            //or
            s.replace(s.begin()+i,s.begin()+i+1,rep);
        }
    }
    return true;
}

void testcase1()
{
    //开头结尾多个空格
    string s = " I  have a question. ";
    string rep="%20";
    char c = ' ';
    cout<<"原始:"<<s<<endl;
    if(replace(s,c,rep))
        cout<<"修改:"<<s<<endl;
}
void testcase2()
{
    //没有空格
    string s = "Ihaveaquestion.";
    string rep="%20";
    char c = ' ';
    cout<<"原始:"<<s<<endl;
    if(replace(s,c,rep))
        cout<<"修改:"<<s<<endl;
}

void testcase3()
{
    //字符串只有空格
    string s = "  ";
    string rep="%20";
    char c = ' ';
    cout<<"原始:"<<s<<endl;
    if(replace(s,c,rep))
        cout<<"修改:"<<s<<endl;
}

int main(int argc, char *argv[])
{
    testcase1();
    testcase2();
    testcase3();
    return 0;
}
