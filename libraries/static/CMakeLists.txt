cmake_minimum_required(VERSION 2.8)
project(static_lib)
set(cpp_fiels
	static_lib.cpp
	)

set(hpp_fiels
	static_lib.hpp
	)

add_library(static_lib STATIC ${cpp_fiels} ${hpp_fiels})