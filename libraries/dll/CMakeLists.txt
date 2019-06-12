cmake_minimum_required(VERSION 2.8)
project(sort_dll_lib)
set(cpp_fils
	sort_dll.cpp
	)

set(hpp_fils
	sort_dll.hpp
	)

add_library(sort_dll SHARED ${cpp_fils} ${hpp_fils})