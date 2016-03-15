#include "quicksort.h"

void testcase1()
{
    int a[]={};
    quicksort(a,0);

    int b[100];
    for(int i=0;i<100;++i)
        b[i]=rand()%1000;
    quicksort(b,100);
    for(int i=0;i<100;++i)
        std::cout<<b[i]<<'\t';
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    testcase1();
    return 0;
}
