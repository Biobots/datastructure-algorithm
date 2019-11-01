#include <graph.h>
#include <test.h>

TEST_CASE("graph test", "[Graph]")
{
    SECTION("Type trait test")
    {
        //compilation should fail
        //MatrixGraph<int, MatrixGraph<int>> graph(20);
    }

    SECTION("Matrix Graph")
    {
        MatrixGraph<int> graph(20);
        graph.insertVertex(1);
        graph.insertVertex(2);
        REQUIRE(graph.getSize() == 2);
        graph.insertEdge(1, 2, 1);
        REQUIRE(graph.getEdge(1, 2) == 1);
        graph.insertEdge(1, 3, 2, true);
        REQUIRE(graph.getSize() == 3);
        REQUIRE(graph.getEdge(1, 3) == 2);
    }

    SECTION("Linked Graph")
    {
        LinkedGraph<int> graph(20);
        REQUIRE(graph.insertVertex(1) == 0);
        REQUIRE(graph.insertVertex(2) == 1);
        REQUIRE(graph.getIndex(1) == 0);
        REQUIRE(graph.getIndex(2) == 1);
        REQUIRE(graph.getSize() == 2);
        graph.insertEdge(1, 2, 1);
        REQUIRE(graph.getEdge(1, 2) == 1);
        graph.insertEdge(1, 3, 2, true);
        REQUIRE(graph.getSize() == 3);
        REQUIRE(graph.getEdge(1, 3) == 2);
    }
}