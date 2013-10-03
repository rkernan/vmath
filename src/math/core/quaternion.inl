#ifndef MATH_CORE_QUATERNION_INL
#define  MATH_CORE_QUATERNION_INL

#include "quaternion.hpp"
#include "vector3.hpp"
#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
quaternion<T>::quaternion(void) : x(), y(), z(), w() {}

/**
 * Parameterized constructor.
 * @param x Quaternion x-component.
 * @param y Quaternion y-component.
 * @param z Quaternion z-component.
 * @param w Quaternion w-component.
 */
template<typename T>
quaternion<T>::quaternion(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

/**
 * Negate a quaternion.
 * @return The negated quaternion.
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
 * @param H Quaternion to add.
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
 * @param H Quaternion to add.
 * @return The modified quaternion (component-wise sum).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator+=(const quaternion<T>& H) {
	return *this = *this + H;
}

/**
 * Component-wise subtraction.
 * @param H Quaternion to subtract.
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
 * Component-wise subtraction. Copy the result into this quaternion.
 * @param H Quaternion to subtract.
 * @return The modified quaternion (component-wise difference).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator-=(const quaternion<T>& H) {
	return *this = *this - H;
}

/**
 * Combine quaternion rotations.
 * @param H Quaternion to multiply by.
 * @return The combined rotation.
 */
template<typename T>
quaternion<T> quaternion<T>::operator*(const quaternion<T>& H) const {
	T x = (this->w * H.x) + (this->x * H.w) + (this->y * H.z) - (this->z * H.y);
	T y = (this->w * H.y) + (this->y * H.w) + (this->z * H.x) - (this->x * H.z);
	T z = (this->w * H.z) + (this->z * H.w) + (this->x * H.y) - (this->y * H.x);
	T w = (this->w * H.w) - (this->w * H.w) - (this->y * H.y) - (this->z * H.z);
	return quaternion<T>(x, y, z, w);
}

/**
 * Combine quaternion rotations. Copy the result into this quaternion.
 * @param H Quaternion to multiply by.
 * @return The modified quaternion (combined rotation).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator*=(const quaternion<T>& H) {
	return *this = *this * H;
}
/**
 * Component-wise division.
 * @param H Quaternion to divide by.
 * @return The component-wise quotient.
 */
template<typename T>
quaternion<T> quaternion<T>::operator/(const quaternion<T>& H) const {
	T x = this->x / H.x;
	T y = this->y / H.y;
	T z = this->z / H.z;
	T w = this->w / H.w;
	return quaternion<T>(x, y, z, w);
}

/**
 * Component-wise division. Copy the result into this quaternion.
 * @param H Quaternion to divide by.
 * @return The modified quaternion (component-wise quotient).
 */
template<typename T>
quaternion<T>& quaternion<T>::operator/=(const quaternion<T>& H) {
	return *this = *this / H;
}

/**
 * Apply this rotation to a vector.
 * @param V Vector to rotate.
 * @return Rotated vector.
 */
template<typename T>
vector3<T> quaternion<T>::operator*(const vector3<T>& V) const {
	vector3<T> N = V.normal();
	quaternion<T> vQ(N.x, N.y, N.z, T());
	quaternion<T> cQ(this->conjugate());
	quaternion<T> rQ(vQ * cQ);
	rQ = *this * rQ;
	return vector3<T>(rQ.x, rQ.y, rQ.z);
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Quaternion-scalar quotient.
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
 * Calculate the quaternion length.
 * @return Quaternion magnitude.
 */
template<typename T>
T quaternion<T>::mag(void) const {
	return math::sqrt(this->mag2());
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
 * Calculate the quaternion normal.
 * @return Quaternion normal.
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
 * Calculate the conjugate of this quaternion.
 * @return Quaternion conjugate.
 */
template<typename T>
quaternion<T> quaternion<T>::conjugate(void) const {
	return quaternion<T>(-this->x, -this->y, -this->z, this->w);
}

/**
 * Calculate the inverse of this quaternion.
 * @return Quaternion inverse.
 */
template<typename T>
quaternion<T> quaternion<T>::inverse(void) const {
	return this->conjugate() / this->mag2();
}

/**
 * Check quaternion equality.
 * @param other Quaternion to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool quaternion<T>::operator==(const quaternion<T>& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

// TODO Use enable_if to specialize.
template<>
bool quaternion<float>::operator==(const quaternion<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool quaternion<double>::operator==(const quaternion<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool quaternion<long double>::operator==(const quaternion<long double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

/**
 * Calculate the inner quaternion product (dot product).
 * @param H1 Quaternion to take innte product of.
 * @param H2 Quaternion to take inner product of.
 * @return Quaternion dot product.
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
	return (math::sin(angle * (static_cast<T>(1.0) - t)) * S + (math::sin(angle * t) * H)) / math::sin(angle);
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param H Quaternion to multiply.
 * @return Scalar-quaternion product.
 */
template<typename T>
quaternion<T> operator*(const T& s, const quaternion<T>& H) {
	T x = s * H.x;
	T y = s * H.y;
	T z = s * H.z;
	T w = s * H.w;
	return quaternion<T>(x, y, z, w);
}

/**
 * Output to stream.
 * @param out Stream to output to.
 * @param H Quaternion to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const quaternion<T>& H) {
	return out << "<" << H.x << ", " << H.y << ", " << H.z << ", " << H.w << ">";
}

#endif
