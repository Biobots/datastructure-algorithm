#ifndef SORT_H
#define SORT_H

#include <common.h>
#include <stack.h>

template <typename T>
void quickSortProcess(T* data, int lo, int hi)
{
    if (lo >= hi) return;
    T store = data[lo];
    int lptr = lo;
    int hptr = hi;
    while (lptr < hptr)
    {
        while (data[hptr] >= store && hptr > lptr) hptr--;
        if (hptr > lptr)
        {
            data[lptr] = data[hptr];
            lptr++;
        }
        while (data[lptr] < store && hptr > lptr) lptr++;
        if (hptr > lptr)
        {
            data[hptr] = data[lptr];
            hptr--;
        }
    }
    data[lptr] = store;
    quickSortProcess(data, lo, lptr - 1);
    quickSortProcess(data, hptr + 1, hi);
}

template <typename T>
void quickSort(T* data, size_t size)
{
    if (size <= 1) return;
    size_t lo = 0;
    size_t hi = size - 1;
    quickSortProcess(data, lo, hi);
}

#include <tuple>
template <typename T>
void quickSortStack(T* data, size_t size)
{
    typedef std::tuple<int, int> U;
    if (size <= 1) return;
    SeqStack<U> stack(size);
    stack.push(U(0, size - 1));
    while (!stack.isEmpty())
    {
        U cur = stack.pop();
        int lo = std::get<0>(cur);
        int hi = std::get<1>(cur);
        if (lo >= hi) continue;
        T store = data[lo];
        int lptr = lo;
        int hptr = hi;
        while (lptr < hptr)
        {
            while (data[hptr] >= store && hptr > lptr) hptr--;
            if (hptr > lptr)
            {
                data[lptr] = data[hptr];
                lptr++;
            }
            while (data[lptr] < store && hptr > lptr) lptr++;
            if (hptr > lptr)
            {
                data[hptr] = data[lptr];
                hptr--;
            }
        }
        data[lptr] = store;
        stack.push(U(lo, lptr - 1));
        stack.push(U(hptr + 1, hi));
    }
}

#endif