cmake_minimum_required(VERSION 3.22.1)

project(brute_force)

option(REVIEW "review or implementation" OFF)

add_executable (${PROJECT_NAME}  ./test.cpp)

if(REVIEW)
    message("")
    message("/////////////////////////////")
    message("//   这是复习模式.")
    message("")
    add_subdirectory(review)
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/review)
    target_link_libraries(${PROJECT_NAME} PUBLIC review_lib)
else()
    message("")
    message("//////////////////////////////////////")
    message("//    这是实现.")
    message("")
    add_subdirectory(implementation)
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/implemention)
    target_link_libraries(${PROJECT_NAME} PUBLIC implementation_lib)
endif()


