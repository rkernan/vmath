cmake_minimum_required(VERSION 2.8)
project(autodog_math)

include_directories(inc)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Winline")

add_executable(autodog_math
	src/main.cpp
	)
