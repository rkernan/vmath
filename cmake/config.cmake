if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	add_definitions("-std=c++11")
endif()

option(MATH_BUILD_DOC "Built HTML documentation." ON)
option(MATH_BUILD_TESTS "Build tests." ON)
