#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZ 100

void freadtest()
{
    FILE *fp = fopen("pwrite_test.c","rb");

    char buf[SIZ];
    size_t sz;
    sz=fread(buf,1,SIZ,fp);
    printf("sz:%lu,seek offset:%lu\n%s\n",sz,ftell(fp),buf);
    fclose(fp);
}

//原子性的带偏移值读取
void preadtest()
{
    char sbuf[SIZ];
    int fd = open("pwrite_test.c",O_RDONLY);
    ssize_t ssz;
    if(ssz=pread(fd,sbuf,SIZ,SIZ)==-1){
        printf("pread error!%d\n",__LINE__);
        exit(1);
    }
    printf("ssz:%ld,\n%s\n",ssz,sbuf);//offset没变
    close(fd);
}
int main(int argc, char *argv[])
{
    freadtest();
    sleep(5);
    preadtest();

    //printf("equals:%d\n",memcmp(buf,sbuf,BUFSIZ));

    return 0;
}
