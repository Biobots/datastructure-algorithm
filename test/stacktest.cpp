#include <stack.h>
#include <test.h>

TEST_CASE("stack function test", "[SeqStack]")
{
    SeqStack<int> stack(20);

    REQUIRE(stack.isEmpty() == true);

    stack.push(10);
    stack.push(23);
    stack.push(9);

    REQUIRE(stack.pop() == 9);
    REQUIRE(stack.getTop() == 23);
}