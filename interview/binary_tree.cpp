#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node *left;
    Node *right;
};

template<typename T>
Node *Construct(int *preorder,int *inorder,int len)
{
    if(preorder == NULL || inorder==NULL|| len<=0)
        return NULL;
    return ConstructCore(preorder,preorder+len-1,inorder,inorder+len-1);
}

template<typename T>
Node *ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder)
{
    T rootValue = startPreorder[0];
    Node *root = new Node;
    root->data = rootValue;
    root->left = root->right;
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder
                && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input.");
    }

    int *rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }
    if(rootInorder == endInorder)
}
