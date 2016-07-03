#ifndef VMATH_CORE_VECTOR_INL
#define VMATH_CORE_VECTOR_INL

#include <vmath/core/vector.hpp>

#include <stdexcept>
#include <string>
#include <vmath/functions.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
T Vector<T, N>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

template<typename T, std::size_t N>
T& Vector<T, N>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-() const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = -this->data[i];
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& v) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] + v.data[i];
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& v) {
	return *this = *this + v;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& v) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] - v.data[i];
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& v) {
	return *this = *this - v;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const Vector<T, N>& v) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] * v.data[i];
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(const Vector<T, N>& v) {
	return *this = *this * v;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(const Vector<T, N>& v) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] / v.data[i];
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(const Vector<T, N>& v) {
	return *this = *this / v;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const T& s) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] * s;
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(const T& s) {
	return *this = *this * s;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(const T& s) const {
	Vector<T, N> res;
	for (std::size_t i = 0; i < N; i++) {
		res.data[i] = this->data[i] / s;
	}
	return res;
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(const T& s) {
	return *this = *this / s;
}

template<typename T, std::size_t N>
T Vector<T, N>::mag() const {
	return vmath::sqrt(this->mag2());
}

template<typename T, std::size_t N>
T Vector<T, N>::mag2() const {
	T mag2 = T();
	for (std::size_t i = 0; i < N; i++) {
		mag2 += this->data[i] * this->data[i];
	}
	return mag2;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::normal() const {
	return *this / this->mag();
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::normalize() {
	return *this = this->normal();
}

/**
 * \brief Equality helper for floating point equality
 * \param[in] V1 Vector to check equality with
 * \param[in] V2 Vector to check equality with
 * \return True if they are equal, otherwise false
 */
template<typename T, std::size_t N>
static inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type equals_helper(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	// FIXME Doesn't allow error resolution
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && vmath::equals(v1.data[i], v2.data[i]);
	}
	return equal;
}

/**
 * \brief Equality helper for non-floating point equality
 * \param[in] V1 Vector to check equality with.
 * \param[in] V2 Vector to check equality with.
 * \return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
static inline typename std::enable_if<!std::is_floating_point<T>::value, bool>::type equals_helper(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && v1.data[i] == v2.data[i];
	}
	return equal;
}

// TODO
/* template<typename T, std::size_t N> */
/* bool Vector<T, N>::equals(const Vector<T, N>& other) const { */

/* } */

/* template<typename T, std::size_t N> */
/* template<typename U, typename = typename std::enable_if<std::is_floating_point<U>::value, U>::type> */
/* bool Vector<T, N>::equals(const Vector<T, N>& other, T epsilon) const { */
/* 	bool equiv = true; */
/* 	for (std::size_t i = 0; i < N; i++) { */
/* 		equiv = equiv && vmath::equals(this->data[i], other.data[i], epsilon); */
/* 	} */
/* 	return equiv; */
/* } */

template<typename T, std::size_t N>
bool Vector<T, N>::operator==(const Vector<T, N>& other) const {
	return this->equals(*this, other);
}

template<typename T, std::size_t N>
bool Vector<T, N>::operator!=(const Vector<T, N>& other) const {
	return !(this->equals(*this, other));
}

template<typename T, std::size_t N>
T Vector<T, N>::dot(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	T dot = T();
	for (std::size_t i = 0; i < N; ++i) {
		dot += v1.data[i] * v2.data[i];
	}
	return dot;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::reflect(const Vector<T, N>& incident, const Vector<T, N>& surface_normal) {
	return incident - surface_normal * static_cast<T>(2.0) * Vector<T, N>::dot(surface_normal, incident);
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::refract(const Vector<T, N>& incident, const Vector<T, N>& surface_normal, const T& eta) {
	T s_dot_i = Vector<T, N>::dot(surface_normal, incident);
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - s_dot_i * s_dot_i);
	if (k < static_cast<T>(0.0)) {
		return Vector<T, N>();
	} else {
		return incident * eta - surface_normal * (eta * s_dot_i + vmath::sqrt(k));
	}
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::lerp(const Vector<T, N>& start, const Vector<T, N>& end, const T& t) {
	return start + ((end - start) * t);
}

template<typename T, std::size_t N>
template<typename U, typename>
T Vector<T, N>::cross(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	return (v1.x * v2.y) - (v1.y * v2.x);
}

template<typename T, std::size_t N>
template<typename U, typename>
Vector<T, N> Vector<T, N>::cross(const Vector<T, N>& v1, const Vector<T, N>& v2) {
	U x = (v1.y * v2.z) - (v1.z * v2.y);
	U y = (v1.z * v2.x) - (v1.x * v2.z);
	U z = (v1.x * v2.y) - (v1.y * v2.x);
	return Vector<U, N>(x, y, z);
}

}
}

#endif