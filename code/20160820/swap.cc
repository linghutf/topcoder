#include <iostream>

template<typename T>
void myswap(T & a,T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void myswap(T * a,T * b)
{
    if(a==NULL||b==NULL)
        return;
    T tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(int argc, char *argv[])
{
    int a = 10,b = 12;

    myswap(a,b);
    std::cout<<a<<","<<b<<std::endl;

    myswap(&a,&b);
    std::cout<<a<<","<<b<<std::endl;

    int *p = new int(2);
    //int *q; //并不是NULL
    int *q=NULL;
    myswap<int*>(p,q);
    delete p;
    return 0;
}
