#include <stdio.h>
#include <stdint.h>
#include <string>
#include <algorithm>

#include <boost/typeof/typeof.hpp>
#include "size.pb.h"

void print_bin(const std::string & data)
{
    for(BOOST_AUTO(it,data.begin());it!=data.end();++it)
    {
        printf("%-3x",*it);
    }
    printf("\n");
}

void test()
{
    Size size;
    DyMsg msg;
    msg.set_topic("mtest");
    msg.set_tag("TagA");
    msg.set_body("haha");
    uint32_t sz = msg.ByteSize();// must greater than 0
    size.set_length(sz);

    std::string head,body;
    msg.SerializeToString(&body);

    size.SerializeToString(&head);

    print_bin(head);

    // 需要把head第一位去掉，和body拼接才是完整的netty数据包
    std::string out(head.begin()+1,head.end());
    out.append(body);

    print_bin(out);

    FILE * fp = fopen("enc","wb");
    if(fp!=NULL)
    {
        fwrite(out.c_str(),1,out.size(),fp);
        fclose(fp);
    }
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}

