#include <iostream>
#include <algorithm>

struct Node{
    int v;
    Node * next;
};

Node * create_list(Node * head)
{
    if(head==NULL) return NULL;
    Node * p = head;
    Node * q=p;
    head->next = NULL;

    int cnt = 10;
    do{
        p = new Node;
        p->v = cnt--;
        p->next = q->next;
        q->next = p;
    }while(cnt>0);
    return head;
}

void free_list(Node * head)
{
    if(head==NULL) return;
    Node * p = head->next;
    if(p==NULL) return;
    Node * q;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
}

Node * reverse_list(Node * head)
{
    if(head==NULL||head->next==NULL) return NULL;
    Node * prev = head->next;
    Node * cur = prev->next;
    Node * next = cur->next;
    prev->next = NULL;
    while(next!=NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    head->next = cur;
    return head;
}


void print_list(Node * head)
{
    head = head->next;
    while(head!=NULL)
    {
        std::cout<<head->v<<'\t';
        head = head->next;
    }
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    Node node;
    create_list(&node);
    print_list(&node);

    reverse_list(&node);
    print_list(&node);

    free_list(&node);

    return 0;
}
