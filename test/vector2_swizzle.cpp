#define BOOST_TEST_MODULE vector2_swizzle
#include "boost_test_config.hpp"

#include <vmath/vector2.hpp>
#include <vmath/vector_functions.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	// TODO
}

// TODO mag
// TODO mag2
// TODO normal
// TODO normalize
// TODO dot
// TODO cross
// TODO lerp
// TODO reflect
// TODO refract
// TODO equals
// TODO equals_op_int
// TODO equals_op_float

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	auto a = v + v.xx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(121.01), TOLERANCE);
	auto b = v.xx + v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(121.01), TOLERANCE);
	auto c = v.xx + v.xx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(40.24), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	auto a = v - v.xx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(0.0), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(80.77), TOLERANCE);
	auto b = v.xx - v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(0.0), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(-80.77), TOLERANCE);
	auto c = v.xx - v.xx;
	BOOST_CHECK_SMALL(c.x, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(c.y, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	auto a = v * v.xx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(2029.9068), TOLERANCE);
	auto b = v.xx * v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(2029.9068), TOLERANCE);
	auto c = v.xx * v.xx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(404.8144), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	auto a = v / v.xx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(5.01441351888668), TOLERANCE);
	auto b = v.xx / v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(0.1994251164634751), TOLERANCE);
	auto c = v.xx / v.xx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(1.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	T s = static_cast<T>(3.2);
	auto a = v.yx * s;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(322.848), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(64.384), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	T s = static_cast<T>(3.2);
	auto a = v.yx / s;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(31.528125), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(6.2875), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, floating_point_types) {
	// FIXME Possible to implicitly cast? Don't want to reimplement vmath::equals...
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(100.89), static_cast<T>(20.12));
	BOOST_CHECK(vmath::equals(v1, v2.yx()));
	BOOST_CHECK(vmath::equals(v1.yx(), v2));
	BOOST_CHECK(vmath::equals(v1.yx(), v2.xy()));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op, T, floating_point_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20.12), static_cast<T>(100.89));
	vmath::Vector<T, 2> v2(static_cast<T>(100.89), static_cast<T>(20.12));
	BOOST_CHECK(v1 == v2.yx);
	BOOST_CHECK(v1.yx == v2);
	BOOST_CHECK(v1.yx == v2.xy);
	BOOST_CHECK(v1.xy != v2.xy);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op_int, T, integral_types) {
	vmath::Vector<T, 2> v1(static_cast<T>(20), static_cast<T>(101));
	vmath::Vector<T, 2> v2(static_cast<T>(10), static_cast<T>(15));
	vmath::Vector<T, 2> v3(static_cast<T>(20), static_cast<T>(101));
	BOOST_CHECK(v1.xy != v2.xy);
	BOOST_CHECK(v2.xy != v3.xy);
	BOOST_CHECK(v1.xx == v1.xx);
	BOOST_CHECK(v1.yy == v3.yy);
}

#define CHECK_VECTOR2_SWIZZLE2(E1, E2) \
	BOOST_CHECK(sizeof(v. E1 ## E2) == 2 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 [1], v. E2, TOLERANCE);

#define CHECK_VECTOR2_SWIZZLE2_EXISTS(E1, E2) \
	v. E1 ## E2;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle2, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	CHECK_VECTOR2_SWIZZLE2(x, x)
	CHECK_VECTOR2_SWIZZLE2(x, y)
	CHECK_VECTOR2_SWIZZLE2(y, x)
	CHECK_VECTOR2_SWIZZLE2(y, y)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(s, s)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(s, t)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(t, s)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(t, t)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(r, r)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(r, g)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(g, r)
	CHECK_VECTOR2_SWIZZLE2_EXISTS(g, g)
}

#define CHECK_VECTOR2_SWIZZLE3(E1, E2, E3) \
	BOOST_CHECK(sizeof(v. E1 ## E2 ## E3) == 2 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [1], v. E2, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [2], v. E3, TOLERANCE);

#define CHECK_VECTOR2_SWIZZLE3_EXISTS(E1, E2, E3) \
	v. E1 ## E2 ## E3;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle3, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	CHECK_VECTOR2_SWIZZLE3(x, x, x)
	CHECK_VECTOR2_SWIZZLE3(x, x, y)
	CHECK_VECTOR2_SWIZZLE3(x, y, x)
	CHECK_VECTOR2_SWIZZLE3(x, y, y)
	CHECK_VECTOR2_SWIZZLE3(y, x, x)
	CHECK_VECTOR2_SWIZZLE3(y, x, y)
	CHECK_VECTOR2_SWIZZLE3(y, y, x)
	CHECK_VECTOR2_SWIZZLE3(y, y, y)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(s, s, s)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(s, s, t)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(s, t, s)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(s, t, t)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(t, s, s)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(t, s, t)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(t, t, s)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(t, t, t)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(r, r, r)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(r, r, g)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(r, g, r)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(r, g, g)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(g, r, r)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(g, r, g)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(g, g, r)
	CHECK_VECTOR2_SWIZZLE3_EXISTS(g, g, g)
}

#define CHECK_VECTOR2_SWIZZLE4(E1, E2, E3, E4) \
	BOOST_CHECK(sizeof(v. E1 ## E2 ## E3 ## E4) == 2 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [1], v. E2, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [2], v. E3, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [3], v. E4, TOLERANCE);

#define CHECK_VECTOR2_SWIZZLE4_EXISTS(E1, E2, E3, E4) \
	v. E1 ## E2 ## E3 ## E4;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle4, T, floating_point_types) {
	vmath::Vector<T, 2> v(static_cast<T>(20.12), static_cast<T>(100.89));
	CHECK_VECTOR2_SWIZZLE4(x, x, x, x)
	CHECK_VECTOR2_SWIZZLE4(x, x, x, y)
	CHECK_VECTOR2_SWIZZLE4(x, x, y, x)
	CHECK_VECTOR2_SWIZZLE4(x, x, y, y)
	CHECK_VECTOR2_SWIZZLE4(x, y, x, x)
	CHECK_VECTOR2_SWIZZLE4(x, y, x, y)
	CHECK_VECTOR2_SWIZZLE4(x, y, y, x)
	CHECK_VECTOR2_SWIZZLE4(x, y, y, y)
	CHECK_VECTOR2_SWIZZLE4(y, x, x, x)
	CHECK_VECTOR2_SWIZZLE4(y, x, x, y)
	CHECK_VECTOR2_SWIZZLE4(y, x, y, x)
	CHECK_VECTOR2_SWIZZLE4(y, x, y, y)
	CHECK_VECTOR2_SWIZZLE4(y, y, x, x)
	CHECK_VECTOR2_SWIZZLE4(y, y, x, y)
	CHECK_VECTOR2_SWIZZLE4(y, y, y, x)
	CHECK_VECTOR2_SWIZZLE4(y, y, y, y)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, s, s, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, s, s, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, s, t, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, s, t, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, t, s, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, t, s, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, t, t, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(s, t, t, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, s, s, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, s, s, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, s, t, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, s, t, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, t, s, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, t, s, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, t, t, s)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(t, t, t, t)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, r, r, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, r, r, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, r, g, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, r, g, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, g, r, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, g, r, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, g, g, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(r, g, g, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, r, r, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, r, r, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, r, g, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, r, g, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, g, r, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, g, r, g)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, g, g, r)
	CHECK_VECTOR2_SWIZZLE4_EXISTS(g, g, g, g)
}
