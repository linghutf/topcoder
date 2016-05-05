//测试fwrite返回值
//#define CATCH_CONFIG_RUNNER
//#include <catch.hpp>

#include <cstdio>
#include <cstring>

int read(char* filename,char* raw,int& rawSize){
    FILE *fp = fopen(filename,"rb");
    size_t bytecount = 0;
    size_t nread = 0;
    while((nread=fread(raw+bytecount,sizeof(char),BUFSIZ,fp))!=0){
        bytecount+=nread;
    }
    printf("%lu\n",bytecount);
    fclose(fp);
    rawSize = bytecount;
    return 0;
}

int write(char* filename,char* raw,int rawSize){
    FILE *fp = fopen(filename,"wb");
    //REQUIRE(fp!=NULL);

    size_t bytecount = 0;
    size_t total = rawSize;
    size_t nwrite = 0;
    while(total>BUFSIZ){
        nwrite = fwrite(raw+bytecount,sizeof(char),BUFSIZ,fp);
        if(nwrite!=BUFSIZ){
            printf("Write data ERROR!\n");
            break;
        }
        bytecount+=nwrite;
        total-=nwrite;
    }

    if(total>0){
        nwrite = fwrite(raw+bytecount,sizeof(char),total,fp);
        if(nwrite!=total){
            printf("Write tail ERROR!\n");
        }
        bytecount+=nwrite;
        total-=nwrite;
    }

    fclose(fp);
    printf("writed:%lu\n",bytecount);
    return 0;
}

int main()
{
    char filename[]="test.dat";
    char data[]="1234";
    int len = strlen(data);

    write(filename,data,len);
    char p[12];
    int read_len=0;
    read(filename,p,read_len);
    printf("read:%d\n",read_len);

    for(int i=0;i<read_len;++i){
        printf("%c",p[i]);
    }
    printf("\n");
    return 0;
}
