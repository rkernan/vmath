cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("math" CXX)

enable_testing()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")

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

add_subdirectory(test)
