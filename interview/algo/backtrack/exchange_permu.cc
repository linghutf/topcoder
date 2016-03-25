/**
 * 交换法排列的可能组合
 */

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void backtrack(char *str,int step,int stop)
{
    if(step==stop){
        cout<<str<<endl;
    }else{
        char lastc='\0';
        for(int i=step;i<stop;++i){
            if(*(str+i)==lastc) continue;//相同跳过
            std::swap(*(str+step),*(str+i));
            lastc = *(str+i);
            backtrack(str,step+1,stop);
            std::swap(*(str+step),*(str+i));
        }
    }
}

int main(int argc, char *argv[])
{
    char str[]="112";
    int len = sizeof(str)-1;
    backtrack(str,0,len);
    return 0;
}
