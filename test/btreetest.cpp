#include <binarytree.h>
#include <test.h>

TEST_CASE("binarytree seq to linkedlist test", "[SeqBTree]")
{
    SeqBTree<int>* tree = new SeqBTree<int>(5);
	size_t size = tree->getSize();

    REQUIRE(size == pow(2, 5) - 1);

    for (int i = 0; i < size - 1; i++)
	{
		tree->setValue(i, i);
	}
	BTNode<int>* t = tree->turnLinkedList();

    REQUIRE(t->left->left->data == 3);
}