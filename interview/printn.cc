#include <iostream>
#include <algorithm>

using namespace std;
void printNumber(char *str)
{
    if(str==NULL) return;
    char *p = str;
    while(*p=='0'&& *p!='\0') ++p;//???0???
    cout<<p<<endl;
}

void backtrack(char *str,int n,int step)
{
    if(n==step){
        printNumber(str);
    }else{
        for(char c='0';c<='9';++c){
            str[step]=c;
            backtrack(str,n,step+1);
        }
    }
}

void testcase()
{
    char str[3];
    int len = 2;
    str[len]='\0';
    backtrack(str,len,0);
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
