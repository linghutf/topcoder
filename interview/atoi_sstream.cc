/**
 * atoi 和 stringstream 对于开头的+都能正常识别
 * 说明+/-开头都是合法的
 * stringstream每次转换之后需要clear，才能正常使用
 */
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

void testcase()
{
    char *p="+123.45";
    int n = atoi(p);
    cout<<n<<endl;

    stringstream ss;
    ss<<p;
    int m;
    ss>>m;
    ss.clear();
    cout<<m<<endl;

    char str[]="-3924x8fc";
    cout<<atoi(str)<<endl;
    ss<<str;
    ss>>m;
    cout<<m<<endl;

    char str2[]="-ffff";
    cout<<atoi(str2)<<endl;
    ss<<str2;
    ss>>m;
    cout<<m<<endl;

}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
