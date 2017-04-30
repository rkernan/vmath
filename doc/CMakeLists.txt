find_package(Doxygen)
option(BUILD_DOCUMENTATION "Build HTML base API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    set(DOXYFILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
    set(DOXYFILE "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile}")

    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is required to build the documentation")
    endif()

    configure_file(${DOXYFILE_IN} ${DOXYFILE} @ONLY)
    add_custom_target(
        doc ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating HTML documentation" VERBATIM
    )
else()
    message(WARNING "Skipping documentation build")
endif()
