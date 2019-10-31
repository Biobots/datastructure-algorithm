#include <queue.h>
#include <test.h>

TEST_CASE("queue function test", "[SeqQueue]")
{
    SeqQueue<int> queue(10);

    REQUIRE(queue.isEmpty() == true);

    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(i);
        REQUIRE(queue.getFront() == 0);
    }

    REQUIRE(queue.isEmpty() == false);

    for (int i = 0; i < 10; i++)
    {
        REQUIRE(queue.dequeue() == i);
    }

    REQUIRE(queue.isEmpty() == true);
}