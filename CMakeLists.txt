cmake_minimum_required (VERSION 2.6)

project(ds)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories(external/rxcpp/Rx/v2/src)
include_directories(external/catch2)
include_directories(misc)
include_directories(ds)
include_directories(algo)
include_directories(pattern/stateMachine)
#aux_source_directory(test DIR_SRCS)

add_executable(stack test/stacktest.cpp)
add_executable(queue test/queuetest.cpp)
add_executable(btree test/btreetest.cpp)
add_executable(graph test/graphtest.cpp)
add_executable(array test/arraytest.cpp)
add_executable(sort test/sorttest.cpp)

SET(CMAKE_INSTALL_PREFIX .)

enable_testing()
ADD_TEST(NAME QueueTests COMMAND queue -s)
ADD_TEST(NAME StackTests COMMAND stack -s)
ADD_TEST(NAME BinaryTreeTests COMMAND btree -s)
ADD_TEST(NAME GraphTests COMMAND graph -s)
ADD_TEST(NAME ArrayTests COMMAND array -s)
ADD_TEST(NAME SortTests COMMAND sort -s)

install(TARGETS queue stack btree graph array sort
        RUNTIME DESTINATION bin)