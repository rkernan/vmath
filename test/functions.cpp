#define BOOST_TEST_MODULE functions
#include "boost_test_config.hpp"

#include <vmath/functions.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(pi, T, floating_point_types) {
	BOOST_CHECK_CLOSE(static_cast<T>(vmath::PI), static_cast<T>(3.14159265358979323846), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, floating_point_types) {
	BOOST_CHECK(vmath::equals(static_cast<T>(1.2), static_cast<T>(1.2)));
	BOOST_CHECK(!vmath::equals(static_cast<T>(1.2), static_cast<T>(1.200001)));
	BOOST_CHECK(!vmath::equals(static_cast<T>(1.2), static_cast<T>(1.199999)));
	BOOST_CHECK(vmath::equals(static_cast<T>(-18.2), static_cast<T>(-18.2)));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(degrees_to_radians, T, floating_point_types) {
	BOOST_CHECK_SMALL(vmath::radians(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(180.0)), static_cast<T>(vmath::PI), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(23.5)), static_cast<T>(0.410152374), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(985.0)), static_cast<T>(17.1914921), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(radians_to_degrees, T, floating_point_types) {
	BOOST_CHECK_SMALL(vmath::degrees(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(vmath::PI)), static_cast<T>(180.0), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(0.345)), static_cast<T>(19.76704393), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, floating_point_types) {
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.0)), static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(2.0), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.5)), static_cast<T>(1.5), TOLERANCE);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.2), static_cast<T>(3.4), static_cast<T>(0.34)), static_cast<T>(1.948), TOLERANCE);
}
