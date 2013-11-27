cmake_minimum_required(VERSION 2.8)
project(autodog_math)

# require clang 3.3+
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.3")
		message(FATAL_ERROR "Requires clang version > 3.3")
	endif()
else()
	message(FATAL_ERROR "Requires clang")
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
	inc/math/tuple/axis_angle.hpp
	inc/math/tuple/axis_angle.inl
	inc/math/tuple/euler.hpp
	inc/math/tuple/euler.inl
	)

# test files
set(SOURCES_TEST
	test/math_tester.cpp
	test/math/func_unit.cpp
	test/math/quaternion_unit.cpp
	test/math/vector2_unit.cpp
	test/math/vector2_swizzle_unit.cpp
	test/math/vector3_unit.cpp
	test/math/vector3_swizzle_unit.cpp
	test/math/vector4_unit.cpp
	test/math/vector4_swizzle_unit.cpp
	)

add_executable(math_tester
	${SOURCES}
	${SOURCES_TEST}
	)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(math_tester ${Boost_LIBRARIES})
