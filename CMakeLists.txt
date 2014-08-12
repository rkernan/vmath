cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("math")

enable_testing()

option(BUILD_DOCUMENTATION "Build HTML documentation using Doxygen." ON)

if(BUILD_DOCUMENTATION)
	find_package(Doxygen)
	if(NOT DOXYGEN_FOUND)
		message(FATAL_ERROR "Doxygen not found. Required to build documentation.")
	endif()

	set(DOXYFILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
	set(DOXYFILE "${PROJECT_BINARY_DIR}/Doxyfile")
	set(DOXYGEN_OUTPUT_DIR "${PROJECT_BINARY_DIR}/doc")

	configure_file(Doxyfile.in "${PROJECT_BINARY_DIR}/Doxyfile" @ONLY)
	add_custom_command(
		OUTPUT ${DOXYGEN_OUTPUT_DIR}
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
		COMMENT "Generating documentation"
		)

	add_custom_target(doc DEPENDS ${DOXYGEN_OUTPUT_DIR})
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(INCDIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

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

add_subdirectory(test)
