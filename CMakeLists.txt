cmake_minimum_required(VERSION 3.5)

set(VERSION_MAJOR 1 CACHE STRING "Project major version number")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number")
set(VERSION_PATCH 0 CACHE STRING "Project match version number")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

project("vmath" VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} LANGUAGES CXX)
message(STATUS "Project Version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(doc)

enable_testing()
add_subdirectory(test)
