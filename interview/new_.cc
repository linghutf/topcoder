#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int>* it = new list<int>();
    delete it;
    return 0;
}
