#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution{
    public:
        string preProcess(string &s){
            if(s.empty()) return "^$";
            int n = s.length();
            string ret = "^";
            for(int i=0;i<n;++i){
                ret += "#"+s.substr(i,1);
            }
            ret += "#$";
            return ret;
        }

        string longestPalindrome(string& s){
            string t = preProcess(s);
            cout<<t<<endl;
            const int n = t.length();
            //以t[i]为中心,向左/右扩张的长度,不包括t[i]
            //p[i]是源字符串中回文串的长度
            int p[n]={0};
            p[0]=0;
            p[1]=1;
            int c=1,r=2;
            int maxlen=0;
            int centeridx=0;
            //#...#
            for(int i=1;i<n-1;++i){
                int i_mirror = 2*c-i;//equal to i' = c -(i-c);
                p[i]=(r>i)?min(r-i,p[i_mirror]):0;
                //以i为中心扩展回文
                while(t[i+1+p[i]] == t[i-1-p[i]])
                    p[i]++;

                //找到最大的回文长度
                if(p[i]>maxlen){
                    maxlen = p[i];
                    centeridx = i;
                }

                if(i+p[i]>r){
                    c=i;
                    r=i+p[i];
                }
            }

            return s.substr((centeridx-1-maxlen)>>1,maxlen);
        }
};

void testcase()
{
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.longestPalindrome(s)<<endl;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
