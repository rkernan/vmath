#ifndef MATH_TUPLE_AXIS_ANGLE_INL
#define MATH_TUPLE_AXIS_ANGLE_INL

#include "axis_angle.hpp"
#include "../core/vector3.hpp"

using namespace math::tuple;

/**
 * Parameterized constructor.
 * @param axis Axis of rotation.
 * @param angle Angle of rotation.
 */
template<typename T>
AxisAngle<T>::AxisAngle(const math::core::Vector3<T>& axis, const T& angle) :
	std::tuple<math::core::Vector3<T>, T>(axis, angle) {}

/**
 * Accessor for axis.
 * @return Axis of rotation.
 */
template<typename T>
math::core::Vector3<T> AxisAngle<T>::axis(void) const {
	return std::get<AxisAngle::axis_idx>(*this);
}

/**
 * Accessor for angle.
 * @return Angle of rotation.
 */
template<typename T>
T AxisAngle<T>::angle(void) const {
	return std::get<AxisAngle::angle_idx>(*this);
}

#endif
