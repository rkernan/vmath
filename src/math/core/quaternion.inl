#ifndef MATH_CORE_QUATERNION_INL
#define MATH_CORE_QUATERNION_INL

#include "quaternion.hpp"
#include "vector.hpp"
#include "../func.hpp"
#include "../tuple/axis_angle.hpp"
#include "../tuple/euler.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
Quaternion<T>::Quaternion(void) : x(), y(), z(), w() {}

/**
 * Parameterized constructor.
 * @param x Quaternion x-component.
 * @param y Quaternion y-component.
 * @param z Quaternion z-component.
 * @param w Quaternion w-component.
 */
template<typename T>
Quaternion<T>::Quaternion(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

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
 * Negate a quaternion.
 * @return The negated quaternion.
 */
template<typename T>
Quaternion<T> Quaternion<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	T z = -this->z;
	T w = -this->w;
	return Quaternion<T>(x, y, z, w);
}

/**
 * Component-wise addition.
 * @param H Quaternion to add.
 * @return The component-wise sum.
 */
template<typename T>
Quaternion<T> Quaternion<T>::operator+(const Quaternion<T>& H) const {
	T x = this->x + H.x;
	T y = this->y + H.y;
	T z = this->z + H.z;
	T w = this->w + H.w;
	return Quaternion<T>(x, y, z, w);
}

/**
 * Component-wise addition. Copy the result into this quaternion.
 * @param H Quaternion to add.
 * @return The modified quaternion (component-wise sum).
 */
template<typename T>
Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& H) {
	return *this = *this + H;
}

/**
 * Component-wise subtraction.
 * @param H Quaternion to subtract.
 * @return The component-wise difference.
 */
template<typename T>
Quaternion<T> Quaternion<T>::operator-(const Quaternion<T>& H) const {
	T x = this->x - H.x;
	T y = this->y - H.y;
	T z = this->z - H.z;
	T w = this->w - H.w;
	return Quaternion<T>(x, y, z, w);
}

/**
 * Component-wise subtraction. Copy the result into this quaternion.
 * @param H Quaternion to subtract.
 * @return The modified quaternion (component-wise difference).
 */
template<typename T>
Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& H) {
	return *this = *this - H;
}

/**
 * Combine quaternion rotations.
 * @param H Quaternion to multiply by.
 * @return The combined rotation.
 */
template<typename T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& H) const {
	T x = (this->w * H.x) + (this->x * H.w) + (this->y * H.z) - (this->z * H.y);
	T y = (this->w * H.y) + (this->y * H.w) + (this->z * H.x) - (this->x * H.z);
	T z = (this->w * H.z) + (this->z * H.w) + (this->x * H.y) - (this->y * H.x);
	T w = (this->w * H.w) - (this->w * H.w) - (this->y * H.y) - (this->z * H.z);
	return Quaternion<T>(x, y, z, w);
}

/**
 * Combine quaternion rotations. Copy the result into this quaternion.
 * @param H Quaternion to multiply by.
 * @return The modified quaternion (combined rotation).
 */
template<typename T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& H) {
	return *this = *this * H;
}

/**
 * Apply this rotation to a vector.
 * @param V Vector to rotate.
 * @return Rotated vector.
 */
template<typename T>
Vector<T, 3> Quaternion<T>::operator*(const Vector<T, 3>& V) const {
	Vector<T, 3> N = V.normal();
	Quaternion<T> vQ(N.x, N.y, N.z, static_cast<T>(0.0));
	Quaternion<T> cQ(this->conjugate());
	Quaternion<T> rQ(vQ * cQ);
	rQ = *this * rQ;
	return vector3(rQ.x, rQ.y, rQ.z);
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Quaternion-scalar quotient.
 */
template<typename T>
Quaternion<T> Quaternion<T>::operator/(const T& s) const {
	T x = this->x / s;
	T y = this->y / s;
	T z = this->z / s;
	T w = this->w / s;
	return Quaternion<T>(x, y, z, w);
}

/**
 * Calculate the quaternion length.
 * @return Quaternion magnitude.
 */
template<typename T>
T Quaternion<T>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T>
T Quaternion<T>::mag2(void) const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
}

/**
 * Calculate the quaternion normal.
 * @return Quaternion normal.
 */
template<typename T>
Quaternion<T> Quaternion<T>::normal(void) const {
	return *this / this->mag();
}

/**
 * Normalize a quaternion.
 * @return The modified quaternion (quaternion normal).
 */
template<typename T>
Quaternion<T>& Quaternion<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Calculate the conjugate of this quaternion.
 * @return Quaternion conjugate.
 */
template<typename T>
Quaternion<T> Quaternion<T>::conjugate(void) const {
	return Quaternion<T>(-this->x, -this->y, -this->z, this->w);
}

/**
 * Calculate the inverse of this quaternion.
 * @return Quaternion inverse.
 */
template<typename T>
Quaternion<T> Quaternion<T>::inverse(void) const {
	return this->conjugate() / this->mag2();
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
 * Check Quaternion equality.
 * @param other Quaternion to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool Quaternion<T>::operator==(const Quaternion<T>& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

// TODO Use enable_if to specialize.
template<>
bool Quaternion<float>::operator==(const Quaternion<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool Quaternion<double>::operator==(const Quaternion<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool Quaternion<long double>::operator==(const Quaternion<long double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

/**
 * Calculate the inner quaternion product (dot product).
 * @param H1 Quaternion to take innte product of.
 * @param H2 Quaternion to take inner product of.
 * @return Quaternion dot product.
 */
template<typename T>
T Quaternion<T>::dot(const Quaternion<T>& H1, const Quaternion<T>& H2) {
	return (H1.x * H2.x) + (H1.y * H2.y) + (H1.z * H2.z) + (H1.w * H2.w);
}

/**
 * Linearly interpolate between two quaternions.
 * @param S Start quaternion.
 * @param E End quaternion.
 * @param t Value to interpolate by.
 * @return Interpolated quaternion.
 */
template<typename T>
Quaternion<T> Quaternion<T>::lerp(const Quaternion<T>& S, const Quaternion<T>& E, const T& t) {
	return S + (t * (E - S));
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

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param H Quaternion to multiply.
 * @return Scalar-quaternion product.
 */
template<typename T>
Quaternion<T> math::core::operator*(const T& s, const Quaternion<T>& H) {
	T x = s * H.x;
	T y = s * H.y;
	T z = s * H.z;
	T w = s * H.w;
	return Quaternion<T>(x, y, z, w);
}

/**
 * Output to stream.
 * @param out Stream to output to.
 * @param H Quaternion to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& math::core::operator<<(std::ostream& out, const Quaternion<T>& H) {
	return out << "<" << H.x << ", " << H.y << ", " << H.z << ", " << H.w << ">";
}

#endif
