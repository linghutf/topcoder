#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string a="hello";
    //c_str()指向不同的地址
    string b=a;
    const char *p=a.c_str();
    const char *q=b.c_str();
    cout<<&p<<","<<&q<<endl;
    if(a.c_str()==b.c_str())
        cout<<"true";
    else cout<<"false"<<endl;

    string c=b;
    c="";
    if(a.c_str()==b.c_str())
        cout<<"true";
    else cout<<"false"<<endl;

    a="";
    if(a.c_str()==b.c_str())
        cout<<"true";
    else cout<<"false"<<endl;
    return 0;
}
