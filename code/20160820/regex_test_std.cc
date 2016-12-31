#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    if(std::regex_match(argv[1],std::regex("(a)+(b)")))
    {
        std::cout<<"ok\n";
    }
    return 0;
}
