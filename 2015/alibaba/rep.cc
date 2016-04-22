/**
 * reinterpret_cast强制转型
 *
 */
#include <iostream>
#include <alloca.h>

using namespace std;

struct Node{
    int key;
    int value;
    Node(int k,int v):key(k),value(v){}
};


int main()
{
    Node *p = new Node(10,12);
    cout<<*reinterpret_cast<unsigned long*>(p)<<endl;
    p->key = 12;
    cout<<*reinterpret_cast<unsigned long*>(p)<<endl;

    double f = 1.9;
    cout<<*reinterpret_cast<int*>(&f)<<endl;

    delete p;
    return 0;

}
