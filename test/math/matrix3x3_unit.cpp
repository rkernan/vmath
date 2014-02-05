#include <array>
#include <stdexcept>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

#include <math/core/matrix.hpp>

#include "../type_lists.hpp"

BOOST_AUTO_TEST_SUITE(Matrix3x3)

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, float_types) {
	BOOST_WARN(sizeof(math::core::Matrix<T, 3>) != 3 * 3 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	math::core::Matrix<T, 3> M_default;
	BOOST_CHECK_SMALL(M_default[0][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][2], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][2], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[2][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[2][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[2][2], static_cast<T>(1e-7));
	// parameterized constructor
	std::array<math::core::Vector<T, 3>, 3> data = {{
			math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0)),
			math::core::Vector<T, 3>(static_cast<T>(4.0), static_cast<T>(5.0), static_cast<T>(6.0)),
			math::core::Vector<T, 3>(static_cast<T>(7.0), static_cast<T>(8.0), static_cast<T>(9.0))
		}};
	math::core::Matrix<T, 3> M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][2], static_cast<T>(9.0), 1e-4f);
	// parameterized constructor
	math::core::Vector<T, 3> col1(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0));
	math::core::Vector<T, 3> col2(static_cast<T>(4.0), static_cast<T>(5.0), static_cast<T>(6.0));
	math::core::Vector<T, 3> col3(static_cast<T>(7.0), static_cast<T>(8.0), static_cast<T>(9.0));
	math::core::Matrix<T, 3> M_param2(col1, col2, col3);
	BOOST_CHECK_CLOSE(M_param2[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0] = math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0));
	M[1] = math::core::Vector<T, 3>(static_cast<T>(4.0), static_cast<T>(5.0), static_cast<T>(6.0));
	M[2] = math::core::Vector<T, 3>(static_cast<T>(7.0), static_cast<T>(8.0), static_cast<T>(9.0));
	BOOST_CHECK_CLOSE(M[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[2][2], static_cast<T>(9.0), 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[3], std::out_of_range);
	BOOST_CHECK_THROW((M[3] = math::core::Vector<T, 3>()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], static_cast<T>(-4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][2], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][0], static_cast<T>(-7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][1], static_cast<T>(-8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][2], static_cast<T>(-9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add, T, float_types) {
	math::core::Matrix<T, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[1][0] = static_cast<T>(4.0);
	M1[1][1] = static_cast<T>(5.0);
	M1[1][2] = static_cast<T>(6.0);
	M1[2][0] = static_cast<T>(7.0);
	M1[2][1] = static_cast<T>(8.0);
	M1[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M2;
	M2[0][0] = static_cast<T>(9.0);
	M2[0][1] = static_cast<T>(8.0);
	M2[0][2] = static_cast<T>(7.0);
	M2[1][0] = static_cast<T>(6.0);
	M2[1][1] = static_cast<T>(5.0);
	M2[1][2] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(3.0);
	M2[2][1] = static_cast<T>(2.0);
	M2[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][2], static_cast<T>(10.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add_eq, T, float_types) {
	math::core::Matrix<T, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[1][0] = static_cast<T>(4.0);
	M1[1][1] = static_cast<T>(5.0);
	M1[1][2] = static_cast<T>(6.0);
	M1[2][0] = static_cast<T>(7.0);
	M1[2][1] = static_cast<T>(8.0);
	M1[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M2;
	M2[0][0] = static_cast<T>(9.0);
	M2[0][1] = static_cast<T>(8.0);
	M2[0][2] = static_cast<T>(7.0);
	M2[1][0] = static_cast<T>(6.0);
	M2[1][1] = static_cast<T>(5.0);
	M2[1][2] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(3.0);
	M2[2][1] = static_cast<T>(2.0);
	M2[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][2], static_cast<T>(10.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub, T, float_types) {
	math::core::Matrix<T, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[1][0] = static_cast<T>(4.0);
	M1[1][1] = static_cast<T>(5.0);
	M1[1][2] = static_cast<T>(6.0);
	M1[2][0] = static_cast<T>(7.0);
	M1[2][1] = static_cast<T>(8.0);
	M1[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M2;
	M2[0][0] = static_cast<T>(9.0);
	M2[0][1] = static_cast<T>(8.0);
	M2[0][2] = static_cast<T>(7.0);
	M2[1][0] = static_cast<T>(6.0);
	M2[1][1] = static_cast<T>(5.0);
	M2[1][2] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(3.0);
	M2[2][1] = static_cast<T>(2.0);
	M2[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], static_cast<T>(-4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(0.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][2], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub_eq, T, float_types) {
	math::core::Matrix<T, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[1][0] = static_cast<T>(4.0);
	M1[1][1] = static_cast<T>(5.0);
	M1[1][2] = static_cast<T>(6.0);
	M1[2][0] = static_cast<T>(7.0);
	M1[2][1] = static_cast<T>(8.0);
	M1[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M2;
	M2[0][0] = static_cast<T>(9.0);
	M2[0][1] = static_cast<T>(8.0);
	M2[0][2] = static_cast<T>(7.0);
	M2[1][0] = static_cast<T>(6.0);
	M2[1][1] = static_cast<T>(5.0);
	M2[1][2] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(3.0);
	M2[2][1] = static_cast<T>(2.0);
	M2[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], static_cast<T>(-4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(0.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][2], static_cast<T>(8.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_mult, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3, 2> M_3x2;
	M_3x2[0][0] = static_cast<T>(1.0);
	M_3x2[0][1] = static_cast<T>(2.0);
	M_3x2[0][2] = static_cast<T>(3.0);
	M_3x2[1][0] = static_cast<T>(4.0);
	M_3x2[1][1] = static_cast<T>(5.0);
	M_3x2[1][2] = static_cast<T>(6.0);
	math::core::Matrix<T, 3> M_3x3;
	M_3x3[0][0] = static_cast<T>(1.0);
	M_3x3[0][1] = static_cast<T>(2.0);
	M_3x3[0][2] = static_cast<T>(3.0);
	M_3x3[1][0] = static_cast<T>(4.0);
	M_3x3[1][1] = static_cast<T>(5.0);
	M_3x3[1][2] = static_cast<T>(6.0);
	M_3x3[2][0] = static_cast<T>(7.0);
	M_3x3[2][1] = static_cast<T>(8.0);
	M_3x3[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3, 4> M_3x4;
	M_3x4[0][0] = static_cast<T>(1.0);
	M_3x4[0][1] = static_cast<T>(2.0);
	M_3x4[0][2] = static_cast<T>(3.0);
	M_3x4[1][0] = static_cast<T>(4.0);
	M_3x4[1][1] = static_cast<T>(5.0);
	M_3x4[1][2] = static_cast<T>(6.0);
	M_3x4[2][0] = static_cast<T>(7.0);
	M_3x4[2][1] = static_cast<T>(8.0);
	M_3x4[2][2] = static_cast<T>(9.0);
	M_3x4[3][0] = static_cast<T>(10.0);
	M_3x4[3][1] = static_cast<T>(11.0);
	M_3x4[3][2] = static_cast<T>(12.0);
	math::core::Matrix<T, 3, 2> M_sum3x2;
	M_sum3x2 = M * M_3x2;
	BOOST_CHECK_CLOSE(M_sum3x2[0][0], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[0][1], static_cast<T>(36.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[0][2], static_cast<T>(42.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][0], static_cast<T>(66.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][1], static_cast<T>(81.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][2], static_cast<T>(96.0), 1e-4f);
	math::core::Matrix<T, 3> M_sum3x3;
	M_sum3x3 = M * M_3x3;
	BOOST_CHECK_CLOSE(M_sum3x3[0][0], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[0][1], static_cast<T>(36.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[0][2], static_cast<T>(42.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][0], static_cast<T>(66.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][1], static_cast<T>(81.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][2], static_cast<T>(96.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][0], static_cast<T>(102.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][1], static_cast<T>(126.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][2], static_cast<T>(150.0), 1e-4f);
	math::core::Matrix<T, 3, 4> M_sum3x4;
	M_sum3x4 = M * M_3x4;
	BOOST_CHECK_CLOSE(M_sum3x4[0][0], static_cast<T>(30.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[0][1], static_cast<T>(36.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[0][2], static_cast<T>(42.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][0], static_cast<T>(66.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][1], static_cast<T>(81.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][2], static_cast<T>(96.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][0], static_cast<T>(102.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][1], static_cast<T>(126.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][2], static_cast<T>(150.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][0], static_cast<T>(138.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][1], static_cast<T>(171.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][2], static_cast<T>(204.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	T s = static_cast<T>(2.0);
	math::core::Matrix<T, 3> M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], static_cast<T>(16.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][2], static_cast<T>(18.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	T s = static_cast<T>(2.0);
	math::core::Matrix<T, 3> M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], static_cast<T>(14.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], static_cast<T>(16.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][2], static_cast<T>(18.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[0][2] = static_cast<T>(6.0);
	M[1][0] = static_cast<T>(8.0);
	M[1][1] = static_cast<T>(10.0);
	M[1][2] = static_cast<T>(12.0);
	M[2][0] = static_cast<T>(14.0);
	M[2][1] = static_cast<T>(16.0);
	M[2][2] = static_cast<T>(18.0);
	T s = static_cast<T>(2.0);
	math::core::Matrix<T, 3> M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[0][2] = static_cast<T>(6.0);
	M[1][0] = static_cast<T>(8.0);
	M[1][1] = static_cast<T>(10.0);
	M[1][2] = static_cast<T>(12.0);
	M[2][0] = static_cast<T>(14.0);
	M[2][1] = static_cast<T>(16.0);
	M[2][2] = static_cast<T>(18.0);
	T s = static_cast<T>(2.0);
	math::core::Matrix<T, 3> M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(transpose, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][2], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][2], static_cast<T>(9.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(minor, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	BOOST_CHECK_CLOSE(M.minor(0, 0), static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(1, 0), static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(2, 0), static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(0, 1), static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(1, 1), static_cast<T>(-12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(2, 1), static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(0, 2), static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(1, 2), static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M.minor(2, 2), static_cast<T>(-3.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(det, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	BOOST_CHECK_SMALL(M.det(), static_cast<T>(1e-7));
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(1.0);
	M[1][2] = static_cast<T>(2.0);
	M[2][0] = static_cast<T>(2.0);
	M[2][1] = static_cast<T>(3.0);
	M[2][2] = static_cast<T>(1.0);
	BOOST_CHECK_CLOSE(M.det(), static_cast<T>(18.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(minors, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_minors;
	M_minors = M.minors();
	BOOST_CHECK_CLOSE(M_minors[0][0], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[0][1], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[1][0], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[1][1], static_cast<T>(-12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[1][2], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[2][0], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[2][1], static_cast<T>(-6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_minors[2][2], static_cast<T>(-3.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(cofactor, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(4.0);
	M[1][1] = static_cast<T>(5.0);
	M[1][2] = static_cast<T>(6.0);
	M[2][0] = static_cast<T>(7.0);
	M[2][1] = static_cast<T>(8.0);
	M[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M_cofactor;
	M_cofactor = M.cofactor();
	BOOST_CHECK_CLOSE(M_cofactor[0][0], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[0][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[0][2], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[1][0], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[1][1], static_cast<T>(-12.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[1][2], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[2][0], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[2][1], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_cofactor[2][2], static_cast<T>(-3.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adjugate, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(1.0);
	M[1][2] = static_cast<T>(2.0);
	M[2][0] = static_cast<T>(2.0);
	M[2][1] = static_cast<T>(3.0);
	M[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_adj = M.adjugate();
	BOOST_CHECK_CLOSE(M_adj[0][0], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[0][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[0][2], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][1], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][2], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][1], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][2], static_cast<T>(-5.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(inverse, T, float_types) {
	math::core::Matrix<T, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[0][2] = static_cast<T>(3.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(1.0);
	M[1][2] = static_cast<T>(2.0);
	M[2][0] = static_cast<T>(2.0);
	M[2][1] = static_cast<T>(3.0);
	M[2][2] = static_cast<T>(1.0);
	math::core::Matrix<T, 3> M_inv = M.inverse();
	BOOST_CHECK_CLOSE(M_inv[0][0], static_cast<T>(-0.277777791), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[0][1], static_cast<T>(0.388888896), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[0][2], static_cast<T>(0.055555556), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][0], static_cast<T>(0.055555556), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][1], static_cast<T>(-0.277777791), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][2], static_cast<T>(0.388888896), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][0], static_cast<T>(0.388888896), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][1], static_cast<T>(0.055555556), 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][2], static_cast<T>(-0.277777791), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	math::core::Matrix<T, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[0][2] = static_cast<T>(3.0);
	M1[1][0] = static_cast<T>(4.0);
	M1[1][1] = static_cast<T>(5.0);
	M1[1][2] = static_cast<T>(6.0);
	M1[2][0] = static_cast<T>(7.0);
	M1[2][1] = static_cast<T>(8.0);
	M1[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[0][2] = static_cast<T>(3.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(5.0);
	M2[1][2] = static_cast<T>(6.0);
	M2[2][0] = static_cast<T>(7.0);
	M2[2][1] = static_cast<T>(8.0);
	M2[2][2] = static_cast<T>(9.0);
	math::core::Matrix<T, 3> M3;
	M3[0][0] = static_cast<T>(9.0);
	M3[0][1] = static_cast<T>(8.0);
	M3[0][2] = static_cast<T>(7.0);
	M3[1][0] = static_cast<T>(6.0);
	M3[1][1] = static_cast<T>(5.0);
	M3[1][2] = static_cast<T>(4.0);
	M3[2][0] = static_cast<T>(3.0);
	M3[2][1] = static_cast<T>(2.0);
	M3[2][2] = static_cast<T>(1.0);
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
