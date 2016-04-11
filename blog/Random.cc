/**
 * 生成1000W随机数
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

#include <chrono>
#include <random>

using namespace std;

int main()
{
    int n = 10000000;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    FILE *fp = fopen("data","w+");
    for(int i=0;i<n;++i){
        fprintf(fp,"%12lu",generator()%n+1);
    }
    fclose(fp);
    return 0;
}
