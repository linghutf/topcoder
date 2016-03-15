#include <iostream>
#include <cstdlib>

using namespace std;

int mod(int a,int b)
{
    if(b==0){
        throw std::overflow_error("不能为0!");
    }
    return a%b;
}

int main(int argc, char *argv[])
{
    int *p = new int(10);

    try{
        int b = atoi(argv[1]);
        int r=mod(10,b);
        cout<<r<<endl;
    }catch(std::exception &e){//catch(...)捕获所有异常
        cout<<e.what()<<endl;
        //释放p

        if(p!=NULL)
            delete p;
        p=NULL;

    }
    if(p!=NULL)
        delete p;
    return 0;
}
