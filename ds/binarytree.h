#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <common.h>
#include <math.h>
#include <queue.h>
#include <stack.h>

template <typename T>
class BTNode;

template <typename T>
class BaseTIterator
{
public:
    virtual BTNode<T>* next() = 0;
    virtual BTNode<T>* cur() = 0;
};

template <typename T>
class DLRiter : public BaseTIterator<T>
{
private:
    SeqStack<BTNode<T>*> pStack;
public:
    DLRiter(BTNode<T>* node)
    {
        pStack.push(node);
    }
    ~DLRiter()
    {
        
    }
    virtual BTNode<T>* next()
    {
        try
        {
            BTNode<T>* cur = pStack.pop();
            if (cur->right != nullptr) pStack.push(cur->right);
            if (cur->left != nullptr) pStack.push(cur->left);
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
    virtual BTNode<T>* cur()
    {
        try
        {
            BTNode<T>* cur = pStack.getTop();
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
};

template <typename T>
class LDRiter : public BaseTIterator<T>
{
private:
    SeqStack<BTNode<T>*> pStack;
public:
    LDRiter(BTNode<T>* node)
    {
        BTNode<T>* cur = node;
        while (cur->left)
        {
            pStack.push(cur);
            cur = cur->left;
        }
        pStack.push(cur);
    }
    ~LDRiter()
    {
        
    }
    virtual BTNode<T>* next()
    {
        try
        {
            BTNode<T>* cur = pStack.pop();
            if (cur->right != nullptr) 
            {
                BTNode<T>* tmp = cur->right;
                pStack.push(tmp);
                while (tmp->left)
                {
                    tmp = tmp->left;
                    pStack.push(tmp);
                }
            }
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
    virtual BTNode<T>* cur()
    {
        try
        {
            BTNode<T>* cur = pStack.getTop();
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
};

template <typename T>
class LRDiter : public BaseTIterator<T>
{
private:
    SeqStack<BTNode<T>*> pStack;
public:
    LRDiter(BTNode<T>* node)
    {
        BTNode<T>* cur = node;
        while (cur->left)
        {
            pStack.push(cur);
            cur = cur->left;
        }
        pStack.push(cur);
    }
    ~LRDiter()
    {
        
    }
    virtual BTNode<T>* next()
    {
        try
        {
            BTNode<T>* cur = pStack.pop();
            BTNode<T>* pre = pStack.getTop();
            if (pre->right != nullptr && pre->right != cur) 
            {
                BTNode<T>* tmp = pre->right;
                pStack.push(tmp);
                while (tmp->left)
                {
                    tmp = tmp->left;
                    pStack.push(tmp);
                }
            }
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
    virtual BTNode<T>* cur()
    {
        try
        {
            BTNode<T>* cur = pStack.getTop();
            return cur;
        }
        catch(...)
        {
            return nullptr;
        }
    }
};

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
	void setValue(size_t index, T val)
	{
		data[index] = val;
	}
    T getValue(size_t index)
    {
        return data[index];
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
    BTNode<T>* turnLinkedList(T skipFlag) // ensure connection
    {
        if (data[0] == skipFlag) return nullptr;
        BTNode<T>* head = new BTNode<T>();
		SeqQueue<BTNode<T>*> nodes(size);
		nodes.enqueue(head);
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == skipFlag) continue;
            BTNode<T>* ptr = nodes.dequeue();
			ptr->data = data[i];
            if (2 * i + 1 <= size - 1 && data[2 * i + 1] != skipFlag)
            {
                BTNode<T>* left = new BTNode<T>();
				ptr->left = left;
				nodes.enqueue(left);
            }
            if (2 * i + 2 <= size - 1 && data[2 * i + 2] != skipFlag)
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

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T>* child;
    TreeNode<T>* next;
    TreeNode()
    {
        child = nullptr;
        next = nullptr;
    }
    TreeNode(T val)
    {
        data = val;
        child = nullptr;
        next = nullptr;
    }
    ~TreeNode()
    {

    }
    static BTNode<T>* turnBinaryTree(TreeNode<T>* node)
    {
        SeqQueue<TreeNode<T>*> qtree(100);
        SeqQueue<BTNode<T>*> qbinary(100);
        TreeNode<T>* ptr;
        BTNode<T>* head = new BTNode<T>(node->data);
        BTNode<T>* pre = head;
        BTNode<T>* cur;
        qtree.enqueue(node);
        qbinary.enqueue(head);
        while(!qtree.isEmpty())
        {
            ptr = qtree.dequeue();
            pre = qbinary.dequeue();
            if (ptr->child != nullptr)
            {
                ptr = ptr->child;
                cur = new BTNode<T>(ptr->data);
                pre->left = cur;
                qtree.enqueue(ptr);
                qbinary.enqueue(cur);
                pre = cur;
                while (ptr->next != nullptr)
                {
                    ptr = ptr->next;
                    cur = new BTNode<T>(ptr->data);
                    pre->right = cur;
                    pre = cur;
                    qtree.enqueue(ptr);
                    qbinary.enqueue(cur);
                }
            }
        }
        return head;
    }
};

template <typename T>
class Forest
{
public:
    TreeNode<T>* trees;
    size_t size;
    Forest(size_t inputSize)
    {
        size = inputSize;
        trees = new TreeNode<T>[size];
    }
    ~Forest()
    {
        if (trees != nullptr) delete[] trees; trees = nullptr;
    }
    static BTNode<T>* turnBinaryTree(Forest<T>* forest)
    {
        size_t size = forest->size;
        BTNode<T>* bts[size];
        for (int i = 0; i < size; i++)
        {
            bts[i] = TreeNode<T>::turnBinaryTree(&forest->trees[i]);
        }
        //TODO
        return nullptr;
    }
};

#endif // !BINARY_TREE_H