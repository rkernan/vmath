cmake_minimum_required(VERSION 2.8)
project(autodog_math CXX)

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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Winline")

# include files
include_directories(inc)
set(INCLUDE_FILES
	inc/math/func.hpp
	inc/math/func.inl
	inc/math/types.hpp
	inc/math/core/matrix.hpp
	inc/math/core/matrix.inl
	inc/math/core/quaternion.hpp
	inc/math/core/quaternion.inl
	inc/math/core/vector.hpp
	inc/math/core/vector.inl
	inc/math/core/swizzle/swizzle.hpp
	inc/math/core/swizzle/swizzle2.hpp
	inc/math/core/swizzle/swizzle2.inl
	inc/math/core/swizzle/swizzle3.hpp
	inc/math/core/swizzle/swizzle3.inl
	inc/math/core/swizzle/swizzle4.hpp
	inc/math/core/swizzle/swizzle4.inl
	inc/math/core/swizzle/swizzle_gen.hpp
)

# unit test files
set(SOURCE_FILES_UNIT
	test/unit/func.cpp
	test/unit/matrix2x2.cpp
	test/unit/matrix2x3.cpp
	test/unit/matrix2x4.cpp
	test/unit/matrix3x2.cpp
	test/unit/matrix3x3.cpp
	test/unit/matrix3x4.cpp
	test/unit/matrix4x2.cpp
	test/unit/matrix4x3.cpp
	test/unit/matrix4x4.cpp
	test/unit/quaternion.cpp
	test/unit/swizzle2.cpp
	test/unit/swizzle3.cpp
	test/unit/swizzle4.cpp
	test/unit/vector2.cpp
	test/unit/vector3.cpp
	test/unit/vector4.cpp
)

add_executable(unit_tests
	test/test_runner.cpp
	${SOURCE_FILES_UNIT}
	${INCLUDE_FILES}
)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
target_link_libraries(unit_tests ${Boost_LIBRARIES})

enable_testing()
add_test(UnitTests unit_tests)
