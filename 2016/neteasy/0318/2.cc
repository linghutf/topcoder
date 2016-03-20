#include <iostream>
#include <algorithm>
#include <vector>

#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 1000

int *split(char *s,char *c)
{
    char *p = strtok(s,c);
    int *dest = new int[N];
    int cnt = 0;
    while(p!=NULL){
        dest[cnt++]=atoi(p);
        p = strtok(NULL,c);
    }
    return dest;
}

int *GetDepend(char *s,char *sep,char *t)
{
    char *p = s;
    while(*p!=' ') ++p;
    strncpy(t,s,p-s);
    return split(p,sep);
}

void SortFile(int a[][],char buf
int main(int argc, char *argv[])
{
    unsigned int t;
    cin>>t;
    if(t>100) return -1;
    int i,j,k;
    int *a;
    char buf[100];
    char buf2[N][12];
    for(i=0;i<t;++i){
        cin>>j;
        a = new int*[j];
        for(k=0;k<j;++k){
            fgets(buf,100,stdin);
            int len = strlen(buf);
            buf[--len]='\0';
            a[k]=GetDepend(buf," ",buf2[k]);
        }
        //handle
        SortFile(a,buf2);
        //clear
        delete[] a;
    }
    return 0;
}
