#include <iostream>

#include <binarytree.h>

int main()
{
    SeqBTree<int>* tree = new SeqBTree<int>(5);
	size_t size = tree->getSize();
    for (int i = 0; i < size - 1; i++)
	{
		tree->setValue(i, i);
	}
	BTNode<int>* t = tree->turnLinkedList();
    std::cout << t->left->left->data << std::endl;
    return 0;
}