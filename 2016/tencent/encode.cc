/**
 * 10进制转化成36进制[0-9a-z]
 */

#include <iostream>
#include <string>
//#include <typeinfo>
#include <algorithm>

using namespace std;

const std::string CODE="0123456789abcdefghijklmnopqrstuvwxyz";

int binsearch(std::string &s,char c)
{
    //int idx = -1;
    int low = 0,high=s.length()-1;
    int mid;
    char t;
    while(low<=high){
        mid=(low+high)>>1;
        t = s.at(mid);
        if(t==c) return mid;
        else if(t<c) low=mid+1;
        else high = mid-1;
    }
    return -1;
}

std::string DecTo36Base(int n,int base)
{
    std::string s;
    while(n%base){
        s.push_back(CODE.at(n%base));
        n/=base;
    }
    std::reverse(s.begin(),s.end());
    return s;
}

int BaseToDec(std::string &s,int base)
{
    int n=0;
    int idx=-1,flag;
    string pre = CODE.substr(0,10);
    string post = CODE.substr(10,27);
    for(std::string::iterator it=s.begin();it!=s.end();++it){
        //auto iter = std::find(CODE.begin(),CODE.end(),*it);
        //cout<<typeid(iter).name()<<endl;
        flag=0;
        if(*it<='9'){
            idx = binsearch(pre,*it);
        }else{
            idx = binsearch(post,*it);
            flag=1;
        }
        if(idx==-1) break;
        n=base*n+idx+flag*10;
    }
    return n;
}

void testcase()
{
    int nums = 4;
    std::string ss[]={"iphone","imac","ipad","ipod"};
    int n;
    for(int i=0;i<nums;++i){
        n=BaseToDec(ss[i],36);
        cout<<ss[i]<<":"<<DecTo36Base(n,36)<<'\t'<<n<<endl;
    }
}

int main(int argc, char *argv[])
{
    testcase();
    //int n = 873085;
    int n,base=36;
    cin>>n;
    cout<<DecTo36Base(n,base)<<endl;;
    return 0;
}
