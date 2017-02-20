#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
struct Node{
    Node *left,*right;
    T val;
};

template<typename T>
typedef void (*func)(T &);

template<typename T>
void visit(Node<T> * root,typename func fp)
{
    if(root!=NULL){
        fp(root->val);
        visit(root->left);
        visit(root->right);
    }
}
