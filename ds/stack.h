#ifndef STACK_H
#define STACK_H

#include <common.h>

#define SEQSTACKMAXSIZE 500

template <typename T>
class SeqStack
{
private:
    T* data;
    int top;
    size_t size;

public:
    SeqStack(size_t stackSize)
    {
        data = new T[stackSize];
        top = -1;
        size = stackSize;
    }
    SeqStack()
    {
        data = new T[SEQSTACKMAXSIZE];
        top = -1;
        size = SEQSTACKMAXSIZE;
    }
    ~SeqStack()
    {
        if (data != nullptr) delete[] data; data = nullptr;
    }

    T getTop()
    {
        if (top < 0) throw new std::underflow_error("stack underflow");
        if (top >= size) throw new std::overflow_error("stack overflow");
        return data[top];
    }

    T pop()
    {
        if (top < 0) throw new std::underflow_error("stack underflow");
        if (top >= size) throw new std::overflow_error("stack overflow");
        return data[top--];
    }

    void push(T val)
    {
        if (top == size - 1) throw new std::overflow_error("stack overflow");
        data[++top] = val;
    }

    bool isEmpty()
    {
        return top < 0 ? true : false;
    }
    
};


#endif
