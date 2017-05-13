#define BOOST_TEST_MODULE vector3
#include "boost_test_config.hpp"

#include <stdexcept>
#include <vmath/vector3.hpp>
#include <vmath/vector_functions.hpp>


BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, floating_point_types) {
	BOOST_CHECK(sizeof(vmath::Vector<T, 3>) == 3 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_default, T, floating_point_types) {
	vmath::Vector<T, 3> v;
	BOOST_CHECK_SMALL(v.x, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(v.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(v.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(3.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_param_from_vector2, T, floating_point_types) {
	vmath::Vector<T, 3> v(vmath::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(2.0)), static_cast<T>(1.0));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(3.0), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(1.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_copy, T, floating_point_types) {
	vmath::Vector<T, 3> v(vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2)));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-18.2), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_move, T, floating_point_types) {
	vmath::Vector<T, 3> v(std::move(vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2))));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-18.2), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-18.2), TOLERANCE);
	BOOST_CHECK_CLOSE(v[0], v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v[1], v.y, TOLERANCE);
	BOOST_CHECK_CLOSE(v[2], v.z, TOLERANCE);
	BOOST_CHECK_CLOSE(v.s, v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v.t, v.y, TOLERANCE);
	BOOST_CHECK_CLOSE(v.p, v.z, TOLERANCE);
	BOOST_CHECK_CLOSE(v.r, v.x, TOLERANCE);
	BOOST_CHECK_CLOSE(v.g, v.y, TOLERANCE);
	BOOST_CHECK_CLOSE(v.b, v.z, TOLERANCE);
	// invalid index
	BOOST_CHECK_THROW(v[3], std::out_of_range);
	BOOST_CHECK_THROW(v[3] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-18.2), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	auto v = -vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-20.12), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-100.89), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(18.2), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2))
	         + vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(85.39), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(2.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v += vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(30.46), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(85.39), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(2.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2))
	         - vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(116.39), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-38.4), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v -= vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(9.78), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(116.39), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-38.4), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2))
	         * vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(208.0408), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-1563.795), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-367.64), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v *= vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(208.0408), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-1563.795), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-367.64), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2))
	         / vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.9458413926499034), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-6.509032258064516), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-0.900990099009901), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v /= vmath::Vector<T, 3>(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(1.9458413926499034), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-6.509032258064516), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-0.900990099009901), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2)) * static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-3475.6605), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(626.99), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v *= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-693.134), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-3475.6605), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(626.99), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) {
	auto v = vmath::Vector<T, 3>(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2)) / static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(0.5283018867924527), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v /= static_cast<T>(-34.45);
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(-0.5840348330914369), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(-2.9285921625544264), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(0.5283018867924527), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK_CLOSE(v.mag(), static_cast<T>(104.47414273397987), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(v.mag(), static_cast<T>(1.0), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(v.mag(), static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK_CLOSE(v.mag2(), static_cast<T>(10914.8465), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_CLOSE(v.mag2(), static_cast<T>(1.0), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
	BOOST_CHECK_SMALL(v.mag2(), static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	auto n = v.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(0.19258353764367417), TOLERANCE);
	BOOST_CHECK_CLOSE(n.y, static_cast<T>(0.96569346754615), TOLERANCE);
	BOOST_CHECK_CLOSE(n.z, static_cast<T>(-0.17420578454845276), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	n = v.normal();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(n.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(n.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	v.normalize();
	BOOST_CHECK_CLOSE(v.x, static_cast<T>(0.19258353764367417), TOLERANCE);
	BOOST_CHECK_CLOSE(v.y, static_cast<T>(0.96569346754615), TOLERANCE);
	BOOST_CHECK_CLOSE(v.z, static_cast<T>(-0.17420578454845276), TOLERANCE);
	v = vmath::Vector<T, 3>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	auto n = v.normalize();
	BOOST_CHECK_CLOSE(n.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_SMALL(n.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(n.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, floating_point_types) {
	vmath::Vector<T, 3> v1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	vmath::Vector<T, 3> v2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	BOOST_CHECK_CLOSE(vmath::dot(v1, v2), static_cast<T>(-1723.3942), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(cross, T, floating_point_types) {
	vmath::Vector<T, 3> v1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	vmath::Vector<T, 3> v2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	auto cross = vmath::cross(v1, v2);
	BOOST_CHECK_CLOSE(cross.x, static_cast<T>(1755.878), TOLERANCE);
	BOOST_CHECK_CLOSE(cross.y, static_cast<T>(-594.612061), TOLERANCE);
	BOOST_CHECK_CLOSE(cross.z, static_cast<T>(-1355.0626), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, floating_point_types) {
	vmath::Vector<T, 3> start(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	vmath::Vector<T, 3> end(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	auto lerp = vmath::lerp(start, end, static_cast<T>(0.5));
	BOOST_CHECK_CLOSE(lerp.x, static_cast<T>(15.23), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.y, static_cast<T>(42.695), TOLERANCE);
	BOOST_CHECK_CLOSE(lerp.z, static_cast<T>(1.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(reflect, T, floating_point_types) {
	vmath::Vector<T, 3> incident(static_cast<T>(-1.0), static_cast<T>(-1.0), static_cast<T>(0.0));
	vmath::Vector<T, 3> surface_normal(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	auto reflect = vmath::reflect(incident, surface_normal);
	BOOST_CHECK_CLOSE(reflect.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(reflect.y, static_cast<T>(-1.0), TOLERANCE);
	BOOST_CHECK_SMALL(reflect.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(refract, T, floating_point_types) {
	vmath::Vector<T, 3> incident(static_cast<T>(-1.0), static_cast<T>(-1.0), static_cast<T>(0.0));
	vmath::Vector<T, 3> surface_normal(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
	auto refraction = vmath::refract(incident, surface_normal, static_cast<T>(0.2));
	BOOST_CHECK_CLOSE(refraction.x, static_cast<T>(-1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(refraction.y, static_cast<T>(-0.2), TOLERANCE);
	BOOST_CHECK_SMALL(refraction.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, floating_point_types) {
	vmath::Vector<T, 3> v1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	vmath::Vector<T, 3> v2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	vmath::Vector<T, 3> v3(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK(!vmath::equals(v1, v2));
	BOOST_CHECK(!vmath::equals(v2, v3));
	BOOST_CHECK(vmath::equals(v1, v1));
	BOOST_CHECK(vmath::equals(v1, v3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op_int, T, integral_types) {
	vmath::Vector<T, 3> v1(static_cast<T>(20), static_cast<T>(101), static_cast<T>(18));
	vmath::Vector<T, 3> v2(static_cast<T>(10), static_cast<T>(15), static_cast<T>(20));
	vmath::Vector<T, 3> v3(static_cast<T>(20), static_cast<T>(101), static_cast<T>(18));
	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v2 != v3);
	BOOST_CHECK(v1 == v1);
	BOOST_CHECK(v1 == v3);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op_float, T, floating_point_types) {
	vmath::Vector<T, 3> v1(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	vmath::Vector<T, 3> v2(static_cast<T>(10.34), static_cast<T>(-15.5), static_cast<T>(20.2));
	vmath::Vector<T, 3> v3(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v2 != v3);
	BOOST_CHECK(v1 == v1);
	BOOST_CHECK(v1 == v3);
}
