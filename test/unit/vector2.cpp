#include <stdexcept>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

#include <math/core/vector.hpp>

#include "../type_lists.hpp"

BOOST_AUTO_TEST_SUITE(vector2)

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, float_types) {
	BOOST_WARN(sizeof(math::core::vector<T, 2>) != 2 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	math::core::vector<T, 2> V_default;
	BOOST_CHECK_SMALL(V_default.x, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(V_default.y, static_cast<T>(1e-7));
	// parameterized constructor
	math::core::vector<T, 2> V_param(static_cast<T>(1.0), static_cast<T>(2.0));
	BOOST_CHECK_CLOSE(V_param.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param.y, static_cast<T>(2.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(100.89), 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	V.r = static_cast<T>(100.89);
	V.g = static_cast<T>(20.12);
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(100.89), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	V.s = 20.12f;
	V.t = 100.89f;
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(100.89), 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	V[0] = static_cast<T>(100.89);
	V[1] = static_cast<T>(20.12);
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(100.89), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(V[2], std::out_of_range);
	BOOST_CHECK_THROW(V[2] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, static_cast<T>(-20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.y, static_cast<T>(-100.89), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, static_cast<T>(85.39), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, static_cast<T>(85.39), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, static_cast<T>(116.39), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, static_cast<T>(116.39), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(208.0408), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-1563.795), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(208.0408), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-1563.795), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(1.9458413926499034), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-6.509032258064516), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(1.9458413926499034), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-6.509032258064516), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T s = static_cast<T>(-34.45);
	math::core::vector<T, 2> V_mult;
	V_mult = V * s;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(-693.134), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-3475.6605), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T s = static_cast<T>(-34.45);
	math::core::vector<T, 2> V_mult = V;
	V_mult *= s;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(-693.134), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-3475.6605), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T s = static_cast<T>(-34.45);
	math::core::vector<T, 2> V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(-0.5840348330914369), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-2.9285921625544264), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T s = static_cast<T>(-34.45);
	math::core::vector<T, 2> V_div = V;
	V_div /= s;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(-0.5840348330914369), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-2.9285921625544264), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T mag = V.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(102.87665673028066), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(1.0), 1e-4f);
	V.x = static_cast<T>(0.0);
	V.y = static_cast<T>(0.0);
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	T mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(10583.6065), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(1.0), 1e-4f);
	V.x = static_cast<T>(0.0);
	V.y = static_cast<T>(0.0);
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(0.19557400716034246), 1e-4f);
	BOOST_CHECK_CLOSE(V_norm.y, static_cast<T>(0.9806889454476615), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(V_norm.y, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, float_types) {
	math::core::vector<T, 2> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(0.19557400716034246), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(0.9806889454476615), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	math::core::vector<T, 2> V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(V_norm.y, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V3;
	V3.x = static_cast<T>(20.12);
	V3.y = static_cast<T>(100.89);
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	float dot = math::core::vector<T, 2>::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, static_cast<T>(-1355.7542), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(cross, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	float cross = math::core::vector<T, 2>::cross(V1, V2);
	BOOST_CHECK_CLOSE(cross, static_cast<T>(-1355.0626), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(reflect, T, float_types) {
	math::core::vector<T, 2> I;
	I.x = static_cast<T>(-1.0);
	I.y = static_cast<T>(-1.0);
	math::core::vector<T, 2> N;
	N.x = static_cast<T>(1.0);
	N.y = static_cast<T>(0.0);
	math::core::vector<T, 2> R = math::core::vector<T, 2>::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(R.y, static_cast<T>(-1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(refract, T, float_types) {
	math::core::vector<T, 2> I;
	I.x = static_cast<T>(-1.0);
	I.y = static_cast<T>(-1.0);
	math::core::vector<T, 2> N;
	N.x = static_cast<T>(1.0);
	N.y = static_cast<T>(0.0);
	T eta = static_cast<T>(0.2);
	math::core::vector<T, 2> R = math::core::vector<T, 2>::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(R.y, static_cast<T>(-0.2), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, float_types) {
	math::core::vector<T, 2> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	math::core::vector<T, 2> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	math::core::vector<T, 2> V_lerp;
	V_lerp = math::core::vector<T, 2>::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, static_cast<T>(15.23), 1e-4f);
	BOOST_CHECK_CLOSE(V_lerp.y, static_cast<T>(42.695), 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
