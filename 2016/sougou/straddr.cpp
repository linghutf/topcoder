#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string a="hello";
    //c_str()指向不同的地址
    string b=a;
    if(a.c_str()==b.c_str())
        cout<<"true";

    return 0;
}
