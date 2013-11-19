cmake_minimum_required(VERSION 2.8)
project(autodog_math)

include_directories(inc)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Winline -g -DDEBUG")

add_executable(math_tester
	# library includes
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
	# test files
	test/math_tester.cpp
	test/math/func_unit.cpp
	test/math/quaternion_unit.cpp
	test/math/vector2_unit.cpp
	test/math/vector3_unit.cpp
	test/math/vector4_unit.cpp
	)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(math_tester ${Boost_LIBRARIES})
