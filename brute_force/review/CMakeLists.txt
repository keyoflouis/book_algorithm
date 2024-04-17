
cmake_minimum_required(VERSION 3.22.1)

project(review)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/sort.cpp)

add_library(review_lib ${source})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})