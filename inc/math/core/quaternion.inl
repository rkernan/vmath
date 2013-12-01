#ifndef MATH_CORE_QUATERNION_INL
#define MATH_CORE_QUATERNION_INL

#include "quaternion.hpp"

#include <ostream>

#include "vector.hpp"
#include "../func.hpp"
#include "../tuple/axis_angle.hpp"
#include "../tuple/euler.hpp"

using namespace math::core;

/**
 * Parameterized constructor.
 * @param axis Axis of rotation.
 * @param angle Angle of rotation.
 */
// TODO Use named constructor?
template<typename T>
Quaternion<T>::Quaternion(const math::tuple::AxisAngle<T>& axis_angle) {
	Vector<T, 3> axis = axis_angle.axis();
	T angle = axis_angle.angle();
	T half_angle = angle / static_cast<T>(2.0);
	Vector<T, 3> N = math::sin(half_angle) * axis.normal();
	this->x = N.x;
	this->y = N.y;
	this->z = N.z;
	this->w = math::cos(half_angle);
}

/**
 * Parameterized constructor.
 * @param pitch Counter-clockwise x-axis rotation in radians.
 * @param yaw Counter-clockwise y-axis rotation in radians.
 * @param roll Counter-clockwise z-axis rotation in radians.
 */
// TODO Use named constructor?
template<typename T>
Quaternion<T>::Quaternion(const math::tuple::EulerAngles<T>& euler) {
	T pitch = euler.pitch();
	T yaw = euler.yaw();
	T roll = euler.roll();
	T half_pitch = pitch / static_cast<T>(2.0);
	T half_yaw = yaw / static_cast<T>(2.0);
	T half_roll = roll / static_cast<T>(2.0);
	T sinp = math::sin(half_pitch);
	T siny = math::sin(half_yaw);
	T sinr = math::sin(half_roll);
	T cosp = math::cos(half_pitch);
	T cosy = math::cos(half_yaw);
	T cosr = math::cos(half_roll);
	this->w = cosp * cosy * cosr + sinp * siny * sinr;
	this->x = sinp * cosy * cosr - cosp * siny * sinr;
	this->y = cosp * siny * cosr + sinp * cosy * sinr;
	this->z = cosp * cosy * sinr - sinp * siny * cosr;
	this->normalize();
}

/**
 * Calculate the inverse of this quaternion.
 * @return Quaternion inverse.
 */
template<typename T>
Quaternion<T> Quaternion<T>::inverse(void) const {
	return Quaternion<T>(-this->x, -this->y, -this->z, this->w) / this->mag2();
}

/**
 * Invert this quaternion.
 * @return The modified quaternion.
 */
template<typename T>
Quaternion<T>& Quaternion<T>::invert(void) {
	return *this = this->inverse();
}

/**
 * Convert Quaternion to euler angles tuple.
 * @return Euler angles.
 */
template<typename T>
math::tuple::EulerAngles<T> Quaternion<T>::eulerAngles(void) const {
	T pitch = math::atan2(2.0f * (this->y * this->z + this->w * this->x),
		this->w * this->w - this->x * this->x - this->y * this->y + this->z * this->z);
	T yaw = math::asin(-2.0f * (this->x * this->z - this-> w * this->y));
	T roll = math::atan2(2.0f * (this->x * this->y + this->w * this->z),
		this->w * this->w + this->x * this->x - this->y * this->y - this->z * this->z);
	return math::tuple::EulerAngles<T>(pitch, yaw, roll);
}

/**
 * Convert quaternion to axis angle tuple.
 * @return Axis angle tuple.
 */
template<typename T>
math::tuple::AxisAngle<T> Quaternion<T>::axisAngle(void) const {
	Vector<T, 3> axis = Vector<T, 3>(this->x, this->y, this->z).normal();
	T angle = math::acos(this->w) * static_cast<T>(2.0);
	return math::tuple::AxisAngle<T>(axis, angle);
}

/**
 * Spherically linearly interpolate between two quaternions.
 * @param S Start quaternion.
 * @param E End quaternion.
 * @param t Value to interpolate by.
 * @param shortest Take the shortest path there. Defaults to true.
 * @return Interpolated quaternion.
 */
template<typename T>
Quaternion<T> Quaternion<T>::slerp(const Quaternion<T>& S, const Quaternion<T>& E, const T& t, const bool shortest) {
	T d = Quaternion<T>::dot(S, E);
	Quaternion<T> H;
	if (d < static_cast<T>(0.0) && shortest) {
		d = -d;
		H = -E;
	} else {
		H = E;
	}
	T angle = math::acos(d);
	return (math::sin(angle * (static_cast<T>(1.0) - t)) * S + (math::sin(angle * t) * H)) / math::sin(angle);
}

#endif
