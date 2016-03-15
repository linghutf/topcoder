/**
 * 删去strB在strA中出现的所有字符
 * bitset翻转
 * 类似2014/tencent/strAInstrB.cpp
 */
#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

/**
 * 不改变stra的值
 */
char* DelCharacter(char *stra,char *strb)
{
    if(stra==NULL||strb==NULL) return stra;
    size_t lenb = strlen(strb);
    if(lenb==0) return stra;

    std::bitset<255> state;
    char *p;
    for(p=stra;*p!='\0';++p){
        state.set(*p);
    }
    for(p=strb;*p!='\0';++p){
        state.set(*p,0);
    }
    size_t len = state.count();
    p=NULL;
    if(len>0){
        p = new char[len+1];
        char *q=p;
        for(int i=0;i<255;++i){
            if(state[i]){
                *q++=(char)i;
            }
        }
        *q='\0';
    }
    return p;
}

void testcase()
{
    char s[]="I love you.";
    char t[]="I have a beautiful house!";
    char *r=DelCharacter(t,s);
    if(r!=NULL){
        cout<<"Ok:"<<r<<endl;
        delete r;
    }
    //delete r;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
