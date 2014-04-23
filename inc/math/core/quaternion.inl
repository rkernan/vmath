#ifndef MATH_CORE_QUATERNION_INL
#define MATH_CORE_QUATERNION_INL

#include "quaternion.hpp"

#include <ostream>

#include "vector.hpp"
#include "../functions.hpp"

using namespace math::core;

/**
 * Convert axis and angle to a quaternion.
 * @param axis Axis of rotation.
 * @param angle Angle of rotation in radians.
 */
template<typename T>
quaternion<T>::quaternion(const vector<T, 3>& axis, const T& angle) {
	T half_angle = angle / static_cast<T>(2.0);
	vector<T, 3> N =  axis.normal() * math::sin(half_angle);
	this->x = N.x;
	this->y = N.y;
	this->z = N.z;
	this->w = math::cos(half_angle);
}

/**
 * Convert euler angles to a quaternion.
 * @param pitch Counter-clockwise x-axis rotation in radians.
 * @param yaw Counter-clockwise y-axis rotation in radians.
 * @param roll Counter-clockwise z-axis rotation in radians.
 */
template<typename T>
quaternion<T>::quaternion(const T& pitch, const T& yaw, const T& roll) {
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
 * Convert a matrix to a quaternion.
 * @param mat matrix to convert.
 */
template<typename T>
quaternion<T>::quaternion(const matrix<T, 4>& mat) {
	T x = math::sqrt(math::max(static_cast<T>(0.0),
		static_cast<T>(1.0) + mat[0][0] - mat[1][1] - mat[2][2])) / static_cast<T>(2.0);
	T y = math::sqrt(math::max(static_cast<T>(0.0),
		static_cast<T>(1.0) - mat[0][0] + mat[1][1] - mat[2][2])) / static_cast<T>(2.0);
	T z = math::sqrt(math::max(static_cast<T>(0.0),
		static_cast<T>(1.0) - mat[0][0] - mat[1][1] + mat[2][2])) / static_cast<T>(2.0);
	T w = math::sqrt(math::max(static_cast<T>(0.0),
		static_cast<T>(1.0) + mat[0][0] + mat[1][1] + mat[2][2])) / static_cast<T>(2.0);
	this->x = math::copysign(x, mat[1][2] - mat[2][1]);
	this->y = math::copysign(y, mat[2][0] - mat[0][2]);
	this->z = math::copysign(z, mat[0][1] - mat[1][0]);
	this->w = w;
	this->normalize();
}

/**
 * Set this quaternion equal to another.
 * @param other quaternion to set equal to.
 * @return The modified vector.
 */
template<typename T>
quaternion<T>& quaternion<T>::operator=(const quaternion<T>& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
	return *this;
}

/**
 * Access a quaternion element using an index.
 * @param idx Location of element to access.
 * @return Accessed element.
 */
template<typename T>
T quaternion<T>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

/**
 * Access and modify a quaternion element using an index.
 * @param idx Location of element to access.
 * @return Modified element.
 */
template<typename T>
T& quaternion<T>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

/**
 * Negate a quaternion.
 * @return The quaternion negated.
 */
template<typename T>
quaternion<T> quaternion<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	T z = -this->z;
	T w = -this->w;
	return quaternion<T>(x, y, z, w);
}

/**
 * Component-wise addition.
 * @param H quaternion to add.
 * @return The component-wise sum.
 */
template<typename T>
quaternion<T> quaternion<T>::operator+(const quaternion<T>& H) const {
	T x = this->x + H.x;
	T y = this->y + H.y;
	T z = this->z + H.z;
	T w = this->w + H.w;
	return quaternion<T>(x, y, z, w);
}

/**
 * Component-wise addition. Copy the result into this quaternion.
 * @param H quaternion to add.
 * @return The modified quaternion (component-wise sum).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator+=(const quaternion<T>& H) {
	return *this = *this + H;
}

/**
 * Component-wise subtraction.
 * @param H quaternion to subtract.
 * @return The component-wise difference.
 */
template<typename T>
quaternion<T> quaternion<T>::operator-(const quaternion<T>& H) const {
	T x = this->x - H.x;
	T y = this->y - H.y;
	T z = this->z - H.z;
	T w = this->w - H.w;
	return quaternion<T>(x, y, z, w);
}

/**
 * Component-wise subtraction.
 * @param H quaternion to subtract.
 * @return The modified quaternion (compnent-wise difference).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator-=(const quaternion<T>& H) {
	return *this = *this - H;
}

/**
 * Multiply another quaternion by this one.
 * @param H quaternion to multiply.
 * @return The combined quaternion rotation.
 */
