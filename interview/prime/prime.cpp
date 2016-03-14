#include "prime.h"

void GetPrimes(std::vector<uint_fast64_t> *vec,uint_fast64_t maxNum)
{
    if(vec==nullptr)
        return;
    vec->clear();

    std::vector<uint_fast64_t> isNotPrime(1,maxNum);
    //isNotPrime.push_back(1);
    //isNotPrime.push_back(1);
    uint_fast64_t i,j;
    for(i = 2;i<maxNum;++i){
        if(!isNotPrime[i])
            vec->push_back(i);
        for(j=0;j<vec->size() && (i*vec->at(j)<maxNum);++j){
            isNotPrime[i*vec->at(j)] = 1;
            if(!(i%vec->at(j)))
                break;
        }
    }
 //   return *vec;
}
