/**
 * 链表逆转
 *
 */
#include <iostream>
#include <iomanip>
#include <algorithm>

#include <assert.h>

struct Node
{
    int data;
    Node *next;

public:
    Node(int d):
        data(d),next(NULL){}
};

// 创建链表
void create_list(Node * &head)
{
    if(head!=NULL) return;
    head = new Node(-1);
    Node * p = head;
    Node * q;
    q = p;
    for(int i=0;i<10;++i)
    {
        p = new Node(i);
        q->next = p;
        q = p;
    }
}

// 打印链表
// 传递指针并不会改变指针本身
void print_list(Node * p)
{
    p = p->next;
    while(p!=NULL)
    {
        std::cout<<std::setw(4)<<p->data;
        p = p->next;
    }
    std::cout<<std::endl;
}

// 反转列表
void reverse_list(Node *& head)
{
    // 处理特殊情况
    if(head == NULL)
    {
        return;
    }
    Node * p = head->next;
    Node * q = p->next;//q为p下一个位置
    p->next = NULL;//末尾为空
    Node * tmp;
    while(q != NULL)
    {
        tmp = q->next;// tmp为q下一个位置
        q->next = p; //改变q指向p,反转
        p = q;//移到下一个位置
        q = tmp;
    }
    head->next = p;
}

// 释放列表
void free_list(Node *& head)
{
    Node * p;
    while(head!=NULL)
    {
        p = head;
        head = head->next;
        delete p;
        p = NULL;
    }
}

// 倒数第K个节点
// len - k
struct Node * last_k_node(struct Node * head,int num)
{
    if(head==NULL||num==0)
    {
        return NULL;
    }
    struct Node * p = head;
    struct Node * q = p;
    // p先走num-2步
    // 无法分辨是否是到达尾结点还是长度不够,因此改为head和next
    for(int i = 0; i < num-1;++i)
    {
        if(p->next!=NULL)
            p = p->next;
        else
            return NULL;
    }

    if(p->next==NULL)
    {
        return NULL;
    }
    // 相差 num-2个位置
    // p 和 q 同步走len-num位置
    while(p->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    return q;
}


/*------------- TEST ---------------*/
// 测试为空的情况
void test_null()
{
    Node * p = NULL;
    reverse_list(p);
}

// 测试倒数第k个节点
void test_last_k_node(struct Node * head)
{
    struct Node * p = last_k_node(head,1);
    assert(p->data == 0);

    p = last_k_node(head,10);
    assert(p->data == 9);

    p = last_k_node(head,-1);
    assert(p==NULL);

    p = last_k_node(head,11);
    assert(p==NULL);
}

int main(int argc, char *argv[])
{
    Node * p = NULL;

    create_list(p);
    print_list(p);

    reverse_list(p);
    print_list(p);

    // 测试用例
    test_last_k_node(p);

    free_list(p);
    assert(p==NULL);

    test_null();

    return 0;
}