template<typename T>
quaternion<T> quaternion<T>::operator*(const quaternion<T>& H) const {
	T x = (this->w * H.x) + (this->x * H.w) + (this->y * H.z) - (this->z * H.y);
	T y = (this->w * H.y) + (this->y * H.w) + (this->z * H.x) - (this->x * H.z);
	T z = (this->w * H.z) + (this->z * H.w) + (this->x * H.y) - (this->y * H.x);
	T w = (this->w * H.w) - (this->x * H.x) - (this->y * H.y) - (this->z * H.z);
	return quaternion<T>(x, y, z, w);
}

/**
 * Multiply another quaternion by this one and set this quaternion equal to the
 * result.
 * @param H quaternion to multiply.
 * @return The combined quaternion rotation.
 */
template<typename T>
quaternion<T>& quaternion<T>::operator*=(const quaternion<T>& H) {
	return *this = *this * H;
}

/**
 * Apply this quaternion rotation to a vector.
 * @param V vector to rotate.
 * @return The rotated vector.
 */
template<typename T>
vector<T, 3> quaternion<T>::operator*(const vector<T, 3>& V) const {
	vector<T, 3> N = V.normal();
	quaternion vQ(N.x, N.y, N.z, 0.0f);
	quaternion cQ(this->inverse());
	quaternion rQ(vQ * cQ);
	rQ = *this * rQ;
	return vector<T, 3>(rQ.x, rQ.y, rQ.z);
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return quaternion-scalar product.
 */
template<typename T>
quaternion<T> quaternion<T>::operator*(const T& s) const {
	T x = this->x * s;
	T y = this->y * s;
	T z = this->z * s;
	T w = this->w * s;
	return quaternion<T>(x, y, z, w);
}

/**
 * Scalar multiplication. Copy the result into this quaternion.
 * @param s Scalar to multiply by.
 * @return The modified quaternion (quaternion-scalar product).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return quaternion-scalar quotient.
 */
template<typename T>
quaternion<T> quaternion<T>::operator/(const T& s) const {
	T x = this->x / s;
	T y = this->y / s;
	T z = this->z / s;
	T w = this->w / s;
	return quaternion<T>(x, y, z, w);
}

/**
 * Scalar division. Copy the result into this quaternion.
 * @param s Scalar to divide by.
 * @return The modified quaternion (quaternion-scalar quotient).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T>
T quaternion<T>::mag2(void) const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
}

/**
 * Calculate the magnitude.
 * @return Magnitude.
 */
template<typename T>
T quaternion<T>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the quaternion normal.
 * @return quaternion normal.
 */
template<typename T>
quaternion<T> quaternion<T>::normal(void) const {
	return *this / this->mag();
}

/**
 * Normalize a quaternion.
 * @return The modified quaternion (quaternion normal).
 */
template<typename T>
quaternion<T>& quaternion<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Calculate the inverse of this quaternion.
 * @return quaternion inverse.
 */
template<typename T>
quaternion<T> quaternion<T>::inverse(void) const {
	return quaternion<T>(-this->x, -this->y, -this->z, this->w) / this->mag2();
}

/**
 * Invert this quaternion.
 * @return The modified quaternion.
 */
template<typename T>
quaternion<T>& quaternion<T>::invert(void) {
	return *this = this->inverse();
}

/**
 * Convert quaternion to euler angle.
 * @return Euler x-axis value (pitch).
 */
template<typename T>
T quaternion<T>::pitch(void) const {
	return math::atan2(2.0f * (this->y * this->z + this->w * this->x),
		this->w * this->w - this->x * this->x - this->y * this->y + this->z * this->z);
}

/**
 * Convert quaternion to euler angle.
 * @return Euler y-axis value (yaw).
 */
template<typename T>
T quaternion<T>::yaw(void) const {
	return math::asin(-2.0f * (this->x * this->z - this-> w * this->y));
}

/**
 * Convert quaternion to euler angle.
 * @return Euler z-axis value (roll).
 */
template<typename T>
T quaternion<T>::roll(void) const {
	return math::atan2(2.0f * (this->x * this->y + this->w * this->z),
		this->w * this->w + this->x * this->x - this->y * this->y - this->z * this->z);
}

/**
 * Convert quaternion to axis angle.
 * @return Axis of rotation.
 */
template<typename T>
vector<T, 3> quaternion<T>::axis(void) const {
	return vector<T, 3>(this->x, this->y, this->z).normal();
}

/**
 * Convert quaternion to axis angle.
 * @return Angle of rotation.
 */
template<typename T>
T quaternion<T>::angle(void) const {
	return math::acos(this->w) * static_cast<T>(2.0);
}

/**
 * Convert quaternion to matrix.
 * @return Rotation matrix.
 */
template<typename T>
matrix<T, 4> quaternion<T>::to_matrix(void) const {
	matrix<T, 4> mat;
	mat[0][0] = static_cast<T>(1.0) - static_cast<T>(2.0) * (this->y * this->y) - static_cast<T>(2.0) * (this->z * this->z);
	mat[0][1] = static_cast<T>(2.0) * (this->x * this->y) + static_cast<T>(2.0) * (this->w * this->z);
	mat[0][2] = static_cast<T>(2.0) * (this->x * this->z) - static_cast<T>(2.0) * (this->w * this->y);
	mat[0][3] = static_cast<T>(0.0);
	mat[1][0] = static_cast<T>(2.0) * (this->x * this->y) - static_cast<T>(2.0) * (this->w * this->z);
	mat[1][1] = static_cast<T>(1.0) - static_cast<T>(2.0) * (this->x * this->x) - static_cast<T>(2.0) * (this->z * this->z);
	mat[1][2] = static_cast<T>(2.0) * (this->y * this->z) + static_cast<T>(2.0) * (this->w * this->x);
	mat[1][3] = static_cast<T>(0.0);
	mat[2][0] = static_cast<T>(2.0) * (this->x * this->z) + static_cast<T>(2.0) * (this->w * this->y);
	mat[2][1] = static_cast<T>(2.0) * (this->y * this->z) - static_cast<T>(2.0) * (this->w * this->x);
	mat[2][2] = static_cast<T>(1.0) - static_cast<T>(2.0) * (this->x * this->x) - static_cast<T>(2.0) * (this->y * this->y);
	mat[2][3] = static_cast<T>(0.0);
	mat[3][0] = static_cast<T>(0.0);
	mat[3][1] = static_cast<T>(0.0);
	mat[3][2] = static_cast<T>(0.0);
	mat[3][3] = static_cast<T>(1.0);
	return mat;
}

/**
 * Equals helper. Allows for partial specialization of the equality operator.
 * Specialization for quaternions containing floats.
 * @param H1 quaternion to check equality with.
 * @param H2 quaternion to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
static inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type
		equals_helper(const quaternion<T>& H1, const quaternion<T>& H2) {
	return math::equals(H1.x, H2.x) && math::equals(H1.y, H2.y) && math::equals(H1.z, H2.z) && math::equals(H1.w, H2.w);
}

/**
 * Equals helper. Allows for partial specialization of the equality operator.
 * Specialization for quaternions containing integers or other.
 * @param H1 quaternion to check equality with.
 * @param H2 quaternion to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
static inline typename std::enable_if<!std::is_floating_point<T>::value, bool>::type
		equals_helper(const quaternion<T>& H1, const quaternion<T>& H2) {
	return H1.x == H2.x && H1.y == H2.y && H1.z == H2.z && H1.w == H2.w;
}

/**
 * Check quaternion equality.
 * @param other quaternion to check equality with.
 * @return True if they are equals, otherwise false.
 */
template<typename T>
bool quaternion<T>::operator==(const quaternion<T>& other) const {
	return equals_helper(*this, other);
}

/**
 * Check quaternion inequality.
 * @param other quaternion to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T>
bool quaternion<T>::operator!=(const quaternion<T>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner quaternion product (dot product).
 * @param H1 quaternion to take dot product of.
 * @param H2 quaternion to take dot product of.
 * @return quaternion dot product.
 */
template<typename T>
T quaternion<T>::dot(const quaternion<T>& H1, const quaternion<T>& H2) {
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
quaternion<T> quaternion<T>::lerp(const quaternion<T>& S, const quaternion<T>& E, const T& t) {
	return S + ((E - S) * t);
}

/**
 * Spherically interpolate between two quaternions.
 * @param S Start quaternion.
 * @param E End quaternion.
 * @param t Value to interpolate by.
 * @param shortest Take the shortest path there. Defaults to true.
 * @return Interpolated quaternion.
 */
template<typename T>
quaternion<T> quaternion<T>::slerp(const quaternion<T>& S, const quaternion<T>& E, const T& t, const bool shortest) {
	T d = quaternion<T>::dot(S, E);
	quaternion<T> H;
	if (d < static_cast<T>(0.0) && shortest) {
		d = -d;
		H = -E;
	} else {
		H = E;
	}
	T angle = math::acos(d);
	return (S * math::sin(angle * (static_cast<T>(1.0) - t)) + H * (math::sin(angle * t))) / math::sin(angle);
}

#endif
