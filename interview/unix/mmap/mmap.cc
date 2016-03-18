/**
 * 内存映射文件实现
 * 操作内存直接操作文件
 * 避免了标准I/O从内核到标准的复制，和
 * 到行标准I/O的再次复制
 */

#include <cstdio>
#include <sys/mman,h>

int main(int argc, char *argv[])
{
    if(argc<2){
        printf("%s filename.\n",argv[0]);
        return -1;
    }

    int fin;
    if((fin=open(argv[1],O_RDONLY)<0){
            fprintf(stderr,"can't open file.\n");
            return 1;
    }

    struct stat sbuf;
    if(fstat(find,&sbuf)<0){
        fprintf(stderr,"fstat error.\n");
    }
    printf("size:%d\n",sbuf.st_size);

    void *p;
    off_t fsz = 0;
    while(fsz<sbuf.st_size){

    }
    if(p= nmap(0,)
    return 0;
}
