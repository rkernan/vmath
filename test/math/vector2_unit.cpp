#include <stdexcept>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Vector2)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_CHECK_EQUAL(sizeof(math::Vector2), 2 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Vector2 V_default;
	BOOST_CHECK_SMALL(V_default.x, 1e-10f);
	BOOST_CHECK_SMALL(V_default.y, 1e-10f);
	// parameterized constructor
	math::Vector2 V_param(1.0f, 2.0f);
	BOOST_CHECK_CLOSE(V_param.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.y, 2.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	BOOST_CHECK_CLOSE(V.x, 20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	V.r = 100.89f;
	V.g = 20.12f;
	BOOST_CHECK_CLOSE(V.x, 100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	V.s = 20.12f;
	V.t = 100.89f;
	BOOST_CHECK_CLOSE(V.x, 20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	V[0] = 100.89f;
	V[1] = 20.12f;
	BOOST_CHECK_CLOSE(V.x, 100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	// invalid index
	BOOST_CHECK_THROW(V[2], std::out_of_range);
	BOOST_CHECK_THROW(V[2] = 0.0f, std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-5f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, -20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.y, -100.89f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div_eq) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_mult;
	V_mult = V * s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_mult = V;
	V_mult *= s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float s = -34.45f;
	math::Vector2 V_div = V;
	V_div /= s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mag) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 102.87665673028066f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, 1e-10f);
}

BOOST_AUTO_TEST_CASE(mag2) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	float mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 10583.6065f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normal) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	math::Vector2 V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, 0.19557400716034246f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.9806889454476615f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(normalize) {
	math::Vector2 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, 0.19557400716034246f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 0.9806889454476615f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	math::Vector2 V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE(dot) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	float dot = math::Vector2::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, -1355.7542f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(cross) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	float cross = math::Vector2::cross(V1, V2);
	BOOST_CHECK_CLOSE(cross, -1355.0626f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(reflect) {
	math::Vector2 I;
	I.x = -1.0f;
	I.y = -1.0f;
	math::Vector2 N;
	N.x = 1.0f;
	N.y = 0.0f;
	math::Vector2 R = math::Vector2::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -1.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(refract) {
	math::Vector2 I;
	I.x = -1.0f;
	I.y = -1.0f;
	math::Vector2 N;
	N.x = 1.0f;
	N.y = 0.0f;
	float eta = 0.2f;
	math::Vector2 R = math::Vector2::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, -1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -0.2f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(lerp) {
	math::Vector2 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	math::Vector2 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	math::Vector2 V_lerp;
	V_lerp = math::Vector2::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, 15.23f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.y, 42.695f, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
