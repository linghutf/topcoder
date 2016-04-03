/**
 * 测试不经过用户空间的零拷贝sendfile函数
 */
#include <stdio.h>
#include <sys/sendfile.h>

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1],"rb");
    FILE *fout = fopen(argv[2],"wb");
    fseek(fin,0,SEEK_END);
    size_t len = ftell(fin);
    rewind(fin);
    size_t n;
    if((n=sendfile(fout,fin,NULL,len))<len){
            printf("error send.\n");
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
