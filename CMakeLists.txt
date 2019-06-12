cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT") 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_subdirectory(googletest/)
add_subdirectory(gtest/)
add_subdirectory(libraries/)
