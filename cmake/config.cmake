if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	add_definitions("-std=c++11")
endif()

option(VMATH_BUILD_DOC "Built HTML documentation." ON)
option(VMATH_BUILD_TESTS "Build tests." ON)
