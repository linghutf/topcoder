#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <algorithm>
#include <string>

uint16_t swap_uint16(uint16_t n);
uint32_t swap_uint32(uint32_t n);
template<typename T>std::string binary_str(T n);

int main(int argc, char *argv[])
{
    assert(argc==2);

    int n = atoi(argv[1]);

    uint32_t test_n = swap_uint32(n);
    printf("[%x]%s\n[%x]%s\n",n,binary_str(n).c_str(),test_n,binary_str(test_n).c_str());
    return 0;
}

uint16_t swap_uint16(uint16_t n)
{
    uint8_t high = n>>8;
    uint8_t low = n&0x00ff;
    return (low<<8)+high;
}

uint32_t swap_uint32(uint32_t n)
{
    uint16_t high = swap_uint16(n>>16);
    uint16_t low = swap_uint16(n&0x0000ffff);
    return (low<<16)+high;
}

template<typename T>std::string binary_str(T n)
{
    std::string t;
    while(n){
        t.push_back('0'+n%2);
        n/=2;
    }
    std::reverse(t.begin(),t.end());
    return t;
}
