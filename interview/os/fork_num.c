#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>

int main()
{
    fork();//有p和c两个
    /**
     * p->p,c0
     * p和c都是父进程,相同看待为P
     * P fork1():P和C0,为P的部分 执行fork2,产生PC0和P,P为真，不执行fork3,
     * PC0为假，执行fork3(),产生PC0和PC0C0
     * 共有P,PC0,PC0C0，3个
     *
     *                为C0的部分,是假,不执行后面的fork2,直接执行fork3,产生C0和C0C0,
     * 共有C0,C0C0，2个
     * 一个进程一共有5个进程
     * p和c0变成10个
     */
    fork() && fork() || fork();//p:5个,c:5个
    fork();//10*2=20个-p=19个

    sleep(10);
    return 0;
}
