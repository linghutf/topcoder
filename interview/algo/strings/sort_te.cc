#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    char s[]=" a 123 ad";
    sort(std::begin(s),std::end(s)-1);
    cout<<s<<endl;
    return 0;
}
