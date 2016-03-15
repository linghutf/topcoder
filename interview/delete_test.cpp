#include <iostream>

class Test{
    char *s;
    public:
    ~Test(){delete s;}
};

int main(int argc, char *argv[])
{
    //new 和 delete 成对出现
    int *p=new int[3];
    std::cout<<"array delete ."<<std::endl;
    delete[] p;
    //delete[] p;//不能两次释放，和new 配对出现

    int *q=new int(2);
    std::cout<<"poniter delete ."<<std::endl;
    delete q;
    //delete q;

    Test *t;
    std::cout<<"class delete ."<<std::endl;
    //没有new,但是析构函数有delete,因此错误
    delete t;
    //delete t;
    return 0;
}
