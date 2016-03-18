/**单链表快速排序
 * 使用指针p和q均往next方向移动
 * 保持p和q之间的元素均大于key
 * q之前均小于key
 * 当p到达链尾时，交换q和key,完成一趟排序
 */

#include <iostream>
//#include <list>
#include <algorithm>

using namespace std;

struct Node{
    int key;
    Node *next;
    Node(int k,Node *p):key(k),next(p){}
};


Node* partition(Node *pBegin,Node *pEnd)
{
    int key = pBegin->key;
    Node *q = pBegin;
    Node *p = q->next;
    while(p!=pEnd){
        if(p->key < key){//交换
            q=q->next;
            std::swap(p->key,q->key);
        }
        p = p->next;
    }
    std::swap(q->key,pBegin->key);
    return q;
}

void QuickSort(Node *pBegin,Node *pEnd)
{
    if(pBegin != pEnd)
    {
        Node *index = partition(pBegin,pEnd);
        QuickSort(pBegin,index);
        QuickSort(index->next,pEnd);
    }
}

void print(Node *pHead)
{
    Node *p = pHead->next;
    while(p!=NULL){
        cout<<p->key<<'\t';
        p=p->next;
    }
    cout<<endl;
}

int main(int argc, char *argv[])
{
    int a[]={3,-2,4,5,9,7};
    int len = sizeof(a)/sizeof(a[0]);

    Node *pHead = new Node(-1,NULL);
    Node *p = pHead,*q=p;
    for(int i=0;i<len;++i){
        p = new Node(a[i],NULL);
        q->next = p;
        q=p;
    }

    p = pHead->next;
    QuickSort(p,NULL);
    print(pHead);

    return 0;
}

