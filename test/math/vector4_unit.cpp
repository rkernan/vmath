#include <stdexcept>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Vector4)

BOOST_AUTO_TEST_CASE(size) {
	BOOST_CHECK_EQUAL(sizeof(math::Vector4), 4 * sizeof(float));
}

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Vector4 V_default;
	BOOST_CHECK_SMALL(V_default.x, 1e-10f);
	BOOST_CHECK_SMALL(V_default.y, 1e-10f);
	BOOST_CHECK_SMALL(V_default.z, 1e-10f);
	// parameterized constructor
	math::Vector4 V_param(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_CLOSE(V_param.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.y, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.z, 3.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param.w, 4.0f, 1e-5f);
	// copy vector2
	math::Vector2 V2;
	V2.x = 4.0f;
	V2.y = 3.0f;
	math::Vector4 V_param2(V2, 2.0f, 1.0f);
	BOOST_CHECK_CLOSE(V_param2.x, 4.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param2.y, 3.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param2.z, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param2.w, 1.0f, 1e-5f);
	// copy vector3
	math::Vector3 V3;
	V3.x = 4.0f;
	V3.y = 3.0f;
	V3.z = 2.0f;
	math::Vector4 V_param3(V3, 1.0f);
	BOOST_CHECK_CLOSE(V_param3.x, 4.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param3.y, 3.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param3.z, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_param3.w, 1.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.63f;
	math::Vector4 V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.z, V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V_copy.w, V.w, 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	math::Vector4 V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.z, V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V_move.w, V.w, 1e-5f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-5f);
	V.r = 35.62f;
	V.g = 20.12f;
	V.b = 100.89f;
	V.a = -18.2f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-5f);
	V.s = -18.2f;
	V.t = 35.62f;
	V.p = 20.12f;
	V.a = 100.89f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-5f);
	V[0] = 100.89f;
	V[1] = -18.2f;
	V[2] = 35.62f;
	V[3] = 20.12f;
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-5f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-5f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-5f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-5f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-5f);
	// invalid index
	BOOST_CHECK_THROW(V[4], std::out_of_range);
	BOOST_CHECK_THROW(V[4] = 0.0f, std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	math::Vector4 V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.z, V.z, 1e-5f);
	BOOST_CHECK_CLOSE(V_assign.w, V.w, 1e-5f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	math::Vector4 V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, -20.12f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.y, -100.89f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.z, 18.2f, 1e-5f);
	BOOST_CHECK_CLOSE(V_neg.w, -35.62f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.z, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.w, -164.72f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.y, 85.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.z, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_add.w, -164.72f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.z, -38.4f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.w, 235.96f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.y, 116.39f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.z, -38.4f, 1e-5f);
	BOOST_CHECK_CLOSE(V_sub.w, 235.96f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, -367.64f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.w, -7136.11079999999995f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, 208.0408f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -1563.795f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, -367.64f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.w, -7136.11079999999995f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, -0.900990099009901f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.w, -0.17779774383547967f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(div_eq) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, 1.9458413926499034f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -6.509032258064516f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, -0.900990099009901f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.w, -0.17779774383547967f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float s = -34.45f;
	math::Vector4 V_mult;
	V_mult = V * s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, 626.99f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.w, -1227.109f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float s = -34.45f;
	math::Vector4 V_mult = V;
	V_mult *= s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.z, 626.99f, 1e-5f);
	BOOST_CHECK_CLOSE(V_mult.w, -1227.109f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float s = -34.45f;
	math::Vector4 V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, 0.5283018867924527f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.w, -1.0339622641509432f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float s = -34.45f;
	math::Vector4 V_div = V;
	V_div /= s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.z, 0.5283018867924527f, 1e-5f);
	BOOST_CHECK_CLOSE(V_div.w, -1.0339622641509432f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(mag) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 110.37948586580751f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, 1e-10f);
}

BOOST_AUTO_TEST_CASE(mag2) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	float mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 12183.6309f, 1e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, 1.0f, 1e-5f);
	V.x = 0.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normal) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	math::Vector4 V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, 0.18228024747696905f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.y, 0.914028537145233f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.z, -0.16488571093841137f, 1e-5f);
	BOOST_CHECK_CLOSE(V_norm.w, 0.32270489140803366f, 2e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_SMALL(V_norm.y, 1e-10f);
	BOOST_CHECK_SMALL(V_norm.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(normalize) {
	math::Vector4 V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	V.w = 35.62f;
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, 0.18228024747696905f, 1e-5f);
	BOOST_CHECK_CLOSE(V.y, 0.914028537145233f, 1e-5f);
	BOOST_CHECK_CLOSE(V.z, -0.16488571093841137f, 1e-5f);
	BOOST_CHECK_CLOSE(V.w, 0.32270489140803366f, 2e-5f);
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	V.w = 0.0f;
	math::Vector4 V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, 1.0f, 1e-5f);
	BOOST_CHECK_SMALL(V.y, 1e-10f);
	BOOST_CHECK_SMALL(V.z, 1e-10f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = -18.2f;
	V3.w = 35.62f;
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE(dot) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	float dot = math::Vector4::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, -8859.505f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(reflect) {
	math::Vector4 I;
	I.x = -1.0f;
	I.y = -1.0f;
	I.z = 0.0f;
	I.w = 0.0f;
	math::Vector4 N;
	N.x = 1.0f;
	N.y = 0.0f;
	N.z = 0.0f;
	N.w = 0.0f;
	math::Vector4 R = math::Vector4::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -1.0f, 1e-5f);
	BOOST_CHECK_SMALL(R.z, 1e-10f);
	BOOST_CHECK_SMALL(R.w, 1e-10f);
}

BOOST_AUTO_TEST_CASE(refract) {
	math::Vector4 I;
	I.x = -1.0f;
	I.y = -1.0f;
	I.z = 0.0f;
	I.w = 0.0f;
	math::Vector4 N;
	N.x = 1.0f;
	N.y = 0.0f;
	N.z = 0.0f;
	N.w = 0.0f;
	float eta = 0.2f;
	math::Vector4 R = math::Vector4::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, -1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(R.y, -0.2f, 1e-5f);
	BOOST_CHECK_SMALL(R.z, 1e-10f);
	BOOST_CHECK_SMALL(R.w, 1e-10f);
}

BOOST_AUTO_TEST_CASE(lerp) {
	math::Vector4 V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	V1.w = 35.62f;
	math::Vector4 V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	V2.w = -200.34f;
	math::Vector4 V_lerp;
	V_lerp = math::Vector4::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, 15.23f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.y, 42.695f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.z, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(V_lerp.w, -82.36f, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
