#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int *p=0;//ok,(void*)0=NULL
    //int *q=1;//error
    int &rp=*p;
    return 0;
}
