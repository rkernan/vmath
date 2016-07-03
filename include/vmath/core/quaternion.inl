#ifndef VMATH_CORE_QUATERNION_INL
#define VMATH_CORE_QUATERNION_INL

#include <vmath/core/Quaternion.hpp>

#include <vmath/functions.hpp>
#include <vmath/core/matrix.hpp>
#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T>
Quaternion<T>::quaternion(const T& pitch, const T& yaw, const T& roll) {
	T half_pitch = pitch / static_cast<T>(2.0);
	T half_yaw = yaw / static_cast<T>(2.0);
	T half_roll = roll / static_cast<T>(2.0);
	T sinp = vmath::sin(half_pitch);
	T siny = vmath::sin(half_yaw);
	T sinr = vmath::sin(half_roll);
	T cosp = vmath::cos(half_pitch);
	T cosy = vmath::cos(half_yaw);
	T cosr = vmath::cos(half_roll);
	this->w = cosp * cosy * cosr + sinp * siny * sinr;
	this->x = sinp * cosy * cosr - cosp * siny * sinr;
	this->y = cosp * siny * cosr + sinp * cosy * sinr;
	this->z = cosp * cosy * sinr - sinp * siny * cosr;
	this->normalize();
}

template<typename T>
Quaternion<T>::quaternion(const vector<T, 3>& axis, const T& angle) {
	T half_angle = angle / static_cast<T>(2.0);
	vector<T, 3> N =  axis.normal() * vmath::sin(half_angle);
	this->x = N.x;
	this->y = N.y;
	this->z = N.z;
	this->w = vmath::cos(half_angle);
}

template<typename T>
Quaternion<T>::quaternion(const matrix<T, 4, 4>& mat) {
	T x = vmath::sqrt(vmath::max(static_cast<T>(0.0),
		static_cast<T>(1.0) + mat[0][0] - mat[1][1] - mat[2][2])) / static_cast<T>(2.0);
	T y = vmath::sqrt(vmath::max(static_cast<T>(0.0),
		static_cast<T>(1.0) - mat[0][0] + mat[1][1] - mat[2][2])) / static_cast<T>(2.0);
	T z = vmath::sqrt(vmath::max(static_cast<T>(0.0),
		static_cast<T>(1.0) - mat[0][0] - mat[1][1] + mat[2][2])) / static_cast<T>(2.0);
	T w = vmath::sqrt(vmath::max(static_cast<T>(0.0),
		static_cast<T>(1.0) + mat[0][0] + mat[1][1] + mat[2][2])) / static_cast<T>(2.0);
	this->x = vmath::copysign(x, mat[1][2] - mat[2][1]);
	this->y = vmath::copysign(y, mat[2][0] - mat[0][2]);
	this->z = vmath::copysign(z, mat[0][1] - mat[1][0]);
	this->w = w;
	this->normalize();
}

template<typename T>
T Quaternion<T>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

template<typename T>
T& Quaternion<T>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

