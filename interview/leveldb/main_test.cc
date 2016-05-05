#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char *argv[])
{
    //setup unit test
    int result = Catch::Session().run(argc,argv);
    //cleanup resource

    //return
    return result;
}

TEST_CASE("vectors can be sized and resized ","[vector]"){
    std::vector<int> v(5);

    REQUIRE(v.size()==5);
    REQUIRE(v.capacity()>=5);

    SECTION("resized larger test"){
        v.resize(10);

        REQUIRE(v.size()==10);
        REQUIRE(v.capacity()>=10);
    }

    SECTION("resized smaller test"){
        v.resize(2);

        REQUIRE(v.size()==2);
        REQUIRE(v.capacity()>=2);
    }
}
