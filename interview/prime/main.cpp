#include <iostream>
#include <algorithm>
#include <cstdlib>

//#include "prime.h"

void GetPrimes(std::vector<uint_fast64_t> &vec,uint_fast64_t maxNum)
{
    vec.clear();
    if(maxNum<2)
        return;
    vec.resize(maxNum);
    std::vector<bool> prime(true,maxNum);
    prime[0]=prime[1]=false;

    vec.push_back(2);
    for(uint_fast64_t i =3;i<maxNum;i+=2)
    {
        if(prime[i]){
            vec.push_back(i);
            for(uint_fast64_t k=i*i;k<maxNum;k+=i)
                prime[k]=false;
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc<2){
        std::cout<<argv[0]<<" maxnum."<<std::endl;
        return -1;
    }
    uint_fast64_t n = std::atoll(argv[1]);

    std::vector<uint_fast64_t> v;
    GetPrimes(v,n);
    std::for_each(v.begin(),v.end(),[](uint_fast64_t n){std::cout<<n<<'\t';});
    std::cout<<std::endl;
    return 0;
}
