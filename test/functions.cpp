#include <boost/test/test_case_template.hpp>
#include <boost/test/unit_test.hpp>

#include <vmath/functions.hpp>
#include "type_lists.hpp"

BOOST_AUTO_TEST_SUITE(functions)

BOOST_AUTO_TEST_CASE_TEMPLATE(pi, T, float_types) {
	BOOST_CHECK_CLOSE(static_cast<T>(vmath::PI), static_cast<T>(3.14159265358979323846), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	BOOST_CHECK(vmath::equals(static_cast<T>(1.2), static_cast<T>(1.2)));
	BOOST_CHECK(!vmath::equals(static_cast<T>(1.2), static_cast<T>(1.3)));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_specify_ulp, T, float_types) {
	BOOST_CHECK(vmath::equals(static_cast<T>(1.2), static_cast<T>(1.2), 3));
	BOOST_CHECK(!vmath::equals(static_cast<T>(1.2), static_cast<T>(1.3), 3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(degrees_to_radians, T, float_types) {
	BOOST_CHECK_SMALL(vmath::radians(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(180.0)), static_cast<T>(vmath::PI), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(23.5)), static_cast<T>(0.410152374), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::radians(static_cast<T>(985.0)), static_cast<T>(17.1914921), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(radians_to_degrees, T, float_types) {
	BOOST_CHECK_SMALL(vmath::degrees(static_cast<T>(0.0)), static_cast<T>(1e-7));
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(vmath::PI)), static_cast<T>(180.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::degrees(static_cast<T>(0.345)), static_cast<T>(19.76704393), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(clamp, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.2), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.5), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(1.75), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(1.75), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(2.0), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::clamp(static_cast<T>(2.2), static_cast<T>(1.5), static_cast<T>(2.0)), static_cast<T>(2.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, float_types) {
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.0)), static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(1.0)), static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(0.5)), static_cast<T>(1.5), 1e-4f);
	BOOST_CHECK_CLOSE(vmath::lerp(static_cast<T>(1.2), static_cast<T>(3.4), static_cast<T>(0.34)), static_cast<T>(1.948), 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
