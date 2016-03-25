/**
 *
 * 网易2016在线笔试编程题1
 * 代金券9和g混淆，将出现的所有可能输出
 *
 * 时间限制；1s,内存限制:32m
 *
 * 当时使用回溯，因为每个位置有9和g可选，结果有重复，
 * 用了集合set去重
 *
 * 状态变量,记录位置变量,每个结果复制进set,有n+n+2^n的空间消耗
 *
 *
 * 现在的解法，使用二维数组记录每个位置元素的选择
 * 每一步作两个元素，分别尝试
 *
 * 状态变量,记录位置变量 有3n+n的空间消耗
 */

#include <iostream>
#include <algorithm>

#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 100

const char SIGN[]="9g";
const int OPT = 2; //可选元素个数

//找到9和g出现的问题，记录位置进行全排列
void findAppear(char *str,int pos[],int *count)
{
    *count=0;
    if(str==NULL) return;
    int len = strlen(str);
    if(len==0) return;
    for(int i=0;i<len;++i)
        if(str[i]=='9'||str[i]=='g'){//记录位置
            pos[*count]=i;
            ++*count;
        }
}

//尝试在每个出现的位置放置9或者g
//使用used保存状态
void backtrack(char *str,int step,int pos[],int count,bool used[][OPT])
{
    if(step==count){//一轮选择完
        cout<<str<<endl;
    }else{
        bool *p = used[step];//针对每一步尝试
        bool *i = p;
        for(;i<p+OPT;++i){
            if(*i) continue;
            *i = true;//选择一个元素
            str[pos[step]]=SIGN[i-p];//对应这一步选择的元素
            backtrack(str,step+1,pos,count,used);//下一个位置
            *i = false;//恢复原状
        }
    }
}

int main(int argc, char *argv[])
{
    char str[MAXN];//最长长度100
    fgets(str,MAXN,stdin);
    int len = strlen(str);
    str[--len]='\0';//去掉\n

    int pos[MAXN]={0};
    int count;//记录参与排列的个数
    //寻找g和g位置
    findAppear(str,pos,&count);

    //所有可能
    if(count>0){
        bool used[count][OPT]={false};
        backtrack(str,0,pos,count,used);
    }
    return 0;
}
