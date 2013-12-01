#include <math/tuple/axis_angle.hpp>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(AxisAngle)

BOOST_AUTO_TEST_CASE(create) {
	math::core::Vector<float, 3> V;
	V.x = 1.0f;
	V.y = 2.0f;
	V.z = 3.0f;
	math::tuple::AxisAngle<float> A(V, 4.0f);
	BOOST_CHECK_CLOSE(std::get<0>(A).x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A).y, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A).z, 3.0f, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(A), 4.0f, 1e-5f);
}

BOOST_AUTO_TEST_CASE(copy) {
	// FIXME Relies on create.
	math::core::Vector<float, 3> V;
	V.x = 1.0f;
	V.y = 2.0f;
	V.z = 3.0f;
	math::tuple::AxisAngle<float> A(V, 4.0f);
	math::tuple::AxisAngle<float> A_copy(A);
	BOOST_CHECK_CLOSE(std::get<0>(A_copy).x, std::get<0>(A).x, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A_copy).y, std::get<0>(A).y, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A_copy).z, std::get<0>(A).z, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(A_copy), std::get<1>(A), 1e-5f);
}

BOOST_AUTO_TEST_CASE(move) {
	// FIXME Relies on create.
	math::core::Vector<float, 3> V;
	V.x = 1.0f;
	V.y = 2.0f;
	V.z = 3.0f;
	math::tuple::AxisAngle<float> A(V, 4.0f);
	math::tuple::AxisAngle<float> A_move(A);
	BOOST_CHECK_CLOSE(std::get<0>(A_move).x, std::get<0>(A).x, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A_move).y, std::get<0>(A).y, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<0>(A_move).z, std::get<0>(A).z, 1e-5f);
	BOOST_CHECK_CLOSE(std::get<1>(A_move), std::get<1>(A), 1e-5f);
}

BOOST_AUTO_TEST_CASE(remove) {
	// TODO
	BOOST_CHECK_MESSAGE(false, "test not implemented");
}

BOOST_AUTO_TEST_CASE(axis) {
	// FIXME Relies on create.
	math::core::Vector<float, 3> V;
	V.x = 1.0f;
	V.y = 2.0f;
	V.z = 3.0f;
	math::tuple::AxisAngle<float> A(V, 4.0f);
	BOOST_CHECK_CLOSE(A.axis().x, 1.0f, 1e-5f);
	BOOST_CHECK_CLOSE(A.axis().y, 2.0f, 1e-5f);
	BOOST_CHECK_CLOSE(A.axis().z, 3.0f, 1e-5f);

}

BOOST_AUTO_TEST_CASE(angle) {
	// FIXME Relies on create.
	math::core::Vector<float, 3> V;
	V.x = 1.0f;
	V.y = 2.0f;
	V.z = 3.0f;
	math::tuple::AxisAngle<float> A(V, 4.0f);
	BOOST_CHECK_CLOSE(A.angle(), 4.0f, 1e-5f);
}

BOOST_AUTO_TEST_SUITE_END()
