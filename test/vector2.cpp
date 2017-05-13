#define BOOST_TEST_MODULE vector2
#include "boost_test_config.hpp"

#include <stdexcept>
#include <vmath/vector2.hpp>
#include <vmath/vector_functions.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, floating_point_types) {
	BOOST_CHECK(sizeof(vmath::Vector<T, 2>) == 2 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor, T, floating_point_types) {
	vmath::Vector<T, 2> v;
	BOOST_CHECK_SMALL(v.x, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(v.y, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(1.0), static_cast<T>(2.0));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(2.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_copy, T, floating_point_types) {
	vmath::Vector<T, 2> v(vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89)));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_move, T, floating_point_types) {
	vmath::Vector<T, 2> v(std::move(vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89))));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v[0], v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v[1], v.y, TOLERANCE);
	BOOST_CHECK_CLOSE(v.s, v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v.t, v.y, TOLERANCE);
	BOOST_CHECK_CLOSE(v.r, v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v.g, v.y, TOLERANCE);
	// invalid index
	BOOST_CHECK_THROW(v[2], std::out_of_range);
	BOOST_CHECK_THROW(v[2] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	auto v = -vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-100.89), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89))
		+ vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(85.39), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v += vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(85.39), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89))
		- vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(116.39), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v -= vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(116.39), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89))
		* vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(208.0408), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-1563.795), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v *= vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(208.0408), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-1563.795), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89))
		/ vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.9458413926499034), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-6.509032258064516), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v /= vmath::Vector<T, 2>(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.9458413926499034), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-6.509032258064516), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89)) * static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-3475.6605), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v *= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-3475.6605), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 2>(static_cast<T>(20.12), static_cast<T>(100.89)) / static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v /= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK_CLOSE(v.mag(), static_cast<T>(102.87665673028066), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(v.mag(), static_cast<T>(1.0), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(v.mag(), static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK_CLOSE(v.mag2(), static_cast<T>(10583.6065), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(v.mag2(), static_cast<T>(1.0), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(v.mag2(), static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	auto n = v.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(0.19557400716034246), TOLERANCE);
	BOOST_CHECK_CLOSE(n.y, static_cast<T>(0.9806889454476615), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(0.0));
	n = v.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(n.y, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	v.normalize();
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(0.19557400716034246), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(0.9806889454476615), TOLERANCE);
	v = vmath::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(0.0));
	v.normalize();
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(v.y, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, floating_point_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(vmath::dot(v1, v2), static_cast<T>(-1355.7542), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(cross, T, floating_point_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(10.34), static_cast<T>(-15.5));
	BOOST_CHECK_CLOSE(vmath::cross(v1, v2), static_cast<T>(-1355.0626), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, floating_point_types) {
	vmath::Vector<T, 2> start(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> end(static_cast<T>(10.34), static_cast<T>(-15.5));
	auto lerp = vmath::lerp(start, end, static_cast<T>(0.5));
	BOOST_CHECK_CLOSE(lerp.x, static_cast<T>(15.23), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.y, static_cast<T>(42.695), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(reflect, T, floating_point_types) {
	vmath::Vector<T, 2> incident(static_cast<T>(-1.0), static_cast<T>(-1.0));
	vmath::Vector<T, 2> surface_normal(static_cast<T>(1.0), static_cast<T>(0.0));
	auto reflection = vmath::reflect(incident, surface_normal);
	BOOST_CHECK_CLOSE(reflection.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(reflection.y, static_cast<T>(-1.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(refract, T, floating_point_types) {
	vmath::Vector<T, 2> incident(static_cast<T>(-1.0), static_cast<T>(-1.0));
	vmath::Vector<T, 2> surface_normal(static_cast<T>(1.0), static_cast<T>(0.0));
	auto refraction = vmath::refract(incident, surface_normal, static_cast<T>(0.2));
	BOOST_CHECK_CLOSE(refraction.x, static_cast<T>(-1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(refraction.y, static_cast<T>(-0.2), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, floating_point_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(10.34), static_cast<T>(-15.5));
	vmath::Vector<T, 2> v3(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK(!vmath::equals(v1, v2));
	BOOST_CHECK(!vmath::equals(v2, v3));
	BOOST_CHECK(vmath::equals(v1, v1));
	BOOST_CHECK(vmath::equals(v1, v3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op_int, T, integral_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20), static_cast<T>(101));
	vmath::Vector<T, 2> v2(static_cast<T>(10), static_cast<T>(15));
	vmath::Vector<T, 2> v3(static_cast<T>(20), static_cast<T>(101));
	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v2 != v3);
	BOOST_CHECK(v1 == v1);
	BOOST_CHECK(v1 == v3);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op_float, T, floating_point_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(10.34), static_cast<T>(-15.5));
	vmath::Vector<T, 2> v3(static_cast<T>(20.12), static_cast<T>(100.89));
	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v2 != v3);
	BOOST_CHECK(v1 == v1);
	BOOST_CHECK(v1 == v3);
}
