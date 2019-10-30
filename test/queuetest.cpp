#include <iostream>

#include <queue.h>

int main()
{
    SeqQueue<int> queue(10);
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(i);
    }
    std::cout << queue.getFront() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << queue.dequeue() << std::endl;
    }
    return 0;
}