cmake_minimum_required (VERSION 2.6)

project(ds)

include_directories(ds)
aux_source_directory(test DIR_SRCS)

add_executable(main ${DIR_SRCS})