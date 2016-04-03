#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    char str[]="12345";
    string s(str+2,str+4);//34
    cout<<s<<endl;
    return 0;
}
