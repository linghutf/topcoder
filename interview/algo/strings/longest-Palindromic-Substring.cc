#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//预处理，将abba转换成$#a#b#b#a#\0
char *pre(char *s)
{
    int len = strlen(s);
    char *prestr = new char[2*len+4];
    prestr[1]='$';
    for(int i=0;i<len;++i)
    {
        prestr[(i+1)<<1] = '#';
        prestr[(i+1)<<1+1] = s[i];
    }
    prestr[len<<1+2] = '#';
    prestr[len<<1+3] = '\0';
    return prestr;
}

int LognestPalindrom(char *s)
{
    char *prestr = pre(s);
    int mx = 0, pi = 1;//边界和对称中心
    int len = strlen(prestr);
    int *suffix = new int[len];//辅助数组
    suffix[0]=0;
    for(int i=1;i<len;++i){
        if(mx>i){
            suffix[i] = std::min(mx-i,suffix[2*pi-i]);
        }else{
            suffix[i]=1;
        }
        while(prestr[i-suffix[i]]==prestr[i+suffix[i]] && (i-suffix[i])>0 && (i+suffix[i])<len){
            ++suffix[i];
        }
        if((i+suffix[i])>mx){
            mx = suffix[i]+i;
            pi = i;
        }
    }

    //回文长度
    int maxlen = 0;
    for(int i=0;i<len;++i){
        if(suffix[i]>maxlen){
            maxlen = suffix[i];
        }
    }
    //delete []prestr;
    //delete []suffix;
    return maxlen-1;
}

void testcase()
{
    char s[][20]={
        "forgeeksskeegfor",
        "abaaba",
        "abababa",
        "abcbabcbabcba"
    };
    int len=4;
    for(int i=0;i<len;++i){
        cout<<LognestPalindrom(s[i])<<endl;
    }
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
