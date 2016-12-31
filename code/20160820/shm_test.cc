/**
 * 共享内存测试
 */

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <pthread.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * SHM_NAME = "shm.tmp";

void * read_shm()
{
    struct stat st;
    int fd = shm_open(SHM_NAME,O_RDONLY,0);
    if(fd==-1)
    {
        perror("open shared mem ERROR");
        return NULL;
    }

    // 设置stat
    if(fstat(fd,&st)==-1)
    {
        printf("fstat ERROR!\n");
        return NULL;
    }

    void * addr = mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,fd,0);
    if(addr == MAP_FAILED)
    {
        perror("mmap ERROR");
        return NULL;
    }

    // 关闭文件描述符
    close(fd);

    // 读取内容
    write(STDOUT_FILENO,addr,st.st_size);
    printf("\n");

    return NULL;
}

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("usage:%s filename.\n",argv[0]);
        return 1;
    }
    int fd;
    size_t len;
    void * addr;

    // 打开共享内存
    fd = shm_open(SHM_NAME,O_RDWR,0);
    if(fd==-1)
    {
        perror("create shared mem ERROR");
        return 1;
    }

    // 打开文件
    FILE * fp = fopen(argv[1],"rb");
    if(fp==NULL)
    {
        printf("cannot open file:%s\n",argv[1]);
        return 1;
    }

    // 设置共享内存大小
    len = ftell(fp);
    if(-1==ftruncate(fd,len))
    {
        printf("truncate ERROR!\n");
        return 1;
    }

    // 映射共享内存
    addr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(addr == MAP_FAILED)
    {
        perror("mmap ERROR");
        return 1;
    }

    // 关闭文件描述符
    close(fd);

    // 拷贝文件到共享内存
    size_t sz = 0;
    char buf[BUFSIZ];
    size_t offset = 0;
    while((sz=fread(buf,1,BUFSIZ,fp))!=0)
    {
        memcpy(addr+offset,buf,sz);
        offset+=sz;
    }

    // 测试读取内容
    read_shm();

    sleep(10);
    if(munmap(addr,len)==-1)
    {
        perror("unmap ERROR");
        return 1;
    }

    shm_unlink("/shm_test");
    return 0;
}
