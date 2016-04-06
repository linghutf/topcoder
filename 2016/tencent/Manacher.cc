#include <iostream>
#include <algorithm>
#include <string>

#include <iomanip>

using namespace std;

std::string LongestPalindromString(const std::string &s)
{
    if(s.empty()) return "";
    int n = s.length();
    n=(n<<1)+1;
    int L[n];
    L[0]=0;
    L[1]=1;
    int C = 1;//中心位置
    int R=2;//中心右边位置
    int i=0;//当前中心右端位置
    int iMirror;//当前中心左端位置
    int maxlen=0;
    int center_idx=0;//记录最长回文子串的中心位置
    int start = -1;
    //int end = -1;
    //int diff = -1;

    for(i=2;i<n;++i){
        //从比较中心右端位置得到左端位置(镜像对称)
        iMirror = 2*C-i;
        //如果i被包含在中心右端距离R中
        L[i]=(R>i)?std::min(L[iMirror],R-i):0;

        while(((i+L[i])<n && (i-L[i])>0) &&
                ((((i+L[i]+1)&0x1)==0) || s[(i+L[i]+1)>>1] == s[(i-L[i]-1)>>1])){//会超出边界,不用at
            ++L[i];
        }

        //记录最长回文串
        if(L[i]>maxlen){
            maxlen = L[i];
            center_idx = i;
        }

        if(i+L[i]>R){
            C=i;
            R=i+L[i];
        }
    }
    //debug info
    for(int i=1;i<=n;i+=2)
        cout<<setw(3)<<L[i];
    cout<<endl;

    start = (center_idx-maxlen)>>1;
    //end = start+maxlen-1;
    return s.substr(start,maxlen);
}

int main(int argc, char *argv[])
{
    string s(0,100);
    cin>>s;
    cout<<LongestPalindromString(s)<<endl;

    return 0;
}
