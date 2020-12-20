cmake_minimum_required(VERSION 3.17)
project(Book)

set(CMAKE_CXX_STANDARD 14)

add_executable(Book main.cpp BookOp.h BookData.h)