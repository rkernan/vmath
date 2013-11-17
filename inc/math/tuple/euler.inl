#ifndef MATH_CORE_EULER_INL
#define MATH_CORE_EULER_INL

#include "euler.hpp"

using namespace math::tuple;

/**
 * Parameterized constructor.
 * @param p Counter-clockwise x-axis rotation in radians.
 * @param y Counter-clockwise y-axis rotation in radians.
 * @param r Counter-clockwise z-axis rotation in radians.
 */
template<typename T>
EulerAngles<T>::EulerAngles(const T& p, const T& y, const T& r) : std::tuple<T, T, T>(p, y, r) {}

/**
 * Accessor for pitch.
 * @return Counter-clockwise x-axis rotation in radians.
 */
template<typename T>
T EulerAngles<T>::pitch(void) const {
	return std::get<EulerAngles::pitch_idx>(*this);
}

/**
 * Accessor for yaw.
 * @return Counter-clockwise y-axis rotation in radians.
 */
template<typename T>
T EulerAngles<T>::yaw(void) const {
	return std::get<EulerAngles::yaw_idx>(*this);
}

/**
 * Accessor for roll.
 * @return Counter-clockwise z-axis rotation in radians.
 */
template<typename T>
T EulerAngles<T>::roll(void) const {
	return std::get<EulerAngles::roll_idx>(*this);
}

#endif
