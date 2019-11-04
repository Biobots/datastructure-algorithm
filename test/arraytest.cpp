#include <dynamicarray.h>
#include <test.h>

TEST_CASE("array test", "[Array]")
{
    SECTION("init")
    {
        Array<int> arr(10);
        for (int i = 0; i < 10; i++)
        {
            arr[i] = i;
        }
        for (int i = 0; i < 10; i++)
        {
            REQUIRE(arr[i] == i);
        }
        arr[10] = 100;
        REQUIRE(arr[10] == 100);
    }
}