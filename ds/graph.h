#ifndef GRAPH_H
#define GRAPH_H

#include <common.h>
#include <stateMachine.h>

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
        for (int i = 0; i < size; i++)
        {
            if (vertex[i] == val) return i;
        }
        vertex[size++] = val;
        return size - 1;
    }
    void deleteVertex(T val)
    {
        int index = getIndex(val);
        if (index == INDEX_ERROR) return;
        size--;
        for (int i = index; i < size; i++)
        {
            vertex[i] = vertex[i + 1];
        }
        for (int i = index; i < size; i++)
        {
            edge[i] = edge[i + 1];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = index; j < size; j++)
            {
                edge[i][j] = edge[i][j + 1];
            }
        }
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
    void deleteEdge(T v1, T v2)
    {
        int i1 = getIndex(v1);
        int i2 = getIndex(v2);
        if (i1 == INDEX_ERROR || i2 == INDEX_ERROR) return;
        edge[i1][i2] = 0;
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

template <typename T, typename U=int>
struct Vertex;
template <typename T, typename U=int>
struct Edge;

template <typename T, typename U>
struct Vertex
{
    Edge<T, U>* eNode = nullptr;
    T data;
    Vertex() {}
    Vertex(T val)
    {
        data = val;
    }
    void releaseEdge()
    {
        Edge<T, U>* cur = eNode;
        Edge<T, U>* tmp;
        while (cur)
        {
            tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    void appendEdge(T val, U w=1)
    {
        if (val == data) return;
        Edge<T, U>* ptr = eNode;
        Edge<T, U>* pre = ptr;
        if (eNode == nullptr)
        {
            eNode = new Edge<T, U>(val, w);
            return;
        }
        while (ptr)
        {
            if (ptr->data == val) // val exist
            {
                ptr->weight = w; // just update weight
                return;
            }
            pre = ptr;
            ptr = ptr->next;
        }
        Edge<T, U>* cur = new Edge<T, U>(val, w);
        pre->next = cur;
    }
    U getEdge(T val)
    {
        if (val == data) throw new std::invalid_argument("same args");
        Edge<T, U>* ptr = eNode;
        while (ptr)
        {
            if (ptr->data == val)
            {
                return ptr->weight;
            }
            ptr = ptr->next;
        }
        throw new std::invalid_argument("arg(s) not in graph");
    }
};

template <typename T, typename U>
struct Edge
{
    T data;
    U weight=0;
    Edge<T, U>* next;
    Edge(T val, U w=1)
    {
        data = val;
        weight = w;
        next = nullptr;
    }
};

template <typename T, typename U=int>
class LinkedGraph // directed!!!
{
    typedef typename std::enable_if<std::is_arithmetic<U>::value, U>::type WeightType;
private:
    Vertex<T, WeightType>* vertList;
    size_t size = 0;
    size_t max;
    bool directed;
public:
    LinkedGraph(size_t maxSize)
    {
        vertList = new Vertex<T, WeightType>[maxSize];
        max = maxSize;
    }
    ~LinkedGraph()
    {
        if (vertList != nullptr)
        {
            for (int i = 0; i < size; i++)
            {
                vertList[i].releaseEdge();
            }
        }
        if (vertList != nullptr) delete[] vertList; vertList = nullptr;
    }
    size_t getSize()
    {
        return size;
    }
    int getIndex(T val)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (vertList[i].data == val) return i;
        }
        return INDEX_ERROR;
    }
    T getVertex(size_t index)
    {
        if (index >= size) throw new std::overflow_error("graph overflow");
        return vertList[index].data;
    }
    size_t insertVertex(T val)
    {
        if (size >= max) throw new std::overflow_error("graph overflow");
        for (int i = 0; i < size; i++)
        {
            if (vertList[i].data == val) return i;
        }
        Vertex<T, WeightType> vert(val);
        vertList[size++] = vert;
        return size - 1;
    }
    void insertEdge(T v1, T v2, WeightType w, bool autoAdd=false)
    {
        int i1 = getIndex(v1);
        int i2 = getIndex(v2);
        if (i1 != INDEX_ERROR && i2 != INDEX_ERROR)
        {
            vertList[i1].appendEdge(v2, w);
        }
        else if (autoAdd)
        {
            i1 = i1 == INDEX_ERROR ? insertVertex(v1) : i1;
            i2 = i2 == INDEX_ERROR ? insertVertex(v2) : i2;
            vertList[i1].appendEdge(v2, w);
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
        return vertList[i1].getEdge(v2);
    }
};

#endif