#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("枚举类型值define兼容测试","[enum]"){
    enum Test{
        SEND_META = -1,
        SEND_DATA = -2,
        DEL_DATA = 3
    };
    REQUIRE((int)SEND_META == -1);

    REQUIRE((int)SEND_DATA == -2);
}
