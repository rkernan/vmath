cmake_minimum_required(VERSION 3.5)

set(VERSION_MAJOR 1 CACHE STRING "Project major version number")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number")
set(VERSION_PATCH 1 CACHE STRING "Project patch version number")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

project("vmath" VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} LANGUAGES CXX)
message(STATUS "Project Version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_library(vmath SHARED src/vmath.cpp)

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
add_subdirectory(test)

add_subdirectory(doc)
