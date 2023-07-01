cmake_minimum_required(VERSION 3.2.0)
project(CPP CXX)

set(CMAKE_C_COMPILER "which gcc")
set(CMAKE_CXX_COMPILE_FEATURES "which g++")
set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR}/)

add_subdirectory(src)