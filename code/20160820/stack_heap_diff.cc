/**
 * 栈和堆的区别
 */
#include <iostream>

static size_t g_count = 0;

class Object
{
    public:
        Object(){std::cout<<"construct obj...["<<g_count++<<"]\n";}
        ~Object(){std::cout<<"destroy obj...["<<--g_count<<"]\n";}
};

// 测试栈溢出
void test_stack_overflow()
{
    Object objs[0x7fffffff];
}

// 测试局部对象退出作用域自动释放
void test_stack_area()
{
    {
        Object obj;
    }// 退出作用域,删除
}


int main(int argc, char *argv[])
{
    test_stack_area();

    test_stack_overflow();

    return 0;
}
