#include <array>
#include <stdexcept>

#include <math/types.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Matrix3x3)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_WARN(sizeof(math::Matrix3x3) != 3 * 3 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Matrix3x3 M_default;
	BOOST_CHECK_SMALL(M_default[0][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][2], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][2], 1e-7f);
	BOOST_CHECK_SMALL(M_default[2][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[2][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[2][2], 1e-7f);
	// parameterized constructor
	std::array<Vector3, 3> data = {{
			math::Vector3(1.0f, 2.0f, 3.0f),
			math::Vector3(4.0f, 5.0f, 6.0f),
			math::Vector3(7.0f, 8.0f, 9.0f)
		}};
	math::Matrix3x3 M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][2], 9.0f, 1e-4f);
	// parameterized constructor
	math::Vector3 col1(1.0f, 2.0f, 3.0f);
	math::Vector3 col2(4.0f, 5.0f, 6.0f);
	math::Vector3 col3(7.0f, 8.0f, 9.0f);
	math::Matrix3x3 M_param2(col1, col2, col3);
	BOOST_CHECK_CLOSE(M_param2[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x3 M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x3 M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Matrix3x3 M;
	M[0] = math::Vector3(1.0f, 2.0f, 3.0f);
	M[1] = math::Vector3(4.0f, 5.0f, 6.0f);
	M[2] = math::Vector3(7.0f, 8.0f, 9.0f);
	BOOST_CHECK_CLOSE(M[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[2][2], 9.0f, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[3], std::out_of_range);
	BOOST_CHECK_THROW(M[3] = math::Vector3(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x3 M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x3 M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], -2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][2], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], -4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][2], -6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][0], -7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][1], -8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][2], -9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add) {
	math::Matrix3x3 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[1][0] = 4.0f;
	M1[1][1] = 5.0f;
	M1[1][2] = 6.0f;
	M1[2][0] = 7.0f;
	M1[2][1] = 8.0f;
	M1[2][2] = 9.0f;
	math::Matrix3x3 M2;
	M2[0][0] = 9.0f;
	M2[0][1] = 8.0f;
	M2[0][2] = 7.0f;
	M2[1][0] = 6.0f;
	M2[1][1] = 5.0f;
	M2[1][2] = 4.0f;
	M2[2][0] = 3.0f;
	M2[2][1] = 2.0f;
	M2[2][2] = 1.0f;
	math::Matrix3x3 M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][2], 10.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add_eq) {
	math::Matrix3x3 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[1][0] = 4.0f;
	M1[1][1] = 5.0f;
	M1[1][2] = 6.0f;
	M1[2][0] = 7.0f;
	M1[2][1] = 8.0f;
	M1[2][2] = 9.0f;
	math::Matrix3x3 M2;
	M2[0][0] = 9.0f;
	M2[0][1] = 8.0f;
	M2[0][2] = 7.0f;
	M2[1][0] = 6.0f;
	M2[1][1] = 5.0f;
	M2[1][2] = 4.0f;
	M2[2][0] = 3.0f;
	M2[2][1] = 2.0f;
	M2[2][2] = 1.0f;
	math::Matrix3x3 M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][2], 10.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub) {
	math::Matrix3x3 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[1][0] = 4.0f;
	M1[1][1] = 5.0f;
	M1[1][2] = 6.0f;
	M1[2][0] = 7.0f;
	M1[2][1] = 8.0f;
	M1[2][2] = 9.0f;
	math::Matrix3x3 M2;
	M2[0][0] = 9.0f;
	M2[0][1] = 8.0f;
	M2[0][2] = 7.0f;
	M2[1][0] = 6.0f;
	M2[1][1] = 5.0f;
	M2[1][2] = 4.0f;
	M2[2][0] = 3.0f;
	M2[2][1] = 2.0f;
	M2[2][2] = 1.0f;
	math::Matrix3x3 M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], -4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], -2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 0.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][2], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub_eq) {
	math::Matrix3x3 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[1][0] = 4.0f;
	M1[1][1] = 5.0f;
	M1[1][2] = 6.0f;
	M1[2][0] = 7.0f;
	M1[2][1] = 8.0f;
	M1[2][2] = 9.0f;
	math::Matrix3x3 M2;
	M2[0][0] = 9.0f;
	M2[0][1] = 8.0f;
	M2[0][2] = 7.0f;
	M2[1][0] = 6.0f;
	M2[1][1] = 5.0f;
	M2[1][2] = 4.0f;
	M2[2][0] = 3.0f;
	M2[2][1] = 2.0f;
	M2[2][2] = 1.0f;
	math::Matrix3x3 M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], -4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], -2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 0.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][2], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_mult) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x2 M_3x2;
	M_3x2[0][0] = 1.0f;
	M_3x2[0][1] = 2.0f;
	M_3x2[0][2] = 3.0f;
	M_3x2[1][0] = 4.0f;
	M_3x2[1][1] = 5.0f;
	M_3x2[1][2] = 6.0f;
	math::Matrix3x3 M_3x3;
	M_3x3[0][0] = 1.0f;
	M_3x3[0][1] = 2.0f;
	M_3x3[0][2] = 3.0f;
	M_3x3[1][0] = 4.0f;
	M_3x3[1][1] = 5.0f;
	M_3x3[1][2] = 6.0f;
	M_3x3[2][0] = 7.0f;
	M_3x3[2][1] = 8.0f;
	M_3x3[2][2] = 9.0f;
	math::Matrix3x4 M_3x4;
	M_3x4[0][0] = 1.0f;
	M_3x4[0][1] = 2.0f;
	M_3x4[0][2] = 3.0f;
	M_3x4[1][0] = 4.0f;
	M_3x4[1][1] = 5.0f;
	M_3x4[1][2] = 6.0f;
	M_3x4[2][0] = 7.0f;
	M_3x4[2][1] = 8.0f;
	M_3x4[2][2] = 9.0f;
	M_3x4[3][0] = 10.0f;
	M_3x4[3][1] = 11.0f;
	M_3x4[3][2] = 12.0f;
	math::Matrix3x2 M_sum3x2;
	M_sum3x2 = M * M_3x2;
	BOOST_CHECK_CLOSE(M_sum3x2[0][0], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[0][1], 36.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[0][2], 42.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][0], 66.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][1], 81.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x2[1][2], 96.0f, 1e-4f);
	math::Matrix3x3 M_sum3x3;
	M_sum3x3 = M * M_3x3;
	BOOST_CHECK_CLOSE(M_sum3x3[0][0], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[0][1], 36.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[0][2], 42.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][0], 66.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][1], 81.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[1][2], 96.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][0], 102.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][1], 126.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x3[2][2], 150.0f, 1e-4f);
	math::Matrix3x4 M_sum3x4;
	M_sum3x4 = M * M_3x4;
	BOOST_CHECK_CLOSE(M_sum3x4[0][0], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[0][1], 36.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[0][2], 42.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][0], 66.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][1], 81.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[1][2], 96.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][0], 102.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][1], 126.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[2][2], 150.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][0], 138.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][1], 171.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum3x4[3][2], 204.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	float s = 2.0f;
	math::Matrix3x3 M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], 12.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], 16.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][2], 18.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	float s = 2.0f;
	math::Matrix3x3 M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], 12.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], 16.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][2], 18.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Matrix3x3 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[0][2] = 6.0f;
	M[1][0] = 8.0f;
	M[1][1] = 10.0f;
	M[1][2] = 12.0f;
	M[2][0] = 14.0f;
	M[2][1] = 16.0f;
	M[2][2] = 18.0f;
	float s = 2.0f;
	math::Matrix3x3 M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	math::Matrix3x3 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[0][2] = 6.0f;
	M[1][0] = 8.0f;
	M[1][1] = 10.0f;
	M[1][2] = 12.0f;
	M[2][0] = 14.0f;
	M[2][1] = 16.0f;
	M[2][2] = 18.0f;
	float s = 2.0f;
	math::Matrix3x3 M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(transpose) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	math::Matrix3x3 M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][2], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][2], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(det) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 4.0f;
	M[1][1] = 5.0f;
	M[1][2] = 6.0f;
	M[2][0] = 7.0f;
	M[2][1] = 8.0f;
	M[2][2] = 9.0f;
	BOOST_CHECK_SMALL(M.det(), 1e-7f);
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 3.0f;
	M[1][1] = 1.0f;
	M[1][2] = 2.0f;
	M[2][0] = 2.0f;
	M[2][1] = 3.0f;
	M[2][2] = 1.0f;
	BOOST_CHECK_CLOSE(M.det(), 18.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(adjugate) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 3.0f;
	M[1][1] = 1.0f;
	M[1][2] = 2.0f;
	M[2][0] = 2.0f;
	M[2][1] = 3.0f;
	M[2][2] = 1.0f;
	math::Matrix3x3 M_adj = M.adjugate();
	BOOST_CHECK_CLOSE(M_adj[0][0], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[0][1], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[0][2], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][1], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][1], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_adj[2][2], -5.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(inverse) {
	math::Matrix3x3 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[1][0] = 3.0f;
	M[1][1] = 1.0f;
	M[1][2] = 2.0f;
	M[2][0] = 2.0f;
	M[2][1] = 3.0f;
	M[2][2] = 1.0f;
	math::Matrix3x3 M_inv = M.inverse();
	BOOST_CHECK_CLOSE(M_inv[0][0], -0.277777791f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[0][1], 0.388888896f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[0][2], 0.055555556f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][0], 0.055555556f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][1], -0.277777791f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[1][2], 0.388888896f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][0], 0.388888896f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][1], 0.055555556f, 1e-4f);
	BOOST_CHECK_CLOSE(M_inv[2][2], -0.277777791f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Matrix3x3 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[1][0] = 4.0f;
	M1[1][1] = 5.0f;
	M1[1][2] = 6.0f;
	M1[2][0] = 7.0f;
	M1[2][1] = 8.0f;
	M1[2][2] = 9.0f;
	math::Matrix3x3 M2;
	M2[0][0] = 1.0f;
	M2[0][1] = 2.0f;
	M2[0][2] = 3.0f;
	M2[1][0] = 4.0f;
	M2[1][1] = 5.0f;
	M2[1][2] = 6.0f;
	M2[2][0] = 7.0f;
	M2[2][1] = 8.0f;
	M2[2][2] = 9.0f;
	math::Matrix3x3 M3;
	M3[0][0] = 9.0f;
	M3[0][1] = 8.0f;
	M3[0][2] = 7.0f;
	M3[1][0] = 6.0f;
	M3[1][1] = 5.0f;
	M3[1][2] = 4.0f;
	M3[2][0] = 3.0f;
	M3[2][1] = 2.0f;
	M3[2][2] = 1.0f;
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
