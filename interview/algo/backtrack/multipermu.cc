/**
 * 一个尾有多个选择的全排列
 *
 * 解决方案:
 * 1.使用set过滤重复的结果，占用空间大大
 * 2.边界增长一倍,选取奇数位的值组成可行解,缺点时间复杂度太高
 * 3.使用多维数组保存选取状态
 */

#include <iostream>
#include <algorithm>

using namespace std;

const char SIGN[] ="9g";//每个位置的可能选择
const int OPT = 2;
const int LEN = 3;
bool used[LEN][OPT]={false};

void backtrack(char *str,int step)
{
    if(step==LEN){
        cout<<str<<endl;
    }else{
        bool *p = used[step];
        bool *i = p;
        for(;i<p+OPT;++i){//每一步对应的可选择元素
            if(*i) continue;//使用过
            *i = true;
            str[step]=SIGN[i-p];//对应位置元素
            backtrack(str,step+1);
            *i = false;
        }
    }
}

int main(int argc, char *argv[])
{
    char str[LEN+1];
    str[LEN]='\0';
    backtrack(str,0);
    return 0;
}
//使用字典序方法，可以使用方案2
/*
void permutation(char *str)
{
    int len = strlen(str);
    char *newstr = new char[len<<1+1];
    strncpy(newstr,str,len);//复制两倍
    strncpy(newstr+len,str,len);
    //使其有序
    len<<=1;
    sort(newstr,newstr+len);
    do{
        //打印奇数位
        for(int i=0;i<len;i+=2)
            cout<<newstr[i];
        cout<<endl;
    }while(std::next_permutation(newstr,newstr+len));//不行，位置会改变,本来只能在0位的跑到了1位置参与全排
}*/
