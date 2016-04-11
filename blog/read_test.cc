/*
 * read_test.cc
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "read_test.h"
 */

#include <iostream>
// #include <string>
#include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <memory>
// #include <thread>

using namespace std;

int main(int argc,char const *argv[])
{
    FILE *fp = fopen("data","r");
    unsigned int a;
    for(int i=0;i<10;++i){
        fscanf(fp,"%u",&a);
        cout<<a<<endl;
    }
    fclose(fp);
    return 0;
}
