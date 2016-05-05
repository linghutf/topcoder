#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <cmath>
double m_sqrt(unsigned int n)
{
    if(n==0) return 0;
    double m = 1.0;
    for(int i=0;i<5;++i){
        m = (m+n/m)/2;
    }
    return m;
}

TEST_CASE("Sqrt are computed.","[sqrt]"){
    unsigned int a[]={0,1,2,3};
    int nums = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<nums;++i){
        REQUIRE(m_sqrt(a[i])-::sqrt(a[i])<1e-9);
    }
    INFO("sqrt(3):" << m_sqrt(3));
}