template<typename T>
Quaternion<T> quaternion<T>::operator-() const {
	T x = -this->x;
	T y = -this->y;
	T z = -this->z;
	T w = -this->w;
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T> quaternion<T>::operator+(const quaternion<T>& h) const {
	T x = this->x + h.x;
	T y = this->y + h.y;
	T z = this->z + h.z;
	T w = this->w + h.w;
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T>& quaternion<T>::operator+=(const quaternion<T>& h) {
	return *this = *this + h;
}

template<typename T>
Quaternion<T> quaternion<T>::operator-(const quaternion<T>& h) const {
	T x = this->x - h.x;
	T y = this->y - h.y;
	T z = this->z - h.z;
	T w = this->w - h.w;
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T>& quaternion<T>::operator-=(const quaternion<T>& h) {
	return *this = *this - h;
}

template<typename T>
Quaternion<T> quaternion<T>::operator*(const quaternion<T>& h) const {
	T x = (this->w * h.x) + (this->x * h.w) + (this->y * h.z) - (this->z * h.y);
	T y = (this->w * h.y) + (this->y * h.w) + (this->z * h.x) - (this->x * h.z);
	T z = (this->w * h.z) + (this->z * h.w) + (this->x * h.y) - (this->y * h.x);
	T w = (this->w * h.w) - (this->x * h.x) - (this->y * h.y) - (this->z * h.z);
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T>& quaternion<T>::operator*=(const quaternion<T>& h) {
	return *this = *this * h;
}

template<typename T>
vector<T, 3> Quaternion<T>::operator*(const vector<T, 3>& v) const {
	vector<T, 3> n = v.normal();
	Quaternion vq(n.x, n.y, n.z, 0.0f);
	Quaternion cq(this->inverse());
	Quaternion rq(vq * cq);
	rQ = *this * rq;
	return vector<T, 3>(rq.x, rq.y, rq.z);
}

template<typename T>
Quaternion<T> quaternion<T>::operator*(const T& s) const {
	T x = this->x * s;
	T y = this->y * s;
	T z = this->z * s;
	T w = this->w * s;
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T>& quaternion<T>::operator*=(const T& s) {
	return *this = *this * s;
}

template<typename T>
Quaternion<T> quaternion<T>::operator/(const T& s) const {
	T x = this->x / s;
	T y = this->y / s;
	T z = this->z / s;
	T w = this->w / s;
	return Quaternion<T>(x, y, z, w);
}

template<typename T>
Quaternion<T>& quaternion<T>::operator/=(const T& s) {
	return *this = *this / s;
}

template<typename T>
T Quaternion<T>::mag2() const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
}

template<typename T>
T Quaternion<T>::mag() const {
	return vmath::sqrt(this->mag2());
}

template<typename T>
Quaternion<T> quaternion<T>::normal() const {
	return *this / this->mag();
}

template<typename T>
Quaternion<T>& quaternion<T>::normalize() {
	return *this = this->normal();
}

template<typename T>
Quaternion<T> quaternion<T>::inverse() const {
	return Quaternion<T>(-this->x, -this->y, -this->z, this->w) / this->mag2();
}

template<typename T>
Quaternion<T>& quaternion<T>::invert() {
	return *this = this->inverse();
}

template<typename T>
T Quaternion<T>::pitch() const {
	return vmath::atan2(2.0f * (this->y * this->z + this->w * this->x),
		this->w * this->w - this->x * this->x - this->y * this->y + this->z * this->z);
}

template<typename T>
T Quaternion<T>::yaw() const {
	return vmath::asin(-2.0f * (this->x * this->z - this-> w * this->y));
}

template<typename T>
T Quaternion<T>::roll() const {
	return vmath::atan2(2.0f * (this->x * this->y + this->w * this->z),
		this->w * this->w + this->x * this->x - this->y * this->y - this->z * this->z);
}

template<typename T>
vector<T, 3> Quaternion<T>::axis() const {
	return vector<T, 3>(this->x, this->y, this->z).normal();
}

template<typename T>
T Quaternion<T>::angle() const {
	return vmath::acos(this->w) * static_cast<T>(2.0);
}

template<typename T>
matrix<T, 4> Quaternion<T>::to_matrix() const {
	matrix<T, 4, 4> mat;
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
 * \brief Specialization for quaternions containing floats
 * \param[in] h1 Quaternion to check equality with
 * \param[in] h2 Quaternion to check equality with
 * \return True if they are equal, otherwise false
 */
template<typename T>
static inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type equals_helper(const Quaternion<T>& h1, const quaternion<T>& h2) {
	// FIXME Can't specify error
	return vmath::equals(h1.x, h2.x) && vmath::equals(h1.y, h2.y) && vmath::equals(h1.z, h2.z) && vmath::equals(h1.w, h2.w);
}

/**
 * \brief Specialization for quaternions containing integers or other
 * \param[in] h1 Quaternion to check equality with
 * \param[in] h2 Quaternion to check equality with
 * \return True if they are equal, otherwise false
 */
template<typename T>
static inline typename std::enable_if<!std::is_floating_point<T>::value, bool>::type equals_helper(const Quaternion<T>& h1, const quaternion<T>& h2) {
	return h1.x == h2.x && h1.y == h2.y && h1.z == h2.z && h1.w == h2.w;
}

template<typename T>
bool Quaternion<T>::operator==(const quaternion<T>& other) const {
	return equals_helper(*this, other);
}

template<typename T>
bool Quaternion<T>::operator!=(const quaternion<T>& other) const {
	return !(*this == other);
}

template<typename T>
T Quaternion<T>::dot(const quaternion<T>& h1, const quaternion<T>& h2) {
	return (h1.x * h2.x) + (h1.y * h2.y) + (h1.z * h2.z) + (h1.w * h2.w);
}

template<typename T>
Quaternion<T> quaternion<T>::lerp(const quaternion<T>& start, const quaternion<T>& end, const T& t) {
	return start + ((end - start) * t);
}

template<typename T>
Quaternion<T> quaternion<T>::slerp(const quaternion<T>& start, const quaternion<T>& end, const T& t, const bool shortest) {
	T d = Quaternion<T>::dot(start, end);
	Quaternion<T> h;
	if (d < static_cast<T>(0.0) && shortest) {
		d = -d;
		h = -end;
	} else {
		h = end;
	}
	T angle = vmath::acos(d);
	return (start * vmath::sin(angle * (static_cast<T>(1.0) - t)) + h * (vmath::sin(angle * t))) / vmath::sin(angle);
}

}
}

#endif
