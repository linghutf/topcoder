#include <stdio.h>

struct A{
    char c;//2
    short b;//2
    int a;//4
};

struct B{
    char c;//4
    int a;//4
    short b;//4
};

struct C{
    int a;//4
    char c;//2
    short b;//2
};

int main()
{
    printf("A:%4lu\n",sizeof(struct A));//8
    printf("B:%4lu\n",sizeof(struct B));//12
    printf("C:%4lu\n",sizeof(struct C));//8
    return 0;
}
