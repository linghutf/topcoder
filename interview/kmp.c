#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>
/**
 * 找到返回位置
 * 未找到返回-1
 * kmp的子串移动是按照子串的特性，而不是目标串的状态。
 * 失配情况下,前缀(后缀)字符相同的情况下尽可能长
 * str:  s s s s x
 * sub:  s s s s b
 *   j:  1 2 3 4 5
 *              失配
 * 前缀: . . .    3(前后相等)
 * 后缀:   . . .  3(最大长度)
 *    k:         4(3+1)
 * next: 0 1 2 3 4(失配情况下移动位置)
 *
 * sub移动:s s s s v(例子)
 *
 * sub 没有重复，匹配失败则前移到1-1位置
 *     2个重复字符,              2-1位置
 *     3个重复,                  3-1位置
 *     ...
 */
//求模式串的next数组

//没有使用next[j]=next[k]时，
//当前位置的值 由最长相等的前后缀长度决定
// 0 1 2 3 4 5 6 7 8
// x y x y y x x y x
//-1 0 0 1(x=x)
//-1 0 0 1 2(xy=xy)
//-1 0 0 1 2 0 1 1 2

void GetNext(const char *str,int *next)
{
    if(str==NULL||next==NULL)
        return;
    int len = strlen(str);
    int j=0,k=-1;//j表示后缀,k表示前缀
    next[j]=k;//第一个位置
    while(j<len){
        if(k==-1||str[j]==str[k]){//匹配成功
            k++;//i:len-1 -> len,next越界，所以要多申请1个空间
            j++;
            if(str[j]!=str[k])
                next[j]=k;//不是连续相同的
            else
                next[j]=next[k];

        }else{//回溯到上一个j的位置
            k=next[k];
        }
    }
}

int search(const char *sub,const char *str)
{
    int pos = -1;
    if(str==NULL)
        return pos;
    if(sub==NULL)
        return 0;
    int slen = strlen(str);
    int tlen = strlen(sub);
    if(tlen==0) return 0;
    //int *next = (int*)malloc(sizeof(int)*tlen);
    int *next = (int*)alloca(sizeof(int)*tlen);
    if(next==NULL){
        printf("malloc ERROR.\n");
        return pos;
    }
    //next作为匹配失败时的回退位置
    GetNext(sub,next);
    /*
    printf("next:");
    for(int i=0;i<tlen;++i)
        printf("%3d",next[i]);
    printf("\n");
    */
    //开始匹配
    int i=0,j=0;
    while(i<slen){
        if(j==-1||str[i]==sub[j]){//j=-1回到起始位置
            i++;
            j++;
            if(j==tlen)//found
                break;
        }else{//匹配失败，移动sub
            j = next[j];//next[0]=-1,表示i,j同时前移
        }

    }
    //free(next);
    if(j==tlen){//完成一次完全匹配
        pos = i-j;
    }
    return pos;
}

int main(int argc, char *argv[])
{
    if(argc<3){
        printf("%s str test-sub.\n",argv[0]);
        return -1;
    }
    char *str = argv[1];
    char *sub = argv[2];
    printf("%d\n",search(sub,str));
    return 0;
}
