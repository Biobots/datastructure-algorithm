#include <binarytree.h>
#include <test.h>

TEST_CASE("binarytree test", "[SeqBTree]")
{
    SeqBTree<int>* tree = new SeqBTree<int>(5);
	size_t size = tree->getSize();

    for (int i = 0; i < size - 1; i++)
	{
		tree->setValue(i, i);
	}
	BTNode<int>* tr = tree->turnLinkedList();

    SECTION("basic")
    {
        REQUIRE(size == pow(2, 5) - 1);
        REQUIRE(tr->left->left->data == 3);
    }
    
    SECTION("traverse DLR")
    {
        DLRiter<int> dlr(tr);
        REQUIRE(dlr.cur()->data == 0);
        dlr.next();
        REQUIRE(dlr.cur()->data == 1);
        dlr.next();
        REQUIRE(dlr.cur()->data == 3);
        dlr.next();
        REQUIRE(dlr.cur()->data == 7);
        dlr.next();
        REQUIRE(dlr.cur()->data == 15);
        dlr.next();
        REQUIRE(dlr.cur()->data == 16);
        for (int i = 1; i < 27; i++) { dlr.next();}
        REQUIRE(!dlr.cur());
    }

    SECTION("traverse LDR")
    {
        LDRiter<int> ldr(tr);
        REQUIRE(ldr.cur()->data == 15);
        ldr.next();
        REQUIRE(ldr.cur()->data == 7);
        ldr.next();
        REQUIRE(ldr.cur()->data == 16);
        ldr.next();
        REQUIRE(ldr.cur()->data == 3);
        ldr.next();
        REQUIRE(ldr.cur()->data == 17);
        ldr.next();
        REQUIRE(ldr.cur()->data == 8);
        for (int i = 1; i < 27; i++) { ldr.next();}
        REQUIRE(!ldr.cur());
    }

    SECTION("traverse LRD")
    {
        LRDiter<int> lrd(tr);
        REQUIRE(lrd.cur()->data == 15);
        lrd.next();
        REQUIRE(lrd.cur()->data == 16);
        lrd.next();
        REQUIRE(lrd.cur()->data == 7);
        lrd.next();
        REQUIRE(lrd.cur()->data == 17);
        lrd.next();
        REQUIRE(lrd.cur()->data == 18);
        lrd.next();
        REQUIRE(lrd.cur()->data == 8);
        lrd.next();
        REQUIRE(lrd.cur()->data == 3);
        for (int i = 1; i < 26; i++) { lrd.next();}
        REQUIRE(!lrd.cur());
    }
}