#define BOOST_TEST_MODULE matrix4x2
#include "boost_test_config.hpp"

#include <stdexcept>
#include <vmath/matrix4x2.hpp>
#include <vmath/matrix_functions.hpp>
#include <vmath/vector4.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, floating_point_types) {
	BOOST_CHECK(sizeof(vmath::Matrix<T, 4, 2>) == 4 * 2 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor, T, floating_point_types) {
	vmath::Matrix<T, 4, 2> m;
	BOOST_CHECK_SMALL(m[0][0], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[0][1], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[0][2], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[0][3], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][0], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][1], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][2], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][3], static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param, T, floating_point_types) {
	vmath::Matrix<T, 4, 2> m(vmath::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
	                         vmath::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][2], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][3], static_cast<T>(4.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(6.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][2], static_cast<T>(7.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][3], static_cast<T>(8.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_copy, T, floating_point_types) {
	vmath::Matrix<T, 4, 2> m(vmath::Matrix<T, 4, 2>(vmath::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
	                                                vmath::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0))));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][2], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][3], static_cast<T>(4.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(6.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][2], static_cast<T>(7.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][3], static_cast<T>(8.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_move, T, floating_point_types) {
	vmath::Matrix<T, 4, 2> m(std::move(vmath::Matrix<T, 4, 2>(vmath::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
	                                                          vmath::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0)))));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][2], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][3], static_cast<T>(4.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(6.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][2], static_cast<T>(7.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][3], static_cast<T>(8.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, floating_point_types) {
	vmath::Matrix<T, 4, 2> m(vmath::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
	                         vmath::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][2], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][3], static_cast<T>(4.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(6.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][2], static_cast<T>(7.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][3], static_cast<T>(8.0), TOLERANCE);
	// invalid index
	BOOST_CHECK_THROW(m[4], std::out_of_range);
	BOOST_CHECK_THROW((m[4] = vmath::Vector<T, 4>()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	auto m = vmath::Matrix<T, 4, 2>(vmath::Vector<T, 4>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0)),
	                                vmath::Vector<T, 4>(static_cast<T>(5.0), static_cast<T>(6.0), static_cast<T>(7.0), static_cast<T>(8.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][2], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][3], static_cast<T>(4.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(6.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][2], static_cast<T>(7.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][3], static_cast<T>(8.0), TOLERANCE);
}

// TODO negation op
// TODO matrix addition
// TODO matrix subtraction
// TODO matrix multiplication
// TODO scalar multiplication
// TODO scalar division
// TODO transpose
// TODO equals
