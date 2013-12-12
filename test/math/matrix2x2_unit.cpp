#include <array>
#include <stdexcept>

#include <math/types.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Matrix2x2)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_WARN(sizeof(math::Matrix2x2) != 2 * 2 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Matrix2x2 M_default;
	BOOST_CHECK_SMALL(M_default[0][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[0][1], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][0], 1e-7f);
	BOOST_CHECK_SMALL(M_default[1][1], 1e-7f);
	// paremeterized constructor
	std::array<math::Vector2, 2> data = {{
			math::Vector2(1.0f, 2.0f),
			math::Vector2(3.0f, 4.0f)
		}};
	math::Matrix2x2 M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], 4.0f, 1e-4f);
	// parameterized constructor
	math::Vector2 col1(1.0f, 2.0f);
	math::Vector2 col2(3.0f, 4.0f);
	math::Matrix2x2 M_param2(col1, col2);
	BOOST_CHECK_CLOSE(M_param2[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	math::Matrix2x2 M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	math::Matrix2x2 M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Matrix2x2 M;
	M[0] = math::Vector2(1.0f, 2.0f);
	M[1] = math::Vector2(3.0f, 4.0f);
	BOOST_CHECK_CLOSE(M[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], 4.0f, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[2], std::out_of_range);
	BOOST_CHECK_THROW(M[2] = math::Vector2(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	math::Matrix2x2 M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	math::Matrix2x2 M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], -2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], -4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add) {
	math::Matrix2x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[1][0] = 3.0f;
	M1[1][1] = 4.0f;
	math::Matrix2x2 M2;
	M2[0][0] = 4.0f;
	M2[0][1] = 3.0f;
	M2[1][0] = 2.0f;
	M2[1][1] = 1.0f;
	math::Matrix2x2 M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 5.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_add_eq) {
	math::Matrix2x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[1][0] = 3.0f;
	M1[1][1] = 4.0f;
	math::Matrix2x2 M2;
	M2[0][0] = 4.0f;
	M2[0][1] = 3.0f;
	M2[1][0] = 2.0f;
	M2[1][1] = 1.0f;
	math::Matrix2x2 M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], 5.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub) {
	math::Matrix2x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[1][0] = 3.0f;
	M1[1][1] = 4.0f;
	math::Matrix2x2 M2;
	M2[0][0] = 4.0f;
	M2[0][1] = 3.0f;
	M2[1][0] = 2.0f;
	M2[1][1] = 1.0f;
	math::Matrix2x2 M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 3.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_sub_eq) {
	math::Matrix2x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[1][0] = 3.0f;
	M1[1][1] = 4.0f;
	math::Matrix2x2 M2;
	M2[0][0] = 4.0f;
	M2[0][1] = 3.0f;
	M2[1][0] = 2.0f;
	M2[1][1] = 1.0f;
	math::Matrix2x2 M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], -3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], -1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], 3.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(matrix_mult) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
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
	math::Matrix2x2 M_sum2x2;
	M_sum2x2 = M * M_2x2;
	BOOST_CHECK_CLOSE(M_sum2x2[0][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[0][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[1][0], 15.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[1][1], 22.0f, 1e-4f);
	math::Matrix2x3 M_sum2x3;
	M_sum2x3 = M * M_2x3;
	BOOST_CHECK_CLOSE(M_sum2x3[0][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[0][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[1][0], 15.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[1][1], 22.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[2][0], 23.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[2][1], 34.0f, 1e-4f);
	math::Matrix2x4 M_sum2x4;
	M_sum2x4 = M * M_2x4;
	BOOST_CHECK_CLOSE(M_sum2x4[0][0], 7.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[0][1], 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[1][0], 15.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[1][1], 22.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[2][0], 23.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[2][1], 34.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[3][0], 31.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[3][1], 46.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	float s = 2.0f;
	math::Matrix2x2 M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	float s = 2.0f;
	math::Matrix2x2 M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], 4.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], 6.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], 8.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Matrix2x2 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[1][0] = 6.0f;
	M[1][1] = 8.0f;
	float s = 2.0f;
	math::Matrix2x2 M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	math::Matrix2x2 M;
	M[0][0] = 2.0f;
	M[0][1] = 4.0f;
	M[1][0] = 6.0f;
	M[1][1] = 8.0f;
	float s = 2.0f;
	math::Matrix2x2 M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(det) {
	// TODO
}

BOOST_AUTO_TEST_CASE(transpose) {
	math::Matrix2x2 M;
	M[0][0] = 1.0f;
	M[0][1] = 2.0f;
	M[1][0] = 3.0f;
	M[1][1] = 4.0f;
	math::Matrix2x2 M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(inverse) {
	// TODO
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Matrix2x2 M1;
	M1[0][0] = 1.0f;
	M1[0][1] = 2.0f;
	M1[1][0] = 3.0f;
	M1[1][1] = 4.0f;
	math::Matrix2x2 M2;
	M2[0][0] = 1.0f;
	M2[0][1] = 2.0f;
	M2[1][0] = 3.0f;
	M2[1][1] = 4.0f;
	math::Matrix2x2 M3;
	M3[0][0] = 4.0f;
	M3[0][1] = 3.0f;
	M3[1][0] = 2.0f;
	M3[1][1] = 1.0f;
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
