cmake_minimum_required(VERSION 3.14)
project(binary_tree)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(binary_tree
        inc/BinaryTree.h
        src/BinaryTreeTest.cpp)
