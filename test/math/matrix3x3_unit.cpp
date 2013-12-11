#include <math/types.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Matrix3x3)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_WARN(sizeof(math::Matrix3x3) != 3 * 3 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
}

BOOST_AUTO_TEST_CASE(copy) {
}

BOOST_AUTO_TEST_CASE(move) {
}

BOOST_AUTO_TEST_CASE(members) {
}

BOOST_AUTO_TEST_CASE(assign) {
}

BOOST_AUTO_TEST_CASE(negate) {
}

BOOST_AUTO_TEST_CASE(equals) {
}

BOOST_AUTO_TEST_CASE(matrix_add) {
}

BOOST_AUTO_TEST_CASE(matrix_add_eq) {
}

BOOST_AUTO_TEST_CASE(matrix_sub) {
}

BOOST_AUTO_TEST_CASE(matrix_mult) {
}

BOOST_AUTO_TEST_CASE(matrix_sub_eq) {
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
}

BOOST_AUTO_TEST_CASE(scalar_div) {
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
}

BOOST_AUTO_TEST_CASE(det) {
}

BOOST_AUTO_TEST_CASE(transpose) {
}

BOOST_AUTO_TEST_CASE(inverse) {
}

BOOST_AUTO_TEST_SUITE_END()
