cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("math" CXX)

enable_testing()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")

add_subdirectory(test)
