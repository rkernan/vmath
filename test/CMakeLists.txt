set(SOURCES
	unit_test_runner.cpp
	unit/functions.cpp
	unit/matrix2x2.cpp
	unit/matrix2x3.cpp
	unit/matrix2x4.cpp
	unit/matrix3x2.cpp
	unit/matrix3x3.cpp
	unit/matrix3x4.cpp
	unit/matrix4x2.cpp
	unit/matrix4x3.cpp
	unit/matrix4x4.cpp
	unit/quaternion.cpp
	unit/swizzle2.cpp
	unit/swizzle3.cpp
	unit/swizzle4.cpp
	unit/vector2.cpp
	unit/vector3.cpp
	unit/vector4.cpp
)

add_executable(unit_tests
	${SOURCES}
)

add_definitions("-std=c++11")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
target_link_libraries(unit_tests ${Boost_LIBRARIES})

add_test(UnitTests unit_tests)
