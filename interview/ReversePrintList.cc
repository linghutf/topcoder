/**
 * 逆序打印链表:递归，栈
 *
 * 反转单链表
 */
#include <iostream>
#include <stack>
//#include <list>

using namespace std;

struct List{
    int d;
    struct List *next;
    List(int _d=0):d(_d),next(NULL){}
};

List *createList(List &li)
{
    List *head = &li;
    List *p,*q;
    p=new List(10);
    head->next=p;
    q=p;
    int i=9;
    while(i>0){
        p=new List(i);
        q->next=p;
        q=p;
        --i;
    }
    q->next=NULL;
    return head;
}

//递归法逆序打印
//传入不带head的List
void print(List *li)
{
    if(li->next!=NULL){
        print(li->next);
    }
    cout<<li->d<<'\t';
}

void printByStack(List *li)
{
    stack<int> s;
    while(li!=NULL){
        s.push(li->d);
        li=li->next;
    }
    while(s.size()>0){
        cout<<s.top()<<'\t';
        s.pop();
    }
    cout<<endl;
}

void destroy(List *head)
{
    List *p=head->next,*q;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
}

//反转单链表
List *ReverseList(List *pHead)
{
    if(pHead==NULL||pHead->next==NULL) return pHead;
    List *p = pHead->next,*q,*tmp;
    q=p->next;
    tmp = q->next;
    q->next=p;
    p->next=NULL;
    p=q;
    q=tmp;
    while(q!=NULL){
        //q=p->next;//store next addr
        tmp = q->next;
        q->next = p;//reverse
        p=q;//p->next已经改变,指向以前的p
        q=tmp;
    }

    pHead->next=p;//add to head
    return pHead;
}

int main(int argc, char *argv[])
{
    List head;
    createList(head);

    cout<<"逆序:";
    print(head.next);
    cout<<endl;
    printByStack(head.next);

    cout<<"顺序:";
    ReverseList(&head);
    print(head.next);
    cout<<endl;

    destroy(&head);
    return 0;
}
