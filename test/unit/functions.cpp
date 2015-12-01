#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

#include <vmath/functions.hpp>

#include "../type_lists.hpp"

BOOST_AUTO_TEST_SUITE(Math_Functions)

BOOST_AUTO_TEST_CASE_TEMPLATE(pi, T, float_types) {
	BOOST_CHECK_CLOSE(static_cast<T>(vmath::PI), static_cast<T>(3.14159265358979323846), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	BOOST_CHECK(vmath::equals(static_cast<T>(1.2), static_cast<T>(1.2)));
	BOOST_CHECK(!vmath::equals(static_cast<T>(1.2), static_cast<T>(1.3)));
	// TODO Within a specific tolerance.
}

BOOST_AUTO_TEST_CASE_TEMPLATE(radians, T, float_types) {
	BOOST_CHECK_SMALL(vmath::radians(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(180.0)), static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(23.5)), static_cast<T>(0.410152374), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(985.0)), static_cast<T>(17.1914921), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(degrees, T, float_types) {
	BOOST_CHECK_SMALL(vmath::degrees(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(vmath::PI)), static_cast<T>(180.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(0.345)), static_cast<T>(19.76704393), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(cos, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::cos(static_cast<T>(0.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::cos(static_cast<T>(0.25) * static_cast<T>(vmath::PI)), static_cast<T>(0.70710678118), 1e-4f);
	BOOST_CHECK_SMALL(vmath::cos(static_cast<T>(0.5) * static_cast<T>(vmath::PI)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::cos(static_cast<T>(0.75) * static_cast<T>(vmath::PI)), static_cast<T>(-0.70710678118), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::cos(static_cast<T>(vmath::PI)), static_cast<T>(-1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sin, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::sin(static_cast<T>(-0.5) * static_cast<T>(vmath::PI)), static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::sin(static_cast<T>(-0.25) * static_cast<T>(vmath::PI)), static_cast<T>(-0.70710678118), 1e-4f);
	BOOST_CHECK_SMALL(vmath::sin(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::sin(static_cast<T>(0.25) * static_cast<T>(vmath::PI)), static_cast<T>(0.70710678118), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::sin(static_cast<T>(0.5f) * static_cast<T>(vmath::PI)), static_cast<T>(1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(tan, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::tan(static_cast<T>(-0.25) * static_cast<T>(vmath::PI)), static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_SMALL(vmath::tan(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::tan(static_cast<T>(0.25) * static_cast<T>(vmath::PI)), static_cast<T>(1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(acos, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::acos(static_cast<T>(1.0)), static_cast<T>(0.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::acos(static_cast<T>(0.70710678118)), static_cast<T>(0.25) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::acos(static_cast<T>(0.0)), static_cast<T>(0.5) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::acos(static_cast<T>(-0.70710678118)), static_cast<T>(0.75) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::acos(static_cast<T>(-1.0)), static_cast<T>(vmath::PI), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(asin, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::asin(static_cast<T>(-1.0)), static_cast<T>(-0.5) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::asin(static_cast<T>(-0.70710678118)), static_cast<T>(-0.25) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_SMALL(vmath::asin(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::asin(static_cast<T>(0.70710678118)), static_cast<T>(0.25) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::asin(static_cast<T>(1.0)), static_cast<T>(0.5) * static_cast<T>(vmath::PI), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(atan, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::atan(static_cast<T>(-1.0)), static_cast<T>(-0.25) * static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_SMALL(vmath::atan(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::atan(static_cast<T>(1.0)), static_cast<T>(0.25) * static_cast<T>(vmath::PI), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(atan2, T, float_types) {
	// case: x > 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(0.0), static_cast<T>(1.0)), vmath::atan(static_cast<T>(0.0 / 1.0)), 1e-4f);
	// case: y >= 0, x < 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(0.0), static_cast<T>(-0.2)), vmath::atan(static_cast<T>(0.0 / -0.2)) + static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(0.2), static_cast<T>(-0.2)), vmath::atan(static_cast<T>(0.2 / -0.2)) + static_cast<T>(vmath::PI), 1e-4f);
	// case: y < 0, x < 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(-0.2), static_cast<T>(-0.2)), vmath::atan(static_cast<T>(-0.2 / -0.2)) - static_cast<T>(vmath::PI), 1e-4f);
	// case: y > 0, x = 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(0.2), static_cast<T>(0.0)), static_cast<T>(0.5) * static_cast<T>(vmath::PI), 1e-4f);
	// case: y < 0, x = 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(-0.2), static_cast<T>(0.0)), static_cast<T>(-0.5) * static_cast<T>(vmath::PI), 1e-4f);
	// case: y = 0, x = 0
	BOOST_CHECK_CLOSE(vmath::atan2(static_cast<T>(0.0), static_cast<T>(0.0)), static_cast<T>(0.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(pow, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::pow(static_cast<T>(2.0), static_cast<T>(2.0)), static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::pow(static_cast<T>(20.0), static_cast<T>(0.0)), static_cast<T>(1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sqrt, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::sqrt(static_cast<T>(4.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::sqrt(static_cast<T>(9.0)), static_cast<T>(3.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(ceil, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(1.5)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(-1.5)), static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(20.49)), static_cast<T>(21.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(-20.49)), static_cast<T>(-20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(5.0)), static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(-5.0)), static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(12.99)), static_cast<T>(13.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::ceil(static_cast<T>(-12.99)), static_cast<T>(-12.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(floor, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(1.5)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(-1.5)), static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(20.49)), static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(-20.49)), static_cast<T>(-21.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(5.0)), static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(-5.0)), static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(12.99)), static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::floor(static_cast<T>(-12.99)), static_cast<T>(-13.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(round, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(1.5)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(-1.5)), static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(20.49)), static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(-20.49)), static_cast<T>(-20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(5.0)), static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(-5.0)), static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(12.99)), static_cast<T>(13.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::round(static_cast<T>(-12.99)), static_cast<T>(-13.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(trunc, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(1.5)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(-1.5)), static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(20.49)), static_cast<T>(20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(-20.49)), static_cast<T>(-20.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(5.0)), static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(-5.0)), static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(12.99)), static_cast<T>(12.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::trunc(static_cast<T>(-12.99)), static_cast<T>(-12.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(clamp, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.2), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.5), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.75), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.75), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(2.0), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(2.2), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(2.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(abs, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::abs(static_cast<T>(1.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::abs(static_cast<T>(-1.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::abs(static_cast<T>(0.1)), static_cast<T>(0.1), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::abs(static_cast<T>(-0.1)), static_cast<T>(0.1), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copysign, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::copysign(static_cast<T>(2.0), static_cast<T>(-1.0)), static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::copysign(static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::copysign(static_cast<T>(2.0), static_cast<T>(0.0)), static_cast<T>(0.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.5)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.2), static_cast<T>(3.4), static_cast<T>(0.34)), static_cast<T>(1.948), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(max, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::max(static_cast<T>(1.0), static_cast<T>(2.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::max(static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(2.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(min, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::min(static_cast<T>(1.0), static_cast<T>(2.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::min(static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(1.0), 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
