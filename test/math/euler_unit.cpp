#include <math/tuple/euler.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(EulerAngle)

BOOST_AUTO_TEST_CASE(create) {
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	BOOST_CHECK_CLOSE(std::get<0>(E), 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(E), 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<2>(E), 3.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	// FIXME Relies on create.
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	math::tuple::EulerAngles<float> E_copy(E);
	BOOST_CHECK_CLOSE(std::get<0>(E_copy), std::get<0>(E), 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(E_copy), std::get<1>(E), 1e-5f);
	BOOST_CHECK_CLOSE(std::get<2>(E_copy), std::get<2>(E), 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	// FIXME Relies on create.
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	math::tuple::EulerAngles<float> E_move(std::move(E));
	BOOST_CHECK_CLOSE(std::get<0>(E_move), std::get<0>(E), 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(E_move), std::get<1>(E), 1e-5f);
	BOOST_CHECK_CLOSE(std::get<2>(E_move), std::get<2>(E), 1e-5f);
}

BOOST_AUTO_TEST_CASE(remove) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(pitch) {
	// FIXME Relies on create.
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	BOOST_CHECK_CLOSE(E.pitch(), 1.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(yaw) {
	// FIXME Relies on create.
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	BOOST_CHECK_CLOSE(E.yaw(), 2.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(roll) {
	// FIXME Relies on create.
	math::tuple::EulerAngles<float> E(1.0f, 2.0f, 3.0f);
	BOOST_CHECK_CLOSE(E.roll(), 3.0f, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
