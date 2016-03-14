#include <iostream>
#include <algorithm>

using namespace std;

void strPermutate(char *str,char *begin)
{
    if(str==NULL)
        return;
    if(*begin=='\0'){
        cout<<str<<endl;
    }else{
        for(char *p = begin;*p!='\0';++p){//一个个字符尝试
            std::swap(*p,*begin);//交换位置
            strPermutate(str,begin+1);//处理下一个位置
            std::swap(*p,*begin);//返回
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc<2){
        cout<<argv[0]<<" str."<<endl;
        return -1;
    }
    //char s[]="";
    strPermutate(argv[1],argv[1]);
    return 0;
}
