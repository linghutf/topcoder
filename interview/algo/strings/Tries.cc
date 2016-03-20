/**
 * 实现单词tries树
 */
#include <iostream>
#include <algorithm>

#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

struct Node{
    char c;
    Node *next;
    int LT;
    Node(char _c,Node *_next):c(_c),next(_next){}
};

void BuildTries(Node *pHead,char *s)
{
    if(s==NULL) return ;
    int len = strlen(s);
    if(s==0) return;
    Node *p = pHead->next;
    char *q=s;
    while(p->c==tolower(*q)&& q<=s+len){
        p=p->next;
        q++;
    }
}
