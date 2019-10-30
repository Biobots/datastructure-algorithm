#ifndef QUEUE_H
#define QUEUE_H

#include <common.h>

template <typename T>
class SeqQueue
{
private:
    T* data;
    uint front;
    uint rear;
    size_t size;
public:
    SeqQueue(size_t queueSize)
    {
        data = new T[queueSize + 1];
        front = 0;
        rear = front;
        size = queueSize + 1;
    }
    ~SeqQueue()
    {
        if (data != nullptr) delete[] data; data = nullptr;
    }

    void enqueue(T val)
    {
        if ((rear + 1) % size == front) throw new std::overflow_error("queue overflow");
        rear = (rear + 1) % size;
        data[rear] = val;
    }

    T dequeue()
    {
        if (rear % size == front) throw new std::underflow_error("queue underflow");
        front = (front + 1) % size;
        return data[front];
    }

    bool isEmpty()
    {
        return (rear % size == front) ? true : false; 
    }

    T getFront()
    {
        if (rear % size == front) throw new std::underflow_error("queue underflow");
        return data[(front + 1) % size];
    }
};

#endif