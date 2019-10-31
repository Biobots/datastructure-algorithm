#ifndef GRAPH_H
#define GRAPH_H

#include <common.h>

template <typename T, typename U=int>
class MatrixGraph
{
    typedef typename std::enable_if<std::is_arithmetic<U>::value, U>::type WeightType;
private:
    T* vertex;
    WeightType** edge;
    size_t size = 0;
    size_t max;
    bool directed;
    inline void _insertEdge(int v1, int v2, WeightType w)
    {
        edge[v1][v2] = w;
        if (!directed) edge[v2][v1] = w;
    }
public:
    MatrixGraph(size_t maxSize, bool isDirected=false)
    {
        vertex = new T[maxSize];
        edge = new WeightType*[maxSize];
        for (size_t i = 0; i < maxSize; i++)
        {
            edge[i] = new WeightType[maxSize];
        }
        for (size_t i = 0; i < maxSize; i++)
        {
            for (size_t j = 0; j < maxSize; j++)
            {
                edge[i][j] = 0;
            }
        }
        max = maxSize;
        directed = isDirected;
    }
    ~MatrixGraph()
    {
        for (size_t i = 0; i < size; i++)
        {
            if (edge[i] != nullptr) delete[] edge[i]; edge[i] = nullptr;
        }
        if (edge != nullptr) delete[] edge; edge = nullptr;
        if (vertex != nullptr) delete[] vertex; vertex = nullptr;
    }
    size_t insertVertex(T val)
    {
        if (size >= max) throw new std::overflow_error("graph overflow");
        vertex[size++] = val;
        return size - 1;
    }
    size_t getSize()
    {
        return size;
    }
    int getIndex(T val)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (vertex[i] == val) return i;
        }
        return INDEX_ERROR;
    }
    T getVertex(size_t index)
    {
        if (index >= size) throw new std::overflow_error("graph overflow");
        return vertex[index];
    }
    void insertEdge(T v1, T v2, WeightType w, bool autoAdd=false)
    {
        int i1 = getIndex(v1);
        int i2 = getIndex(v2);
        if (i1 != INDEX_ERROR && i2 != INDEX_ERROR)
        {
            _insertEdge(i1, i2, w);
        }
        else if (autoAdd)
        {
            i1 = i1 == INDEX_ERROR ? insertVertex(v1) : i1;
            i2 = i2 == INDEX_ERROR ? insertVertex(v2) : i2;
            _insertEdge(i1, i2, w);
        }
        else
        {
            throw new std::invalid_argument("arg(s) not in graph");
        }
    }
    WeightType getEdge(T v1, T v2)
    {
        int i1 = getIndex(v1);
        int i2 = getIndex(v2);
        if (i1 == INDEX_ERROR || i2 == INDEX_ERROR) throw new std::invalid_argument("arg(s) not in graph");
        return edge[i1][i2];
    }
    bool isDirected()
    {
        return directed;
    }
};

class LinkedGraph
{

};

#endif