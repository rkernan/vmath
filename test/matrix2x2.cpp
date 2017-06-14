#define BOOST_TEST_MODULE matrix2x2
#include "boost_test_config.hpp"

#include <stdexcept>
#include <vmath/matrix2x2.hpp>
#include <vmath/matrix_functions.hpp>
#include <vmath/vector2.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, floating_point_types) {
	BOOST_CHECK(sizeof(vmath::Matrix<T, 2, 2>) == 2 * 2 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m;
	BOOST_CHECK_SMALL(m[0][0], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[0][1], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][0], static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(m[1][1], static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                         vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_copy, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                                                vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0))));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_move, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(std::move(vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                                                          vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)))));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                         vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE);
	// invalid index
	BOOST_CHECK_THROW(m[2], std::out_of_range);
	BOOST_CHECK_THROW((m[2] = vmath::Vector<T, 2>()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	auto m = vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                                vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	// FIXME
	/* auto m = -vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)), */
	/*                                 vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0))); */
	/* BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(-1.0), TOLERANCE); */
	/* BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(-2.0), TOLERANCE); */
	/* BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(-3.0), TOLERANCE); */
	/* BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(-4.0), TOLERANCE); */
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	auto m = vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)), vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)))
	         + vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(4.0), static_cast<T>(3.0)), vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(1.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(5.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                         vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)));
	m += vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(4.0), static_cast<T>(3.0)),
	                            vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(1.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(5.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(5.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	auto m = vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)), vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)))
	         - vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(4.0), static_cast<T>(3.0)), vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(1.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(-3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(-1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(3.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
	                         vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)));
	m -= vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(4.0), static_cast<T>(3.0)),
	                            vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(1.0)));
	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(-3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(-1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(3.0), TOLERANCE);
}

/* BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) { */
/* 	auto m = vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)), vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0))) */
/* 	         * static_cast<T>(2.0); */
/* 	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(2.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(4.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(6.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(8.0), TOLERANCE); */
/* } */

/* BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) { */
/* 	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)), vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0))); */
/* 	m *= static_cast<T>(2.0); */
/* 	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(2.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(4.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(6.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(8.0), TOLERANCE); */
/* } */

/* BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) { */
/* 	auto m = vmath::Matrix<T, 2, 2>(vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(4.0)), vmath::Vector<T, 2>(static_cast<T>(6.0), static_cast<T>(8.0))) */
/* 	         / static_cast<T>(2.0); */
/* 	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE); */
/* } */

/* BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) { */
/* 	vmath::Matrix<T, 2, 2> m(vmath::Vector<T, 2>(static_cast<T>(2.0), static_cast<T>(4.0)), vmath::Vector<T, 2>(static_cast<T>(6.0), static_cast<T>(8.0))); */
/* 	m /= static_cast<T>(2.0); */
/* 	BOOST_CHECK_CLOSE(m[0][0], static_cast<T>(1.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[0][1], static_cast<T>(2.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][0], static_cast<T>(3.0), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(m[1][1], static_cast<T>(4.0), TOLERANCE); */
/* } */

// TODO matrix multiplication
// TODO transpose
// TODO minor
// TODO determinate
// TODO minors
// TODO cofactor
// TODO adjugate
// TODO inverse
// TODO equals
