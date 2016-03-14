/**
 *全排列打印从1到n位数
 */

#include <iostream>
#include <cstring>

using namespace std;

void PrintNumber(char *num)
{
    int i=0;
    while(num[i]=='0') ++i;
    //printf("%s\n",num+i);
    cout<<num+i<<endl;
}
//全排列
void PrintOneToMaxOfNDigitsByRecursively(char *num,int len,int index)
{
    if(index == len-1){//到达边界
        PrintNumber(num);
        return ;
    }

    for(int i=0;i<10;++i){
        num[index+1]='0'+i;
        PrintOneToMaxOfNDigitsByRecursively(num,len,index+1);
    }
}

void PrintOneToMaxOfNDigits(int n)
{
    if(n<=0)
        return;
    char *number[n+1];//难道是新标准支持了?
    memset(number,'0',n);
    number[n]='\0';
    for(int i=0;i<10;++i)
    {
        number[0]='0'+i;
        PrintOneToMaxOfNDigitsByRecursively(number,n,0);
    }
}

void testcase()
{
    PrintOneToMaxOfNDigits(3);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
