/**
 * 从特定集合中选择元素组成全排列
 */

#include <iostream>
#include <algorithm>

using namespace std;

const char s[]="9g";

int main(int argc, char *argv[])
{
    char str[10];
    do{
        cout<<str<<endl;
    }while(std::next_permutation(s,s+2));
    return 0;
}
