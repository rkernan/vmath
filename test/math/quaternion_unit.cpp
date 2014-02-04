#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <utility>

#include <math/types.hpp>

BOOST_AUTO_TEST_SUITE(Quaternion)

BOOST_AUTO_TEST_CASE(create) {
	// default constructor
	math::Quaternion H_default;
	BOOST_CHECK_SMALL(H_default.x, 1e-7f);
	BOOST_CHECK_SMALL(H_default.y, 1e-7f);
	BOOST_CHECK_SMALL(H_default.z, 1e-7f);
	// parameterized constructor
	math::Quaternion H_param(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_CLOSE(H_param.x, 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_param.y, 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_param.z, 3.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_param.w, 4.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(from_axis_angle) {
	math::Quaternion H_param2(math::Vector3(1.0f, 0.0f, 0.0f), math::radians(90.0f));
	BOOST_CHECK_CLOSE(H_param2.x, 0.707106769f, 1e-4f);
	BOOST_CHECK_SMALL(H_param2.y, 1e-7f);
	BOOST_CHECK_SMALL(H_param2.z, 1e-7f);
	BOOST_CHECK_CLOSE(H_param2.w, 0.707106769f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(from_euler) {
	math::Quaternion H_param3(math::radians(90.0f), 0.0f, 0.0f);
	BOOST_CHECK_CLOSE(H_param3.x, 0.707106769f, 1e-4f);
	BOOST_CHECK_SMALL(H_param3.y, 1e-7f);
	BOOST_CHECK_SMALL(H_param3.z, 1e-7f);
	BOOST_CHECK_CLOSE(H_param3.w, 0.707106769f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(from_matrix4) {
	math::Matrix4 M;
	M[0][0] = 0.696367031483999f;
	M[0][1] = 0.6963627001160001f;
	M[0][2] = -0.17364002904f;
	M[0][3] = 0.0f;
	M[1][0] = -0.62246796936f;
	M[1][1] = 0.706459172124f;
	M[1][2] = 0.336820447316f;
	M[1][3] = 0.0f;
	M[2][0] = 0.357219116116f;
	M[2][1] = -0.12646492199f;
	M[2][2] = 0.925419288444f;
	M[2][3] = 0.0f;
	M[3][0] = 0.0f;
	M[3][1] = 0.0f;
	M[3][2] = 0.0f;
	M[3][3] = 1.0f;
	math::Quaternion H(M);
	BOOST_CHECK_CLOSE(H.x, 0.126973f, 1e-3f);
	BOOST_CHECK_CLOSE(H.y, 0.145493f, 1e-3f);
	BOOST_CHECK_CLOSE(H.z, 0.361453f, 1e-3f);
	BOOST_CHECK_CLOSE(H.w, 0.912173f, 1e-3f);
}

BOOST_AUTO_TEST_CASE(copy) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.63f;
	math::Quaternion H_copy(H);
	BOOST_CHECK_CLOSE(H_copy.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_copy.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE(move) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	math::Quaternion H_move(std::move(H));
	BOOST_CHECK_CLOSE(H_move.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_move.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE(members) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	BOOST_CHECK_CLOSE(H[0], H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H[1], H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H[2], H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H[3], H.w, 1e-4f);
	H[0] = 100.89f;
	H[1] = -18.2f;
	H[2] = 35.62f;
	H[3] = 20.12f;
	BOOST_CHECK_CLOSE(H[0], H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H[1], H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H[2], H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H[3], H.w, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(H[4], std::out_of_range);
	BOOST_CHECK_THROW(H[4] = 0.0f, std::out_of_range);
}

BOOST_AUTO_TEST_CASE(assign) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	math::Quaternion H_assign;
	H_assign = H;
	BOOST_CHECK_CLOSE(H_assign.x, H.x, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.y, H.y, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.z, H.z, 1e-4f);
	BOOST_CHECK_CLOSE(H_assign.w, H.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE(negate) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	math::Quaternion H_neg;
	H_neg = -H;
	BOOST_CHECK_CLOSE(H_neg.x, -20.12f, 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.y, -100.89f, 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.z, 18.2f, 1e-4f);
	BOOST_CHECK_CLOSE(H_neg.w, -35.62f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_add;
	H_add = H1 + H2;
	BOOST_CHECK_CLOSE(H_add.x, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.y, 85.39f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.z, 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.w, -164.72f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add_eq) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_add = H1;
	H_add += H2;
	BOOST_CHECK_CLOSE(H_add.x, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.y, 85.39f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.z, 2.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_add.w, -164.72f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(sub) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_sub;
	H_sub = H1 - H2;
	BOOST_CHECK_CLOSE(H_sub.x, 9.78f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.y, 116.39f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.z, -38.4f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.w, 235.96f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(sub_eq) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_sub = H1;
	H_sub -= H2;
	BOOST_CHECK_CLOSE(H_sub.x, 9.78f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.y, 116.39f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.z, -38.4f, 1e-4f);
	BOOST_CHECK_CLOSE(H_sub.w, 235.96f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_mult;
	H_mult = H1 * H2;
	BOOST_CHECK_CLOSE(H_mult.x, -1906.652f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, -21359.0246f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, 3010.6493f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, -5412.7166f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult_eq) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_mult = H1;
	H_mult *= H2;
	BOOST_CHECK_CLOSE(H_mult.x, -1906.652f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, -21359.0246f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, 3010.6493f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, -5412.7166f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(vector3_mult) {
	math::Quaternion H;
	H.x = 0.3651483655f;
	H.y = 0.5477225184f;
	H.z = 0.7302967310f;
	H.w = 0.1825741827f;
	math::Vector3 V;
	V.x = 1.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	math::Vector3 V_rot;
	V_rot = H * V;
	BOOST_CHECK_CLOSE(V_rot.x, -0.6666666269f, 1e-4f);
	BOOST_CHECK_CLOSE(V_rot.y, 0.6666666269f, 1e-4f);
	BOOST_CHECK_CLOSE(V_rot.z, 0.3333333135f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	float s = -34.45f;
	math::Quaternion H_mult;
	H_mult = H * s;
	BOOST_CHECK_CLOSE(H_mult.x, -693.134f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.y, -3475.6605f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.z, 626.99f, 1e-4f);
	BOOST_CHECK_CLOSE(H_mult.w, -1227.109f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	float s = -34.45f;
	math::Quaternion H_div;
	H_div = H / s;
	BOOST_CHECK_CLOSE(H_div.x, -0.5840348330914369f, 1e-4f);
	BOOST_CHECK_CLOSE(H_div.y, -2.9285921625544264f, 1e-4f);
	BOOST_CHECK_CLOSE(H_div.z, 0.5283018867924527f, 1e-4f);
	BOOST_CHECK_CLOSE(H_div.w, -1.0339622641509432f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mag) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	float mag = H.mag();
	BOOST_CHECK_CLOSE(mag, 110.37948586580751f, 1e-4f);
	H.x = 1.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	mag = H.mag();
	BOOST_CHECK_CLOSE(mag, 1.0f, 1e-4f);
	H.x = 0.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	mag = H.mag();
	BOOST_CHECK_SMALL(mag, 1e-7f);
}

BOOST_AUTO_TEST_CASE(mag2) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	float mag2 = H.mag2();
	BOOST_CHECK_CLOSE(mag2, 12183.6309f, 1e-4f);
	H.x = 1.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	mag2 = H.mag2();
	BOOST_CHECK_CLOSE(mag2, 1.0f, 1e-4f);
	H.x = 0.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	mag2 = H.mag2();
	BOOST_CHECK_SMALL(mag2, 1e-7f);
}

BOOST_AUTO_TEST_CASE(normal) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	math::Quaternion H_norm(H.normal());
	BOOST_CHECK_CLOSE(H_norm.x, 0.18228024747696905f, 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.y, 0.914028537145233f, 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.z, -0.16488571093841137f, 1e-4f);
	BOOST_CHECK_CLOSE(H_norm.w, 0.32270489140803366f, 2e-5f);
	H.x = 1.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	H_norm = H.normal();
	BOOST_CHECK_CLOSE(H_norm.x, 1.0f, 1e-4f);
	BOOST_CHECK_SMALL(H_norm.y, 1e-7f);
	BOOST_CHECK_SMALL(H_norm.z, 1e-7f);
}

BOOST_AUTO_TEST_CASE(normalize) {
	math::Quaternion H;
	H.x = 20.12f;
	H.y = 100.89f;
	H.z = -18.2f;
	H.w = 35.62f;
	H.normalize();
	BOOST_CHECK_CLOSE(H.x, 0.18228024747696905f, 1e-4f);
	BOOST_CHECK_CLOSE(H.y, 0.914028537145233f, 1e-4f);
	BOOST_CHECK_CLOSE(H.z, -0.16488571093841137f, 1e-4f);
	BOOST_CHECK_CLOSE(H.w, 0.32270489140803366f, 2e-5f);
	H.x = 1.0f;
	H.y = 0.0f;
	H.z = 0.0f;
	H.w = 0.0f;
	math::Quaternion H_norm;
	H_norm = H.normalize();
	BOOST_CHECK_CLOSE(H_norm.x, 1.0f, 1e-4f);
	BOOST_CHECK_SMALL(H.y, 1e-7f);
	BOOST_CHECK_SMALL(H.z, 1e-7f);
	BOOST_CHECK_SMALL(H.w, 1e-7f);
}

BOOST_AUTO_TEST_CASE(inverse) {
	math::Quaternion H;
	H.x = 2.0f;
	H.y = 4.0f;
	H.z = 2.0f;
	H.w = 4.0f;
	math::Quaternion H_inv = H.inverse();
	BOOST_CHECK_CLOSE(H_inv.x, -0.05, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.y, -0.1f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, -0.05f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, 0.1f, 1e-4f);
	H.x = 0.5f;
	H.y = 0.5f;
	H.z = 0.5f;
	H.w = 0.5f;
	H_inv = H.inverse();
	BOOST_CHECK_CLOSE(H_inv.x, -0.5, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.y, -0.5f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, -0.5f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, 0.5f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(invert) {
	math::Quaternion H;
	H.x = 2.0f;
	H.y = 4.0f;
	H.z = 2.0f;
	H.w = 4.0f;
	H.invert();
	BOOST_CHECK_CLOSE(H.x, -0.05, 1e-4f);
	BOOST_CHECK_CLOSE(H.y, -0.1f, 1e-4f);
	BOOST_CHECK_CLOSE(H.z, -0.05f, 1e-4f);
	BOOST_CHECK_CLOSE(H.w, 0.1f, 1e-4f);
	H.x = 0.5f;
	H.y = 0.5f;
	H.z = 0.5f;
	H.w = 0.5f;
	math::Quaternion H_inv = H.invert();
	BOOST_CHECK_CLOSE(H_inv.x, -0.5, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.y, -0.5f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.z, -0.5f, 1e-4f);
	BOOST_CHECK_CLOSE(H_inv.w, 0.5f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(to_euler_angles) {
	math::Quaternion H;
	H.x = 0.126973f;
	H.y = 0.145493f;
	H.z = 0.361453f;
	H.w = 0.912173f;
	BOOST_CHECK_CLOSE(H.pitch(), 0.349062055f, 1e-4f);
	BOOST_CHECK_CLOSE(H.yaw(), 0.174524635f, 1e-4f);
	BOOST_CHECK_CLOSE(H.roll(), 0.785396338f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(to_axis_angle) {
	math::Quaternion H(math::Vector3(1.0f, 1.0f, 0.0f), math::radians(22.0f));
	BOOST_CHECK_CLOSE(H.axis().x, 0.707106829f, 1e-4f);
	BOOST_CHECK_CLOSE(H.axis().y, 0.707106829f, 1e-4f);
	BOOST_CHECK_SMALL(H.axis().z, 1e-7f);
	BOOST_CHECK_CLOSE(H.angle(), math::radians(22.0f), 1e-4f);
}

BOOST_AUTO_TEST_CASE(to_matrix4) {
	math::Quaternion H;
	H.x = 0.126973f;
	H.y = 0.145493f;
	H.z = 0.361453f;
	H.w = 0.912173f;
	math::Matrix4 M;
	M = H.matrix4();
	BOOST_CHECK_CLOSE(M[0][0], 0.696367031483999f, 1e-3f);
	BOOST_CHECK_CLOSE(M[0][1], 0.6963627001160001f, 1e-3f);
	BOOST_CHECK_CLOSE(M[0][2], -0.17364002904f, 1e-3f);
	BOOST_CHECK_CLOSE(M[0][3], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[1][0], -0.62246796936f, 1e-3f);
	BOOST_CHECK_CLOSE(M[1][1], 0.706459172124f, 1e-3f);
	BOOST_CHECK_CLOSE(M[1][2], 0.336820447316f, 1e-3f);
	BOOST_CHECK_CLOSE(M[1][3], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[2][0], 0.357219116116f, 1e-3f);
	BOOST_CHECK_CLOSE(M[2][1], -0.12646492199f, 1e-3f);
	BOOST_CHECK_CLOSE(M[2][2], 0.925419288444f, 1e-3f);
	BOOST_CHECK_CLOSE(M[2][3], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[3][0], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[3][1], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[3][2], 0.0f, 1e-3f);
	BOOST_CHECK_CLOSE(M[3][3], 1.0f, 1e-3f);
}

BOOST_AUTO_TEST_CASE(equals) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H3;
	H3.x = 20.12f;
	H3.y = 100.89f;
	H3.z = -18.2f;
	H3.w = 35.62f;
	BOOST_CHECK(H1 != H2);
	BOOST_CHECK(H2 != H3);
	BOOST_CHECK(H1 == H1);
	BOOST_CHECK(H1 == H3);
}

BOOST_AUTO_TEST_CASE(dot) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	float dot = math::Quaternion::dot(H1, H2);
	BOOST_CHECK_CLOSE(dot, -8859.505f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(lerp) {
	math::Quaternion H1;
	H1.x = 20.12f;
	H1.y = 100.89f;
	H1.z = -18.2f;
	H1.w = 35.62f;
	math::Quaternion H2;
	H2.x = 10.34f;
	H2.y = -15.5f;
	H2.z = 20.2f;
	H2.w = -200.34f;
	math::Quaternion H_lerp;
	H_lerp = math::Quaternion::lerp(H1, H2, 0.5f);
	BOOST_CHECK_CLOSE(H_lerp.x, 15.23f, 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.y, 42.695f, 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.z, 1.0f, 1e-4f);
	BOOST_CHECK_CLOSE(H_lerp.w, -82.36f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(slerp) {
	math::Quaternion H1(math::Vector3(1.0f, 0.0f, 0.0f), math::radians(20.0f));
	math::Quaternion H2(math::Vector3(1.0f, 0.0f, 0.0f), math::radians(40.0f));
	math::Quaternion Hs = math::Quaternion::slerp(H1, H2, 0.0f);
	BOOST_CHECK_CLOSE(Hs.x, H1.x, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.y, H1.y, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.z, H1.z, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.w, H1.w, 1e-4f);
	Hs = math::Quaternion::slerp(H1, H2, 1.0f);
	BOOST_CHECK_CLOSE(Hs.x, H2.x, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.y, H2.y, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.z, H2.z, 1e-4f);
	BOOST_CHECK_CLOSE(Hs.w, H2.w, 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
