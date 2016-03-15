#include <iostream>
#include <cassert>
using namespace std;


struct ListNode{
    int data;
    ListNode *next;
    ListNode(int d=0):data(d),next(NULL){}

};

void printList(ListNode *pHead)
{
    if(pHead==NULL)
        return;
    int i=0;
    ListNode *p=pHead->next;
    while(p!=NULL){
        cout<<"["<<i++<<"]:"<<p->data<<endl;
        p=p->next;
    }
}

ListNode *createList(ListNode **pHead)
{
    ListNode *p,*q;
    if((*pHead)!=NULL)
        return *pHead;
    *pHead = new ListNode;
    p=new ListNode(1);
    (*pHead)->next = p;
    q=p;
    int i=2;
    while(i<=10){
        p=new ListNode(i);
        q->next = p;
        q=p;
        ++i;
    }
    return *pHead;
}

bool destroyList(ListNode *pHead)
{
    if(pHead==NULL)
        return true;
    ListNode *p=pHead,*q;
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
    return true;
}

/**
 * 获取倒数第K个节点
 */
ListNode *GetLastKNode(ListNode *pHead,unsigned int k)
{
    if(k==0||pHead==NULL)
        return NULL;
    ListNode *p,*q=pHead->next;
    unsigned int i=0;
    while(i<k){
        if(q==NULL) return NULL;//小于K个节点
        q=q->next;
        i++;
    }
    p=pHead->next;
    while(q!=NULL){
        q=q->next;
        p=p->next;
    }
    return p;
}
/**
 * 合并两个升序的链表
 */

/**
 * 没有头节点的合并
 */
ListNode *merge(ListNode *p,ListNode *q)
{
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;

    ListNode *head;
    if(p->data<q->data){
        head = p;
        head->next = merge(p->next,q);
    }else{
        head = q;
        head->next = merge(p,q->next);
    }
}

ListNode *MergeList(ListNode *pHead1,ListNode *pHead2)
{
    if(pHead1==NULL&&pHead2==NULL)
        return NULL;
    else{
        ListNode *head;
        if(pHead1!=NULL&&pHead2==NULL)
            head = pHead1;
        else if(pHead2!=NULL&&pHead1==NULL)
            head = pHead2;
        else{
            ListNode *p = pHead1->next;
            ListNode *q = pHead2->next;
            ListNode *list,*tmp;
            bool isHead = true;
            while(p!=NULL&&q!=NULL){
                if(p->data<q->data){
                    tmp = p;
                    p=p->next;
                }else{
                    tmp = q;
                    q=q->next;
                }
                //设置连接节点
                if(isHead){
                    head = pHead1;//默认头节点
                    isHead = false;
                    list = tmp;
                    head->next = list;//设置第一个节点
                }else{
                    list->next = tmp;
                    list = tmp;//设置下一个节点
                }
            }
            while(p!=NULL){
                list->next = p;
                p=p->next;
                list = list->next;
            }
            while(q!=NULL){
                list->next = q;
                q=q->next;
                list = list->next;
            }

        }
        return head;
    }
}

void testcase(ListNode *pHead)
{
    unsigned int k = 1;
    ListNode *p = GetLastKNode(pHead,k);
    cout<<"k:"<<k<<","<<p->data<<endl;

    p=GetLastKNode(NULL,k);
    assert(p==NULL);//"GetLastKNode ERROR.");

    k = -2;
    p = GetLastKNode(pHead,k);
    assert(p==NULL);//"GetLastKNode ERROR.");
    //cout<<"k:"<<k<<","<<p->data<<endl;

    k=10;
    p = GetLastKNode(pHead,k);
    cout<<"k:"<<k<<","<<p->data<<endl;

    k=3;
    p = GetLastKNode(pHead,k);
    cout<<"k:"<<k<<","<<p->data<<endl;

    k=11;
    p = GetLastKNode(pHead,k);
    assert(p==NULL);

    //只有头节点
    ListNode head;
    p = GetLastKNode(&head,0);
    assert(p==NULL);

    head.next = new ListNode(12);
    p = GetLastKNode(&head,1);
    assert(p->data == 12);
    p = GetLastKNode(&head,2);//head没有值
    assert(p==NULL);

    delete head.next;
}

void merge_testcase()
{
    ListNode *p=NULL,*q=NULL;
    createList(&p);
    createList(&q);
    ListNode *head = MergeList(p,q);
    cout<<"相同长度链表:"<<endl;
    printList(head);
    destroyList(head);
    delete p,q;
    p=q=NULL;

    ListNode *pNull=NULL,*pFull=NULL;
    createList(&pFull);
    ListNode *head2 = MergeList(pNull,pFull);
    cout<<"一个为Null链表:"<<endl;
    printList(head2);
    destroyList(head2);
    delete pFull;

    ListNode *qNull1=NULL,*qNull2=NULL;
    assert(MergeList(qNull1,qNull2)==NULL);

    p = new ListNode;
    p->next = new ListNode(3);
    q = new ListNode;
    q->next = new ListNode(2);
    q->next->next = new ListNode(5);

    cout<<"不同长度链表:"<<endl;
    ListNode *head3 = MergeList(p,q);
    printList(head3);
    destroyList(head3);
    delete p,q;
    p=q=NULL;

    p = new ListNode;
    q = new ListNode;
    //p->next = new ListNode(1);
    q->next = new ListNode(1);
    /*
    //没有通过
    ListNode *head4 = MergeList(p,q);
    */
    cout<<"只有一个节点链表:"<<endl;

    //去除了头节点之外的合并
    ListNode head4;
    head4.next = merge(p->next,q->next);
    printList(&head4);
    destroyList(head4.next);//dobule free
    delete p,q;
    p=q=NULL;

}

int main(int argc, char *argv[])
{
    /*
    ListNode *list=NULL;
    createList(&list);
    printList(list);
    testcase(list);
    destroyList(list);
    */

    merge_testcase();
    return 0;
}
