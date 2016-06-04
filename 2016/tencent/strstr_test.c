#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<2){
        printf("usage:%s substr.\n",argv[0]);
        return 1;
    }
    char str[]="1234_1_23";

    printf("%s is :%s\n",argv[1],strstr(str,argv[1]));
    return 0;
}
