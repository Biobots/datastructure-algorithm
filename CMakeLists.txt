cmake_minimum_required (VERSION 2.6)

project(ds)

include_directories(ds)
#aux_source_directory(test DIR_SRCS)

add_executable(stack test/stacktest.cpp)
add_executable(queue test/queuetest.cpp)
add_executable(btree test/btreetest.cpp)
add_executable(graph test/graphtest.cpp)
add_executable(array test/arraytest.cpp)

SET(CMAKE_INSTALL_PREFIX .)

enable_testing()
ADD_TEST(NAME QueueTests COMMAND queue -s)
ADD_TEST(NAME StackTests COMMAND stack -s)
ADD_TEST(NAME BinaryTreeTests COMMAND btree -s)
ADD_TEST(NAME GraphTests COMMAND graph -s)
ADD_TEST(NAME ArrayTests COMMAND array -s)

install(TARGETS queue stack btree graph array
        RUNTIME DESTINATION bin)