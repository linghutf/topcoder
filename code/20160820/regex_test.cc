#include <iostream>
#include <boost/regex.hpp>

int main(int argc, char *argv[])
{
    if(boost::regex_match(argv[1],boost::regex("(a)+(b)")))
    {
        std::cout<<"ok\n";
    }
    return 0;
}
