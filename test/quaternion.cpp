#define BOOST_TEST_MODULE quaternion
#include "boost_test_config.hpp"

#include <vmath/quaternion.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor, T, floating_point_types) {
	// default constructor
	vmath::Quaternion<T> h;
	BOOST_CHECK_SMALL(h.x, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(h.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(h.z, static_cast<T>(ZERO));

}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(4.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_from_axis_angle, T, floating_point_types) {
	vmath::Quaternion<T> H_param2(
		vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)),
		vmath::radians(static_cast<T>(90.0)));
	BOOST_CHECK_CLOSE(H_param2.x, static_cast<T>(0.707106769), TOLERANCE);
	BOOST_CHECK_SMALL(H_param2.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(H_param2.z, static_cast<T>(ZERO));
	BOOST_CHECK_CLOSE(H_param2.w, static_cast<T>(0.707106769), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_from_euler, T, floating_point_types) {
	vmath::Quaternion<T> H_param3(vmath::radians(static_cast<T>(90.0)), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(H_param3.x, static_cast<T>(0.707106769), TOLERANCE);
	BOOST_CHECK_SMALL(H_param3.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(H_param3.z, static_cast<T>(ZERO));
	BOOST_CHECK_CLOSE(H_param3.w, static_cast<T>(0.707106769), TOLERANCE);
}

/* BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_from_matrix4, T, floating_point_types) { */
/* 	vmath::Quaternion<T> h(vmath::Matrix<T, 4>([static_cast<T>(0.696367031483999), static_cast<T>(0.6963627001160001), static_cast<T>(-0.17364002904), static_cast<T>(0.0)], */
/* 	                                           [static_cast<T>(-0.62246796936), static_cast<T>(0.706459172124), static_cast<T>(0.336820447316), static_cast<T>(0.0)], */
/* 	                                           [static_cast<T>(0.357219116116), static_cast<T>(-0.12646492199), static_cast<T>(0.925419288444), static_cast<T>(0.0)], */
/* 	                                           [static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(1.0)])); */
/* 	BOOST_CHECK_CLOSE(h.x, static_cast<T>(0.126973), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(h.y, static_cast<T>(0.145493), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(h.z, static_cast<T>(0.361453), TOLERANCE); */
/* 	BOOST_CHECK_CLOSE(h.w, static_cast<T>(0.912173), TOLERANCE); */
/* } */

BOOST_AUTO_TEST_CASE_TEMPLATE(consturctor_copy, T, floating_point_types) {
	vmath::Quaternion<T> h(vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.63)));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(35.63), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_move, T, floating_point_types) {
	vmath::Quaternion<T> h(std::move(vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.63))));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(35.63), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(35.62), TOLERANCE);
	BOOST_CHECK_CLOSE(h[0], h.x, TOLERANCE);
	BOOST_CHECK_CLOSE(h[1], h.y, TOLERANCE);
	BOOST_CHECK_CLOSE(h[2], h.z, TOLERANCE);
	BOOST_CHECK_CLOSE(h[3], h.w, TOLERANCE);
	// invalid index
	BOOST_CHECK_THROW(h[4], std::out_of_range);
	BOOST_CHECK_THROW(h[4] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(35.62), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	auto h = -vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-35.62), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62))
	         + vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(85.39), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-164.72), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h += vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(85.39), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-164.72), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62))
	         - vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(116.39), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-38.4), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(235.96), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h -= vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(116.39), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-38.4), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(235.96), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62))
	         * vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-1906.652), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-21359.0246), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(3010.6493), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-5412.7166), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h *= vmath::Quaternion<T>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-1906.652), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-21359.0246), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(3010.6493), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-5412.7166), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(vector3_mult_op, T, floating_point_types) {
	auto v = vmath::Quaternion<T>(static_cast<T>(0.3651483655), static_cast<T>(0.5477225184), static_cast<T>(0.7302967310), static_cast<T>(0.1825741827))
	         * vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-0.6666666269), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(0.6666666269), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(0.3333333135), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62)) * static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-3475.6605), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(626.99), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-1227.109), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h *= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-3475.6605), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(626.99), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-1227.109), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) {
	auto h = vmath::Quaternion<T>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62)) / static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(0.5283018867924527), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-1.0339622641509432), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h /= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(0.5283018867924527), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(-1.0339622641509432), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK_CLOSE(h.mag(), static_cast<T>(110.37948586580751), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(h.mag(), static_cast<T>(1.0), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(h.mag(), static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK_CLOSE(h.mag2(), static_cast<T>(12183.6309), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(h.mag2(), static_cast<T>(1.0), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(h.mag2(), static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	auto n = h.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(0.18228024747696905), TOLERANCE);
	BOOST_CHECK_CLOSE(n.y, static_cast<T>(0.914028537145233), TOLERANCE);
	BOOST_CHECK_CLOSE(n.z, static_cast<T>(-0.16488571093841137), TOLERANCE);
	BOOST_CHECK_CLOSE(n.w, static_cast<T>(0.32270489140803366), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	n = h.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(n.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(n.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	h.normalize();
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(0.18228024747696905), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(0.914028537145233), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-0.16488571093841137), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(0.32270489140803366), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	auto n = h.normalize();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(n.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(n.z, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(n.w, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(inverse, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(2.0), static_cast<T>(4.0), static_cast<T>(2.0), static_cast<T>(4.0));
	auto i = h.inverse();
	BOOST_CHECK_CLOSE(i.x, static_cast<T>(-0.05), TOLERANCE);
	BOOST_CHECK_CLOSE(i.y, static_cast<T>(-0.1), TOLERANCE);
	BOOST_CHECK_CLOSE(i.z, static_cast<T>(-0.05), TOLERANCE);
	BOOST_CHECK_CLOSE(i.w, static_cast<T>(0.1), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(0.5), static_cast<T>(0.5), static_cast<T>(0.5), static_cast<T>(0.5));
	i = h.inverse();
	BOOST_CHECK_CLOSE(i.x, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.y, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.z, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.w, static_cast<T>(0.5), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(invert, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(2.0), static_cast<T>(4.0), static_cast<T>(2.0), static_cast<T>(4.0));
	h.invert();
	BOOST_CHECK_CLOSE(h.x, static_cast<T>(-0.05), TOLERANCE);
	BOOST_CHECK_CLOSE(h.y, static_cast<T>(-0.1), TOLERANCE);
	BOOST_CHECK_CLOSE(h.z, static_cast<T>(-0.05), TOLERANCE);
	BOOST_CHECK_CLOSE(h.w, static_cast<T>(0.1), TOLERANCE);
	h = vmath::Quaternion<T>(static_cast<T>(0.5), static_cast<T>(0.5), static_cast<T>(0.5), static_cast<T>(0.5));
	auto i = h.invert();
	BOOST_CHECK_CLOSE(i.x, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.y, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.z, static_cast<T>(-0.5), TOLERANCE);
	BOOST_CHECK_CLOSE(i.w, static_cast<T>(0.5), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(to_euler_angles, T, floating_point_types) {
	vmath::Quaternion<T> h(static_cast<T>(0.126973), static_cast<T>(0.145493), static_cast<T>(0.361453), static_cast<T>(0.912173));
	BOOST_CHECK_CLOSE(h.pitch(), static_cast<T>(0.349062055), TOLERANCE);
	BOOST_CHECK_CLOSE(h.yaw(), static_cast<T>(0.174524635), TOLERANCE);
	BOOST_CHECK_CLOSE(h.roll(), static_cast<T>(0.785396338), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(to_axis_angle, T, floating_point_types) {
	vmath::Quaternion<T> h(vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(1.0), static_cast<T>(0.0)),
	                       vmath::radians(static_cast<T>(22.0)));
	BOOST_CHECK_CLOSE(h.axis().x, static_cast<T>(0.707106829), TOLERANCE);
	BOOST_CHECK_CLOSE(h.axis().y, static_cast<T>(0.707106829), TOLERANCE);
	BOOST_CHECK_SMALL(h.axis().z, static_cast<T>(ZERO));
	BOOST_CHECK_CLOSE(h.angle(), vmath::radians(static_cast<T>(22.0)), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, floating_point_types) {
	vmath::Quaternion<T> h1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	vmath::Quaternion<T> h2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	BOOST_CHECK_CLOSE(vmath::dot(h1, h2), static_cast<T>(-8859.505), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, floating_point_types) {
	vmath::Quaternion<T> start(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	vmath::Quaternion<T> end(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	auto lerp = vmath::lerp(start, end, static_cast<T>(0.5));
	BOOST_CHECK_CLOSE(lerp.x, static_cast<T>(15.23), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.y, static_cast<T>(42.695), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.z, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.w, static_cast<T>(-82.36), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(slerp, T, floating_point_types) {
	vmath::Quaternion<T> start(vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)), vmath::radians(static_cast<T>(20.0)));
	vmath::Quaternion<T> end(vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)), vmath::radians(static_cast<T>(40.0)));
	auto slerp = vmath::slerp(start, end, static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(slerp.x, start.x, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.y, start.y, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.z, start.z, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.w, start.w, TOLERANCE);
	slerp = vmath::slerp(start, end, static_cast<T>(1.0));
	BOOST_CHECK_CLOSE(slerp.x, end.x, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.y, end.y, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.z, end.z, TOLERANCE);
	BOOST_CHECK_CLOSE(slerp.w, end.w, TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, floating_point_types) {
	vmath::Quaternion<T> h1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	vmath::Quaternion<T> h2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	vmath::Quaternion<T> h3(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK(!vmath::equals(h1, h2));
	BOOST_CHECK(!vmath::equals(h2, h3));
	BOOST_CHECK(vmath::equals(h1, h1));
	BOOST_CHECK(vmath::equals(h1, h3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op, T, floating_point_types) {
	vmath::Quaternion<T> h1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	vmath::Quaternion<T> h2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2), static_cast<T>(-200.34));
	vmath::Quaternion<T> h3(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2), static_cast<T>(35.62));
	BOOST_CHECK(h1 != h2);
	BOOST_CHECK(h2 != h3);
	BOOST_CHECK(h1 == h1);
	BOOST_CHECK(h1 == h3);
}
