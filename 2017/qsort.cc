/**
 * 单链表的快排
 * 每一次交换，快慢指针，到达中点，两个指针交换移动
 */

#include <iostream>
#include <algorithm>

struct Node
{
    int data;
    Node * next;
};

Node * parition(Node * head)
{
    if(head==NULL) return NULL;
    Node * p = head;
    Node * q = p;
    // 一个指针到达中点
    while(p->next!=NULL)
    {
        p = p->next->next;
        q = q->next;
    }

    // head的值作为枢轴
    Node * mid = q;
    p = head;
    q = mid->next;
    while(q!=NULL)
    {
        while(p->data < head->data) p=p->next;
        while(q->data > head->data) q=q->next;
        if(q==NULL) break;
        std::swap(p->data,q->data);
    }
    std::swap(head->data,mid->data);
    return mid;
}

void mysort(Node * head,Node * tail)
{
    if(head==NULL||head->next==NULL) return;
    if(head!=tail)
    {
        Node *privot = parition(head->next);
        mysort(head->next,privot);
        mysort(privot->next,tail);
    }
}

int main(int argc, char *argv[])
{
    int n = 10;
    Node lst,*q,*prev;
    Node * p = new Node;
    p->data = n--;
    lst.next = p;
    q = p;
    prev = p;
    while(n!=0)
    {
        p = new Node;
        p->data = n--;
        q->next = p;
        prev = q;
        q = p;
    }
    q->next = NULL;

    mysort(lst.next,prev);

    p = lst.next;
    while(p!=NULL)
    {
        std::cout<<p->data<<',';
    }
    std::cout<<std::endl;

    return 0;
}
