/*
 * malloc free new delete 不配套使用
 *
 * 结论:不要混用,容易引发未成功的状态
 *
 * 对于对象来说，malloc不会调用构造函数
 * free不会调用析构函数
 *
 * new int() --> delete
 * new int[] --> delete[]
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void testcase()
{
    int *p = new int(3);
    free(p);
}

void testcase2()
{
    int *p =(int*)malloc(sizeof(int));
    delete p;
}

//一个元素的申请为什么不会造成内存泄露
//因为数组首地址就是第一个元素的地址，所以可以释放
void testcase3()
{
    int *a = new int[1];
    delete a;
}

//数组的释放
//
void testcase4()
{
    int *p = new int[12];
    for(int i=0;i<12;++i)
        p[i]=i;
    delete []p;
}

int main(int argc, char *argv[])
{
    //testcase();
    //testcase2();
    return 0;
}
