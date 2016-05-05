#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char d[]="1234";
    char p[12];
    strncpy(p,d,strlen(d));//OK
    printf("%s\n",p);

    char q[2];
    strncpy(q,d,2);//ERROR
    printf("%s\n",q);
    return 0;
}
