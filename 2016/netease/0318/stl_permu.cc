/**
 * 字典序非递归全排列
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    char s[]="1112";//可以排除重复，但是需要有序
    int len = sizeof(s)-1;
    do{
        cout<<s<<endl;
    }while(std::next_permutation(s,s+len));
    return 0;
}
