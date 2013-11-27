#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Vector3)

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Vector3 V_default;
	BOOST_CHECK_SMALL(V_default.x, 1e-10f);
	BOOST_CHECK_SMALL(V_default.y, 1e-10f);
	BOOST_CHECK_SMALL(V_default.z, 1e-10f);
	// parameterized constructor
	math::Vector3 V_param(1.0f, 2.0f, 3.0f);
	BOOST_CHECK_CLOSE(V_param.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.y, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.z, 3.0f, 1e-5f);
	// copy vector2
	math::Vector2 V2;
	V2.x = 3.0f;
	V2.y = 2.0f;
	math::Vector3 V_param2(V2, 1.0f);
	BOOST_CHECK_CLOSE(V_param2.x, 3.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param2.y, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param2.z, 1.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	math::Vector3 V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.z, V.z, 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	math::Vector3 V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.z, V.z, 1e-5f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	V.r = 100.89f;
	V.g = 20.12f;
	V.b = -18.2f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	V.s = 20.12f;
	V.t = 100.89f;
	V.p = -18.2f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	math::Vector3 V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.z, V.z, 1e-5f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	math::Vector3 V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, -20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.y, -100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.z, 18.2f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.z, 2.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.z, 2.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.z, -38.4f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.z, -38.4f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, -367.64f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, -367.64f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, -0.900990099009901f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div_eq) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, -0.900990099009901f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	math::Vector3 V_mult;
	V_mult = s * V;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, 626.99f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	math::Vector3 V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, 0.5283018867924527f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mag) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 104.47414273397987f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, 1e-10f);
}

BOOST_AUTO_TEST_CASE(mag2) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 10914.8465f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normal) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	math::Vector3 V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, 0.19258353764367417f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.96569346754615f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.z, -0.17420578454845276f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_SMALL(V_norm.y, 1e-10f);
	BOOST_CHECK_SMALL(V_norm.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normalize) {
	math::Vector3 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, 0.19258353764367417f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 0.96569346754615f, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, -0.17420578454845276f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	math::Vector3 V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_SMALL(V.y, 1e-10f);
	BOOST_CHECK_SMALL(V.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = -18.2f;
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE(dot) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	float dot = math::Vector3::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, -1723.3942f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(cross) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 cross = math::Vector3::cross(V1, V2);
	BOOST_CHECK_CLOSE(cross.x, 1755.878f, 1e-5f);
	BOOST_CHECK_CLOSE(cross.y, -594.612061f, 1e-5f);
	BOOST_CHECK_CLOSE(cross.z, -1355.0626f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(reflect) {
	math::Vector3 I;
	I.x = -1.0f;
	I.y = -1.0f;
	I.z = 0.0f;
	math::Vector3 N;
	N.x = 1.0f;
	N.y = 0.0f;
	N.z = 0.0f;
	math::Vector3 R = math::Vector3::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -1.0f, 1e-5f);
	BOOST_CHECK_SMALL(R.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(refract) {
	math::Vector3 I;
	I.x = -1.0f;
	I.y = -1.0f;
	I.z = 0.0f;
	math::Vector3 N;
	N.x = 1.0f;
	N.y = 0.0f;
	N.z = 0.0f;
	float eta = 0.2f;
	math::Vector3 R = math::Vector3::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, -1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -0.2f, 1e-5f);
	BOOST_CHECK_SMALL(R.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(lerp) {
	math::Vector3 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	math::Vector3 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	math::Vector3 V_lerp;
	V_lerp = math::Vector3::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, 15.23f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.y, 42.695f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.z, 1.0f, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
