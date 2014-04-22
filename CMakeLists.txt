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

set(MATH_INC_DIR inc)

# unit test files
set(MATH_TEST_UNIT_SRC
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
	${MATH_TEST_UNIT_SRC}
	)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(unit_tests ${Boost_LIBRARIES})

enable_testing()
add_test(UnitTests unit_tests)
