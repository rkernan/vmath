cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

set(PROJECT_NAME "vmath")
set(PROJECT_VERSION_MAJOR 1 CACHE STRING "Project major version number")
set(PROJECT_VERSION_MINOR 1 CACHE STRING "Project minor version number")
set(PROJECT_VERSION_PATCH 1 CACHE STRING "Project patch version number")
mark_as_advanced(PROJECT_VERSION_MAJOR PROJECT_VERSION_MINOR PROJECT_VERSION_PATCH)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} LANGUAGES CXX)
message(STATUS "Project: ${PROJECT_NAME} ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/inc/vmath)
add_library(${PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/vmath.cpp)

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/doc)

# FIXME remove
add_executable("brap" "src/test.cpp")
target_link_libraries("brap" ${PROJECT_NAME})
