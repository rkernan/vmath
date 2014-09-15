cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("math")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake")

set(MATH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${MATH_INCLUDE_DIR})

set(INCDIR ${MATH_INCLUDE_DIR})
set(HEADERS
	"${INCDIR}/math/functions.hpp"
	"${INCDIR}/math/functions.inl"
	"${INCDIR}/math/types.hpp"
	"${INCDIR}/math/core/matrix.hpp"
	"${INCDIR}/math/core/matrix.inl"
	"${INCDIR}/math/core/quaternion.hpp"
	"${INCDIR}/math/core/quaternion.inl"
	"${INCDIR}/math/core/vector.hpp"
	"${INCDIR}/math/core/vector.inl"
	"${INCDIR}/math/core/swizzle/swizzle.hpp"
	"${INCDIR}/math/core/swizzle/swizzle2.hpp"
	"${INCDIR}/math/core/swizzle/swizzle2.inl"
	"${INCDIR}/math/core/swizzle/swizzle3.hpp"
	"${INCDIR}/math/core/swizzle/swizzle3.inl"
	"${INCDIR}/math/core/swizzle/swizzle4.hpp"
	"${INCDIR}/math/core/swizzle/swizzle4.inl"
	"${INCDIR}/math/core/swizzle/swizzle_gen.hpp"
	)

if(MATH_BUILD_DOC)
	add_subdirectory(doc)
endif()

if(MATH_BUILD_TESTS)
	add_subdirectory(test)
endif()
