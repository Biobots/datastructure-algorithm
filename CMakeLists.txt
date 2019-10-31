cmake_minimum_required (VERSION 2.6)

project(ds)

include_directories(ds)
#aux_source_directory(test DIR_SRCS)

add_executable(stack test/stacktest.cpp)
add_executable(queue test/queuetest.cpp)
add_executable(btree test/btreetest.cpp)

SET(CMAKE_INSTALL_PREFIX .)

enable_testing()
ADD_TEST(NAME QueueTests COMMAND queue -s)
ADD_TEST(NAME StackTests COMMAND stack -s)
ADD_TEST(NAME BinaryTreeTests COMMAND btree -s)

install(TARGETS queue stack btree
        RUNTIME DESTINATION bin)