
cmake_minimum_required(VERSION 3.22.1)

project(implemention)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/sort.cpp)

add_library(implemention_lib ${source})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})