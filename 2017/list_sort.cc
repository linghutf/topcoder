#include <iostream>
#include <algorithm>

struct Node
{
    int data;
    Node * next;
};

// 插入一个节点到链表开头
void insert(Node ** head_ref,int new_data)
{
    Node * new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(Node * node)
{
    while(node != NULL)
    {
        std::cout<<node->data<<',';
        node = node->next;
    }
    std::cout<<'\n';
}

Node * get_tail(Node * cur)
{
    while(cur!=NULL && cur->next!=NULL)
        cur = cur->next;
    return cur;
}

Node * partition(Node * head,Node * end,Node ** newHead,Node ** newEnd)
{
    Node * pivot = end;
    Node * prev = NULL,*cur = head,*tail = pivot;

    while(cur!=pivot)
    {
        if(cur->data < pivot->data)
        {
            // 第一个值小于枢轴的节点为新的头结点
            if(*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if(prev)
            {
                prev->next = cur->next;
            }
            Node * tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // 如果枢轴的值是最小值，枢轴成为头结点
    if(*newHead == NULL)
    {
        *newHead = pivot;
    }
    // 新的尾结点
    *newEnd = tail;
    return pivot;
}

Node * list_qsort(Node * head,Node * end)
{
    if(!head||head==end)
        return head;
    Node * newHead = NULL,*newEnd = NULL;

    Node * pivot = partition(head,end,&newHead,&newEnd);

    if(newHead!=pivot)
    {
        Node * tmp = newHead;
        while(tmp->next!=pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // 排序枢轴前半部分
        newHead = list_qsort(newHead,tmp);

        tmp = get_tail(newHead);
        tmp->next = pivot;
    }

    // 排序枢轴后半部分
    pivot->next = list_qsort(pivot->next,newEnd);
    return newHead;
}

void mysort(Node ** headRef)
{
    *headRef = list_qsort(*headRef,get_tail(*headRef));
}

int main(int argc, char *argv[])
{
    Node list;
    Node *p,*q;
    int n = 10;
    p = new Node;
    p->data = n--;
    list.next = p;
    q = p;
    while(n>0)
    {
        p = new Node;
        p->data = n--;
        q->next = p;
        q = p;
    }
    p->next = NULL;

    Node * head = &list;
    mysort(&head);
    print_list(head);
    return 0;
}
