/**
 * 求[l,r]内交错和f(n)=k的n的和
 * x=abc...z
 * f(x)=a-b+c..+(-1)^(n-1)z
 *
 * input: l,r,k 0<=l<=r<=10^18,k<=100
 * output: sum=realsum%10^9+7
 *
 * dynamic programming
 */
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool g_error = false;

int f(const string &s)
{
    int flag = 1;
    int num = 0;
    if(s.empty()) return 0;
    for(std::string::const_iterator it=s.begin();it!=s.end();++it){
        if(std::isdigit(*it)){
            num+=flag*(*it-'0');
        }else{
            g_error = true;
            break;
        }
        flag=-flag;
    }
    return num;
}

void testcase()
{
    string s;
    cin>>s;
    cout<<f(s)<<endl;
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
