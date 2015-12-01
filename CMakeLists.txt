cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("vmath")

set(VMATH_VERSION_MAJOR "1")
set(VMATH_VERSION_MINOR "0")
set(VMATH_VERSION "${VMATH_VERSION_MAJOR}.${VMATH_VERSION_MINOR}")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake")

set(VMATH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${VMATH_INCLUDE_DIR})

set(INCDIR ${VMATH_INCLUDE_DIR})
set(HEADERS
	"${INCDIR}/vmath/functions.hpp"
	"${INCDIR}/vmath/functions.inl"
	"${INCDIR}/vmath/types.hpp"
	"${INCDIR}/vmath/core/matrix.hpp"
	"${INCDIR}/vmath/core/matrix.inl"
	"${INCDIR}/vmath/core/quaternion.hpp"
	"${INCDIR}/vmath/core/quaternion.inl"
	"${INCDIR}/vmath/core/vector.hpp"
	"${INCDIR}/vmath/core/vector.inl"
	"${INCDIR}/vmath/core/swizzle/swizzle.hpp"
	"${INCDIR}/vmath/core/swizzle/swizzle2.hpp"
	"${INCDIR}/vmath/core/swizzle/swizzle2.inl"
	"${INCDIR}/vmath/core/swizzle/swizzle3.hpp"
	"${INCDIR}/vmath/core/swizzle/swizzle3.inl"
	"${INCDIR}/vmath/core/swizzle/swizzle4.hpp"
	"${INCDIR}/vmath/core/swizzle/swizzle4.inl"
	"${INCDIR}/vmath/core/swizzle/swizzle_gen.hpp"
	)

if(VMATH_BUILD_DOC)
	add_subdirectory(doc)
endif()

if(VMATH_BUILD_TESTS)
	add_subdirectory(test)
endif()
