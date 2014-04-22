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

# source files
set(SOURCES
	inc/math/func.hpp
	inc/math/func.inl
	inc/math/types.hpp
	inc/math/core/vector.hpp
	inc/math/core/vector.inl
	inc/math/core/swizzle/swizzle.hpp
	inc/math/core/swizzle/swizzle2.hpp
	inc/math/core/swizzle/swizzle2.inl
	inc/math/core/swizzle/swizzle3.hpp
	inc/math/core/swizzle/swizzle3.hpp
	inc/math/core/swizzle/swizzle4.inl
	inc/math/core/swizzle/swizzle4.inl
	)

# test files
set(SOURCES_TEST
	test/test_runner.cpp
	test/math/func_unit.cpp
	test/math/matrix2x2_unit.cpp
	test/math/matrix2x3_unit.cpp
	test/math/matrix2x4_unit.cpp
	test/math/matrix3x2_unit.cpp
	test/math/matrix3x3_unit.cpp
	test/math/matrix3x4_unit.cpp
	test/math/matrix4x2_unit.cpp
	test/math/matrix4x3_unit.cpp
	test/math/matrix4x4_unit.cpp
	test/math/quaternion_unit.cpp
	test/math/swizzle2_unit.cpp
	test/math/swizzle3_unit.cpp
	test/math/swizzle4_unit.cpp
	test/math/vector2_unit.cpp
	test/math/vector3_unit.cpp
	test/math/vector4_unit.cpp
	)

add_executable(test_suite
	${SOURCES}
	${SOURCES_TEST}
	)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(test_suite ${Boost_LIBRARIES})

enable_testing()
add_test(TestSuite test_suite)
