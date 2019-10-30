#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <common.h>
#include <math.h>
#include <queue.h>

template <typename T>
class BTNode;

template <typename T>
class SeqBTree
{
private:
	T* data;
	size_t depth;
	size_t size;
public:
	SeqBTree(size_t depth)
	{
		this->depth = depth;
		size = std::pow(2, depth) - 1;
		data = new T[size];
	}
	SeqBTree(T* data, size_t size)
	{
		this->data = data;
		this->size = size;
		depth = std::log(size + 1) / std::log(2);
	}
	~SeqBTree()
	{
		if (data != nullptr) delete[] data; data = nullptr;
	}
	void setValue(T val, size_t index)
	{
		data[index] = val;
	}
	size_t getSize()
	{
		return size;
	}
	BTNode<T>* turnLinkedList()
	{
		BTNode<T>* head = new BTNode<T>();
		SeqQueue<BTNode<T>*> nodes(size);
		nodes.enqueue(head);
		for (size_t i = 0; i < size; i++)
		{
			BTNode<T>* ptr = nodes.dequeue();
			ptr->data = data[i];
			if (2 * i + 1 <= size - 1)
			{
				BTNode<T>* left = new BTNode<T>();
				ptr->left = left;
				nodes.enqueue(left);
			}
			if (2 * i + 2 <= size - 1)
			{
				BTNode<T>* right = new BTNode<T>();
				ptr->right = right;
				nodes.enqueue(right);
			}
		}
		return head;
	}
};

template <typename T>
class BTNode
{
public:
	BTNode()
	{
		left = nullptr;
		right = nullptr;
	}
	BTNode(T val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
	~BTNode()
	{

	}

	T data;
	BTNode<T>* left;
	BTNode<T>* right;

};

#endif // !BINARY_TREE_H