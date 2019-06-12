cmake_minimum_required(VERSION 2.8)

project(goodle_test)


set(SOURSE 
	src/test_g.cpp
)

add_executable(test_g ${SOURSE})

target_link_libraries(test_g PUBLIC gtest)
target_link_libraries(test_g PUBLIC static_lib)
target_link_libraries(test_g PUBLIC sort_dll)