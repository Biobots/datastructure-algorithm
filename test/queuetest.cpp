#include <queue.h>
#include <test.h>

TEST_CASE("queue function test", "[Queue]")
{
    SECTION("sequence queue test")
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

    SECTION("stack-based queue test")
    {
        StackQueue<int> queue;
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
}