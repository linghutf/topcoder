#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int NUM = 10;
std::bitset<256> bitmap;

int used[5][10]={0};

const char Hash[][10]={
    "123567",
    "36",
    "13457",
    "13467",
    "2346",
    "12467",
    "124567",
    "136",
    "1234567",
    "123467"
};

void GetNumber(char *s,char *t)
{
    int len = strlen(s);
    int i,j=0;
    for(i=0;i<len;++i)
        if(isdigit(s[i])) t[j++]=s[i];
    t[j]='\0';
}

bool IsIn(const char *src,const char *t)
{
    for(int i=0;i<strlen(src);++i)
        bitmap.set(src[i]);

    for(int i=0;i<strlen(t);++i)
        if(bitmap[t[i]]==0) return false;
    return true;
}

void PossibleNumbers(vector<string> &vec,vector<string>& result)
{
    for(auto it = std::begin(vec);it!=std::end(vec);++it)
    {
        char nums[20];
        int cnt = 0;
        for(int i=0;i<NUM;++i)
        {
            if(IsIn(Hash[i],it->c_str())){
                //result.push_back(i);//add to possible number
                nums[cnt++] = '0'+i;
            }
        }
        nums[cnt]='\0';
        result.push_back(string(nums));
    }
}

int Possible(vector<string> &v,int step,string &numbers)
{
    if(step==v.size()){
        numbers[step]='\t';
        return atoi(numbers.c_str());
    }else{
        string s = v[size];
        for(int i=0;i<s.size();++i){
            used[step][i]=1;
            numbers[step]=s.at(i);
            Possible(v,step+1,numbers);
            used[step][i]=0;
        }
    }
}

void LessThanN(,int n)
{
    string number;
    int num;
    for(num = Possible(v,0,number);
}
int main(int argc, char *argv[])
{
    vector<string> vec,result;
    unsigned int s;
    cin>>s;
    if(s>100) return -1;

    //input
    //std::bitset<256> bit;
    int i,j,k;
    unsigned int n;
    int len;
    char buf[200],buf2[100];
    for(i=0;i<s;++i){
        cin>>j>>n;
        if(j<1||j>5||n>1000000000) return -1;
        for(k=0;k<j;++k){
            fgets(buf,200,stdin);
            len = strlen(buf);
            buf[len-1]='\0';
            //get number
            GetNumber(buf,buf2);
            //add
            vec.push_back(string(buf2));
        }
        //handle
        PossibleNumbers(vec,result);
        Possible(result,n);
        //clear
        vec.clear();
        result.clear();
    }
    GetInput(vec);
    return 0;
}
