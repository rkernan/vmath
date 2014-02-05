#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

#include <math/core/quaternion.hpp>

#include "../type_lists.hpp"

BOOST_AUTO_TEST_SUITE(Quaternion)

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	math::core::Quaternion<T> H_default;
	BOOST_CHECK_SMALL(H_default.x, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H_default.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H_default.z, static_cast<T>(1e-7));
	// parameterized constructor
	math::core::Quaternion<T> H_param(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0));
	BOOST_CHECK_CLOSE(H_param.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_param.y, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_param.z, static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_param.w, static_cast<T>(4.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(from_axis_angle, T, float_types) {
	math::core::Quaternion<T> H_param2(
		math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)),
		math::radians(static_cast<T>(90.0)));
	BOOST_CHECK_CLOSE(H_param2.x, static_cast<T>(0.707106769), 1e-4f);
	BOOST_CHECK_SMALL(H_param2.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H_param2.z, static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(H_param2.w, static_cast<T>(0.707106769), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(from_euler, T, float_types) {
	math::core::Quaternion<T> H_param3(math::radians(static_cast<T>(90.0)), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(H_param3.x, static_cast<T>(0.707106769), 1e-4f);
	BOOST_CHECK_SMALL(H_param3.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H_param3.z, static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(H_param3.w, static_cast<T>(0.707106769), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(from_matrix4, T, float_types) {
	math::core::Matrix<T, 4> M;
	M[0][0] = static_cast<T>(0.696367031483999);
	M[0][1] = static_cast<T>(0.6963627001160001);
	M[0][2] = static_cast<T>(-0.17364002904);
	M[0][3] = static_cast<T>(0.0);
	M[1][0] = static_cast<T>(-0.62246796936);
	M[1][1] = static_cast<T>(0.706459172124);
	M[1][2] = static_cast<T>(0.336820447316);
	M[1][3] = static_cast<T>(0.0);
	M[2][0] = static_cast<T>(0.357219116116);
	M[2][1] = static_cast<T>(-0.12646492199);
	M[2][2] = static_cast<T>(0.925419288444);
	M[2][3] = static_cast<T>(0.0);
	M[3][0] = static_cast<T>(0.0);
	M[3][1] = static_cast<T>(0.0);
	M[3][2] = static_cast<T>(0.0);
	M[3][3] = static_cast<T>(1.0);
	math::core::Quaternion<T> H(M);
	BOOST_CHECK_CLOSE(H.x, static_cast<T>(0.126973), 1e-3f);
	BOOST_CHECK_CLOSE(H.y, static_cast<T>(0.145493), 1e-3f);
	BOOST_CHECK_CLOSE(H.z, static_cast<T>(0.361453), 1e-3f);
	BOOST_CHECK_CLOSE(H.w, static_cast<T>(0.912173), 1e-3f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.63);
	math::core::Quaternion<T> H_copy(H);
	BOOST_CHECK_CLOSE(H_copy.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H_move(std::move(H));
	BOOST_CHECK_CLOSE(H_move.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	BOOST_CHECK_CLOSE(H[0], H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H[1], H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H[2], H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H[3], H.w, 1e-4f);
	H[0] = static_cast<T>(100.89);
	H[1] = static_cast<T>(-18.2);
	H[2] = static_cast<T>(35.62);
	H[3] = static_cast<T>(20.12);
	BOOST_CHECK_CLOSE(H[0], H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H[1], H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H[2], H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H[3], H.w, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(H[4], std::out_of_range);
	BOOST_CHECK_THROW(H[4] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H_assign;
	H_assign = H;
	BOOST_CHECK_CLOSE(H_assign.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H_neg;
	H_neg = -H;
	BOOST_CHECK_CLOSE(H_neg.x, static_cast<T>(-20.12), 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.y, static_cast<T>(-100.89), 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.z, static_cast<T>(18.2), 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.w, static_cast<T>(-35.62), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_add;
	H_add = H1 + H2;
	BOOST_CHECK_CLOSE(H_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.y, static_cast<T>(85.39), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.w, static_cast<T>(-164.72), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_add = H1;
	H_add += H2;
	BOOST_CHECK_CLOSE(H_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.y, static_cast<T>(85.39), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_add.w, static_cast<T>(-164.72), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_sub;
	H_sub = H1 - H2;
	BOOST_CHECK_CLOSE(H_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.y, static_cast<T>(116.39), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.z, static_cast<T>(-38.4), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.w, static_cast<T>(235.96), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_sub = H1;
	H_sub -= H2;
	BOOST_CHECK_CLOSE(H_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.y, static_cast<T>(116.39), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.z, static_cast<T>(-38.4), 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.w, static_cast<T>(235.96), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_mult;
	H_mult = H1 * H2;
	BOOST_CHECK_CLOSE(H_mult.x, static_cast<T>(-1906.652), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, static_cast<T>(-21359.0246), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, static_cast<T>(3010.6493), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, static_cast<T>(-5412.7166), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_mult = H1;
	H_mult *= H2;
	BOOST_CHECK_CLOSE(H_mult.x, static_cast<T>(-1906.652), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, static_cast<T>(-21359.0246), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, static_cast<T>(3010.6493), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, static_cast<T>(-5412.7166), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(vector3_mult, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(0.3651483655);
	H.y = static_cast<T>(0.5477225184);
	H.z = static_cast<T>(0.7302967310);
	H.w = static_cast<T>(0.1825741827);
	math::core::Vector<T, 3> V;
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	math::core::Vector<T, 3> V_rot;
	V_rot = H * V;
	BOOST_CHECK_CLOSE(V_rot.x, static_cast<T>(-0.6666666269), 1e-4f);
	BOOST_CHECK_CLOSE(V_rot.y, static_cast<T>(0.6666666269), 1e-4f);
	BOOST_CHECK_CLOSE(V_rot.z, static_cast<T>(0.3333333135), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	math::core::Quaternion<T> H_mult;
	H_mult = H * s;
	BOOST_CHECK_CLOSE(H_mult.x, static_cast<T>(-693.134), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, static_cast<T>(-3475.6605), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, static_cast<T>(626.99), 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, static_cast<T>(-1227.109), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	math::core::Quaternion<T> H_div;
	H_div = H / s;
	BOOST_CHECK_CLOSE(H_div.x, static_cast<T>(-0.5840348330914369), 1e-4f);
	BOOST_CHECK_CLOSE(H_div.y, static_cast<T>(-2.9285921625544264), 1e-4f);
	BOOST_CHECK_CLOSE(H_div.z, static_cast<T>(0.5283018867924527), 1e-4f);
	BOOST_CHECK_CLOSE(H_div.w, static_cast<T>(-1.0339622641509432), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	T mag = H.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(110.37948586580751), 1e-4f);
	H.x = static_cast<T>(1.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	mag = H.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(1.0), 1e-4f);
	H.x = static_cast<T>(0.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	mag = H.mag();
	BOOST_CHECK_SMALL(mag, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	T mag2 = H.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(12183.6309), 1e-4f);
	H.x = static_cast<T>(1.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	mag2 = H.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(1.0), 1e-4f);
	H.x = static_cast<T>(0.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	mag2 = H.mag2();
	BOOST_CHECK_SMALL(mag2, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H_norm(H.normal());
	BOOST_CHECK_CLOSE(H_norm.x, static_cast<T>(0.18228024747696905), 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.y, static_cast<T>(0.914028537145233), 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.z, static_cast<T>(-0.16488571093841137), 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.w, static_cast<T>(0.32270489140803366), 2e-5f);
	H.x = static_cast<T>(1.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	H_norm = H.normal();
	BOOST_CHECK_CLOSE(H_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(H_norm.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H_norm.z, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(20.12);
	H.y = static_cast<T>(100.89);
	H.z = static_cast<T>(-18.2);
	H.w = static_cast<T>(35.62);
	H.normalize();
	BOOST_CHECK_CLOSE(H.x, static_cast<T>(0.18228024747696905), 1e-4f);
	BOOST_CHECK_CLOSE(H.y, static_cast<T>(0.914028537145233), 1e-4f);
	BOOST_CHECK_CLOSE(H.z, static_cast<T>(-0.16488571093841137), 1e-4f);
	BOOST_CHECK_CLOSE(H.w, static_cast<T>(0.32270489140803366), 2e-5f);
	H.x = static_cast<T>(1.0);
	H.y = static_cast<T>(0.0);
	H.z = static_cast<T>(0.0);
	H.w = static_cast<T>(0.0);
	math::core::Quaternion<T> H_norm;
	H_norm = H.normalize();
	BOOST_CHECK_CLOSE(H_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(H.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H.z, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(H.w, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(inverse, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(2.0);
	H.y = static_cast<T>(4.0);
	H.z = static_cast<T>(2.0);
	H.w = static_cast<T>(4.0);
	math::core::Quaternion<T> H_inv = H.inverse();
	BOOST_CHECK_CLOSE(H_inv.x, static_cast<T>(-0.05), 1e-4);
	BOOST_CHECK_CLOSE(H_inv.y, static_cast<T>(-0.1), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, static_cast<T>(-0.05), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, static_cast<T>(0.1), 1e-4f);
	H.x = static_cast<T>(0.5);
	H.y = static_cast<T>(0.5);
	H.z = static_cast<T>(0.5);
	H.w = static_cast<T>(0.5);
	H_inv = H.inverse();
	BOOST_CHECK_CLOSE(H_inv.x, static_cast<T>(-0.5), 1e-4);
	BOOST_CHECK_CLOSE(H_inv.y, static_cast<T>(-0.5), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, static_cast<T>(-0.5), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, static_cast<T>(0.5), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(invert, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(2.0);
	H.y = static_cast<T>(4.0);
	H.z = static_cast<T>(2.0);
	H.w = static_cast<T>(4.0);
	H.invert();
	BOOST_CHECK_CLOSE(H.x, static_cast<T>(-0.05), 1e-4);
	BOOST_CHECK_CLOSE(H.y, static_cast<T>(-0.1), 1e-4f);
	BOOST_CHECK_CLOSE(H.z, static_cast<T>(-0.05), 1e-4f);
	BOOST_CHECK_CLOSE(H.w, static_cast<T>(0.1), 1e-4f);
	H.x = static_cast<T>(0.5);
	H.y = static_cast<T>(0.5);
	H.z = static_cast<T>(0.5);
	H.w = static_cast<T>(0.5);
	math::core::Quaternion<T> H_inv = H.invert();
	BOOST_CHECK_CLOSE(H_inv.x, static_cast<T>(-0.5), 1e-4);
	BOOST_CHECK_CLOSE(H_inv.y, static_cast<T>(-0.5), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, static_cast<T>(-0.5), 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, static_cast<T>(0.5), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(to_euler_angles, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(0.126973);
	H.y = static_cast<T>(0.145493);
	H.z = static_cast<T>(0.361453);
	H.w = static_cast<T>(0.912173);
	BOOST_CHECK_CLOSE(H.pitch(), static_cast<T>(0.349062055), 1e-4f);
	BOOST_CHECK_CLOSE(H.yaw(), static_cast<T>(0.174524635), 1e-4f);
	BOOST_CHECK_CLOSE(H.roll(), static_cast<T>(0.785396338), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(to_axis_angle, T, float_types) {
	math::core::Quaternion<T> H(
		math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(1.0), static_cast<T>(0.0)),
		math::radians(static_cast<T>(22.0)));
	BOOST_CHECK_CLOSE(H.axis().x, static_cast<T>(0.707106829), 1e-4f);
	BOOST_CHECK_CLOSE(H.axis().y, static_cast<T>(0.707106829), 1e-4f);
	BOOST_CHECK_SMALL(H.axis().z, static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(H.angle(), math::radians(static_cast<T>(22.0)), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(to_matrix4, T, float_types) {
	math::core::Quaternion<T> H;
	H.x = static_cast<T>(0.126973);
	H.y = static_cast<T>(0.145493);
	H.z = static_cast<T>(0.361453);
	H.w = static_cast<T>(0.912173);
	math::core::Matrix<T, 4> M;
	M = H.matrix4();
	BOOST_CHECK_CLOSE(M[0][0], static_cast<T>(0.696367031483999), 1e-3f);
	BOOST_CHECK_CLOSE(M[0][1], static_cast<T>(0.6963627001160001), 1e-3f);
	BOOST_CHECK_CLOSE(M[0][2], static_cast<T>(-0.17364002904), 1e-3f);
	BOOST_CHECK_SMALL(M[0][3], static_cast<T>(1e-7f));
	BOOST_CHECK_CLOSE(M[1][0], static_cast<T>(-0.62246796936), 1e-3f);
	BOOST_CHECK_CLOSE(M[1][1], static_cast<T>(0.706459172124), 1e-3f);
	BOOST_CHECK_CLOSE(M[1][2], static_cast<T>(0.336820447316), 1e-3f);
	BOOST_CHECK_SMALL(M[1][3], static_cast<T>(1e-7f));
	BOOST_CHECK_CLOSE(M[2][0], static_cast<T>(0.357219116116), 1e-3f);
	BOOST_CHECK_CLOSE(M[2][1], static_cast<T>(-0.12646492199), 1e-3f);
	BOOST_CHECK_CLOSE(M[2][2], static_cast<T>(0.925419288444), 1e-3f);
	BOOST_CHECK_SMALL(M[2][3], static_cast<T>(1e-7f));
	BOOST_CHECK_SMALL(M[3][0], static_cast<T>(1e-7f));
	BOOST_CHECK_SMALL(M[3][1], static_cast<T>(1e-7f));
	BOOST_CHECK_SMALL(M[3][2], static_cast<T>(1e-7f));
	BOOST_CHECK_CLOSE(M[3][3], static_cast<T>(1.0), 1e-3f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H3;
	H3.x = static_cast<T>(20.12);
	H3.y = static_cast<T>(100.89);
	H3.z = static_cast<T>(-18.2);
	H3.w = static_cast<T>(35.62);
	BOOST_CHECK(H1 != H2);
	BOOST_CHECK(H2 != H3);
	BOOST_CHECK(H1 == H1);
	BOOST_CHECK(H1 == H3);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	T dot = math::core::Quaternion<T>::dot(H1, H2);
	BOOST_CHECK_CLOSE(dot, static_cast<T>(-8859.505), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, float_types) {
	math::core::Quaternion<T> H1;
	H1.x = static_cast<T>(20.12);
	H1.y = static_cast<T>(100.89);
	H1.z = static_cast<T>(-18.2);
	H1.w = static_cast<T>(35.62);
	math::core::Quaternion<T> H2;
	H2.x = static_cast<T>(10.34);
	H2.y = static_cast<T>(-15.5);
	H2.z = static_cast<T>(20.2);
	H2.w = static_cast<T>(-200.34);
	math::core::Quaternion<T> H_lerp;
	H_lerp = math::core::Quaternion<T>::lerp(H1, H2, static_cast<T>(0.5));
	BOOST_CHECK_CLOSE(H_lerp.x, static_cast<T>(15.23), 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.y, static_cast<T>(42.695), 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.z, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.w, static_cast<T>(-82.36), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(slerp, T, float_types) {
	math::core::Quaternion<T> H1(
		math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)),
		math::radians(static_cast<T>(20.0)));
	math::core::Quaternion<T> H2(
		math::core::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)),
		math::radians(static_cast<T>(40.0)));
	math::core::Quaternion<T> Hs = math::core::Quaternion<T>::slerp(H1, H2, static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(Hs.x, H1.x, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.y, H1.y, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.z, H1.z, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.w, H1.w, 1e-4f);
	Hs = math::core::Quaternion<T>::slerp(H1, H2, static_cast<T>(1.0));
	BOOST_CHECK_CLOSE(Hs.x, H2.x, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.y, H2.y, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.z, H2.z, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.w, H2.w, 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
