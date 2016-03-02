#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;//不能没有定义长度就使用
    s[0]='1';
    s[2]='2';
    cout<<s<<endl;

    string v(10,'t');//可以使用
    v[0]='1';
    v[1]='2';
    cout<<v<<endl;

    string t;//像使用vector一样
    t.push_back('f');
    t.push_back('p');
    cout<<t<<endl;
    return 0;
}
