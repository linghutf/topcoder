#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
    bitset<11> v(751350255);
    cout<<v.count()<<endl;
    return 0;
}
