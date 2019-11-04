#include <sort.h>
#include <test.h>

TEST_CASE("sort test", "[Sort]")
{
    SECTION("quick sort")
    {
        int arr[10];
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 10 - i;
        }
        quickSort(arr, 10);
        for (int i = 0; i < 10; i++)
        {
            REQUIRE(arr[i] == i + 1);
        }
    }
}