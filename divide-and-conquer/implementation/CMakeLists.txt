
cmake_minimum_required(VERSION 3.22.1)

project(implementation)

file(GLOB source "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )
file(GLOB header "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(implementation_lib ${source} ${header})