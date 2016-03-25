/**
 * 使用set来排除重复的元素
 */
#include <iostream>
#include <algorithm>

#include <unordered_set>

#include <cstring>

using namespace std;

void backtrack(char *str,int len,int step,int stop)
{
    if(step==stop){
        cout<<str<<endl;
    }else{
        unordered_set<char> s;
        for(int i=step;i<len;++i){
            if(s.find(str[i])!=s.end()) continue;//已存在
            s.insert(str[i]);//插入
            swap(str[i],str[len-1]);
            backtrack(str,len,step+1,stop);
            swap(str[i],str[len-1]);
        }
    }
}

int main(int argc, char *argv[])
{
    char s[]="1112";
    int len = strlen(s);
    int stop = len;
    backtrack(s,len,0,stop);
    return 0;
}
