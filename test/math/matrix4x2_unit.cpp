#include <array>
#include <stdexcept>

#include <math/types.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Matrix4x2)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_WARN(sizeof(math::Matrix4x2) != 2 * 4 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Matrix4x2 M_default;
	BOOST_CHECK_SMALL(M_default[0][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][2], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][3], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][2], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][3], 1e-7f);
	// parameterized constructor
	std::array<math::Vector4, 2> data = {{
			math::Vector4(1.0f, 2.0f, 3.0f, 4.0f),
			math::Vector4(5.0f, 6.0f, 7.0f, 8.0f)
		}};
	math::Matrix4x2 M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][3], 8.0f, 1e-4f);
	// parameterized constructor
	math::Vector4 col1(1.0f, 2.0f, 3.0f, 4.0f);
	math::Vector4 col2(5.0f, 6.0f, 7.0f, 8.0f);
	math::Matrix4x2 M_param2(col1, col2);
	BOOST_CHECK_CLOSE(M_param2[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix4x2 M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix4x2 M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Matrix4x2 M;
	M[0] = math::Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	M[1] = math::Vector4(5.0f, 6.0f, 7.0f, 8.0f);
	BOOST_CHECK_CLOSE(M[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][3], 8.0f, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[2], std::out_of_range);
	BOOST_CHECK_THROW(M[2] = math::Vector4(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix4x2 M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix4x2 M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], -2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][2], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][3], -4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], -6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][2], -7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][3], -8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add) {
	math::Matrix4x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[0][3] = 4.0f;
	M1[1][0] = 5.0f;
	M1[1][1] = 6.0f;
	M1[1][2] = 7.0f;
	M1[1][3] = 8.0f;
	math::Matrix4x2 M2;
	M2[0][0] = 8.0f;
	M2[0][1] = 7.0f;
	M2[0][2] = 6.0f;
	M2[0][3] = 5.0f;
	M2[1][0] = 4.0f;
	M2[1][1] = 3.0f;
	M2[1][2] = 2.0f;
	M2[1][3] = 1.0f;
	math::Matrix4x2 M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][3], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][3], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add_eq) {
	math::Matrix4x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[0][3] = 4.0f;
	M1[1][0] = 5.0f;
	M1[1][1] = 6.0f;
	M1[1][2] = 7.0f;
	M1[1][3] = 8.0f;
	math::Matrix4x2 M2;
	M2[0][0] = 8.0f;
	M2[0][1] = 7.0f;
	M2[0][2] = 6.0f;
	M2[0][3] = 5.0f;
	M2[1][0] = 4.0f;
	M2[1][1] = 3.0f;
	M2[1][2] = 2.0f;
	M2[1][3] = 1.0f;
	math::Matrix4x2 M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][2], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][3], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][2], 9.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][3], 9.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub) {
	math::Matrix4x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[0][3] = 4.0f;
	M1[1][0] = 5.0f;
	M1[1][1] = 6.0f;
	M1[1][2] = 7.0f;
	M1[1][3] = 8.0f;
	math::Matrix4x2 M2;
	M2[0][0] = 8.0f;
	M2[0][1] = 7.0f;
	M2[0][2] = 6.0f;
	M2[0][3] = 5.0f;
	M2[1][0] = 4.0f;
	M2[1][1] = 3.0f;
	M2[1][2] = 2.0f;
	M2[1][3] = 1.0f;
	math::Matrix4x2 M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][3], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][3], 7.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub_eq) {
	math::Matrix4x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[0][3] = 4.0f;
	M1[1][0] = 5.0f;
	M1[1][1] = 6.0f;
	M1[1][2] = 7.0f;
	M1[1][3] = 8.0f;
	math::Matrix4x2 M2;
	M2[0][0] = 8.0f;
	M2[0][1] = 7.0f;
	M2[0][2] = 6.0f;
	M2[0][3] = 5.0f;
	M2[1][0] = 4.0f;
	M2[1][1] = 3.0f;
	M2[1][2] = 2.0f;
	M2[1][3] = 1.0f;
	math::Matrix4x2 M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][2], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][3], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][2], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][3], 7.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_mult) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix2x2 M_2x2;
	M_2x2[0][0] = 1.0f;
	M_2x2[0][1] = 2.0f;
	M_2x2[1][0] = 3.0f;
	M_2x2[1][1] = 4.0f;
	math::Matrix2x3 M_2x3;
	M_2x3[0][0] = 1.0f;
	M_2x3[0][1] = 2.0f;
	M_2x3[1][0] = 3.0f;
	M_2x3[1][1] = 4.0f;
	M_2x3[2][0] = 5.0f;
	M_2x3[2][1] = 6.0f;
	math::Matrix2x4 M_2x4;
	M_2x4[0][0] = 1.0f;
	M_2x4[0][1] = 2.0f;
	M_2x4[1][0] = 3.0f;
	M_2x4[1][1] = 4.0f;
	M_2x4[2][0] = 5.0f;
	M_2x4[2][1] = 6.0f;
	M_2x4[3][0] = 7.0f;
	M_2x4[3][1] = 8.0f;
	math::Matrix4x2 M_sum4x2;
	M_sum4x2 = M * M_2x2;
	BOOST_CHECK_CLOSE(M_sum4x2[0][0], 11.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][1], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][2], 17.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[0][3], 20.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][0], 23.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][1], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][2], 37.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x2[1][3], 44.0f, 1e-4f);
	math::Matrix4x3 M_sum4x3;
	M_sum4x3 = M * M_2x3;
	BOOST_CHECK_CLOSE(M_sum4x3[0][0], 11.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][1], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][2], 17.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[0][3], 20.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][0], 23.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][1], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][2], 37.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[1][3], 44.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][0], 35.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][1], 46.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][2], 57.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x3[2][3], 68.0f, 1e-4f);
	math::Matrix4x4 M_sum4x4;
	M_sum4x4 = M * M_2x4;
	BOOST_CHECK_CLOSE(M_sum4x4[0][0], 11.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][1], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][2], 17.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[0][3], 20.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][0], 23.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][1], 30.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][2], 37.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[1][3], 44.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][0], 35.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][1], 46.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][2], 57.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[2][3], 68.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][0], 47.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][1], 62.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][2], 77.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum4x4[3][3], 92.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	float s = 2.0f;
	math::Matrix4x2 M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][3], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 12.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][3], 16.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	float s = 2.0f;
	math::Matrix4x2 M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][2], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][3], 8.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 12.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][2], 14.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][3], 16.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Matrix4x2 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[0][2] = 6.0f;
	M[0][3] = 8.0f;
	M[1][0] = 10.0f;
	M[1][1] = 12.0f;
	M[1][2] = 14.0f;
	M[1][3] = 16.0f;
	float s = 2.0f;
	math::Matrix4x2 M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	math::Matrix4x2 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[0][2] = 6.0f;
	M[0][3] = 8.0f;
	M[1][0] = 10.0f;
	M[1][1] = 12.0f;
	M[1][2] = 14.0f;
	M[1][3] = 16.0f;
	float s = 2.0f;
	math::Matrix4x2 M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][2], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][3], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][2], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][3], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(transpose) {
	math::Matrix4x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[0][2] = 3.0f;
	M[0][3] = 4.0f;
	M[1][0] = 5.0f;
	M[1][1] = 6.0f;
	M[1][2] = 7.0f;
	M[1][3] = 8.0f;
	math::Matrix2x4 M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[2][1], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[3][0], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[3][1], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Matrix4x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[0][2] = 3.0f;
	M1[0][3] = 4.0f;
	M1[1][0] = 5.0f;
	M1[1][1] = 6.0f;
	M1[1][2] = 7.0f;
	M1[1][3] = 8.0f;
	math::Matrix4x2 M2;
	M2[0][0] = 1.0f;
	M2[0][1] = 2.0f;
	M2[0][2] = 3.0f;
	M2[0][3] = 4.0f;
	M2[1][0] = 5.0f;
	M2[1][1] = 6.0f;
	M2[1][2] = 7.0f;
	M2[1][3] = 8.0f;
	math::Matrix4x2 M3;
	M3[0][0] = 8.0f;
	M3[0][1] = 7.0f;
	M3[0][2] = 6.0f;
	M3[0][3] = 5.0f;
	M3[1][0] = 4.0f;
	M3[1][1] = 3.0f;
	M3[1][2] = 2.0f;
	M3[1][3] = 1.0f;
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
