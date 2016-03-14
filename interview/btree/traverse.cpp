#include <iostream>
#include <algorithm>
#include <vector>

#include "btree.hpp"

static std::vector<BinaryNode<int>*> v;

template<typename T=int> BinaryNode<T>* createTree(BinaryNode<T> *proot)
{
    if(proot!=NULL)
        delete proot;

    proot = new BinaryNode<T>(17);
    proot->left = new BinaryNode<T>(12);
    proot->right = new BinaryNode<T>(19);

    BinaryNode<T> *p,*q;

    p=proot->left;
    p->left = new BinaryNode<T>(10);
    p->right = new BinaryNode<T>(15);

    q = p->right;
    p = p->left;
    p->left = new BinaryNode<T>(8);
    p->right = new BinaryNode<T>(11);

    q->left = new BinaryNode<T>(13);
    q->right = new BinaryNode<T>(16);

    p = proot->right;
    p->left = new BinaryNode<T>(18);
    p->right = new BinaryNode<T>(25);

    q = p->right;
    q->left = new BinaryNode<T>(22);
    return proot;
}

template<typename T> int visitNode(BinaryNode<T> *p)
{
    if(p!=NULL)
        std::cout<<p->val<<'\t';
    return true;
}

template<typename T> int destroyNode(BinaryNode<T> *p)
{
    v.push_back(p);
    return true;
}

void testcase()
{
    BinaryNode<int> *proot=NULL;
    proot=createTree(proot);

    std::cout<<"前序遍历:"<<std::endl;
    preorder(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"前序遍历:"<<std::endl;
    preorderNotRecursive(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"中序遍历:"<<std::endl;
    inorder(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"中序遍历:"<<std::endl;
    inorderNotRecursive(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"后序遍历:"<<std::endl;
    postorder(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"后序遍历:"<<std::endl;
    postorderNotRecursive(proot,visitNode<int>);
    std::cout<<std::endl;

    std::cout<<"层次遍历:"<<std::endl;
    levelorder(proot,visitNode<int>);
    std::cout<<std::endl;

    //delete
    //std::vector<BinaryNode<int>*> v;
    levelorder(proot,destroyNode<int>);//std::back_inserter<decltype(proot)>(v));
    std::for_each(v.begin(),v.end(),[](BinaryNode<int> *p){
            delete p;
            });
}


int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
