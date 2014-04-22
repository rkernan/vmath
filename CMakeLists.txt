cmake_minimum_required(VERSION 2.8)
project(autodog_math)

# minimum compiler versions
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.3")
		message(FATAL_ERROR "Requires clang version > 3.3")
	endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.1")
		message(FATAL_ERROR "Requires gcc version > 4.8.1")
	endif()
else()
	message(SEND_ERROR "Unrecognized compiler.")
endif()

include_directories(inc)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Winline -g -DDEBUG")

set(MATH_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(MATH_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_subdirectory(${MATH_TEST_DIR})
