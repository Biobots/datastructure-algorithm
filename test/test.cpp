#include <iostream>

#include <stack.h>

int main()
{
    SeqStack<int> stack(20);
    stack.push(10);
    stack.push(23);
    stack.push(9);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.getTop() << std::endl;
    return 0;
}