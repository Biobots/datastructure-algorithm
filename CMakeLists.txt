cmake_minimum_required (VERSION 2.6)

project(ds)

include_directories(ds)
#aux_source_directory(test DIR_SRCS)

add_executable(stack test/stacktest.cpp)
add_executable(queue test/queuetest.cpp)
add_executable(btree test/btreetest.cpp)

SET(CMAKE_INSTALL_PREFIX .)

install(TARGETS queue stack btree
        RUNTIME DESTINATION bin)