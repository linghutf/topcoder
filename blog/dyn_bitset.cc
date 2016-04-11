/*
 * dyn_bitset.cc
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "dyn_bitset.h"
 */

#include <iostream>
// #include <string>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <memory>
// #include <thread>
#include <boost/dynamic_bitset.hpp>

using namespace std;

typedef boost::dynamic_bitset<> BitMap;

int main(int argc,char const *argv[])
{
    unsigned int maxn = UINT_MAX;
    boost::dynamic_bitset<> bitmap(maxn);
    bitmap.set(1,1);
//bitmap.reset();
    //long a =2<<32-1;
    //bitmap
    //cout<<UINT_MAX<<","<<(2<<32-1)<<endl;//2<<32
    cout<<bitmap.size()<<endl;
    for(auto i=0;i<bitmap.size();++i)
        if(bitmap[i])
            cout<<i<<endl;
    //cout<<bitmap.to_ulong()<<endl;
    return 0;
}
