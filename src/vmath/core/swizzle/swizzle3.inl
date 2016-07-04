#ifndef VMATH_CORE_SWIZZLE_SWIZZLE3_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE3_INL

#include <vmath/core/swizzle/swizzle3.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector<T, 3>() {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator=(const Vector<T, 3>& v) {
	this->data[E1] = v.x;
	this->data[E2] = v.y;
	this->data[E3] = v.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator-() const {
	return -Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator+=(const Vector<T, 3>& v) {
	this->data[E1] += v.x;
	this->data[E2] += v.y;
	this->data[E3] += v.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator+(const Vector<T, 3>& v) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) + v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator-=(const Vector<T, 3>& v) {
	this->data[E1] -= v.x;
	this->data[E2] -= v.y;
	this->data[E3] -= v.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator-(const Vector<T, 3>& v) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) - v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const Vector<T, 3>& v) {
	this->data[E1] *= v.x;
	this->data[E2] *= v.y;
	this->data[E3] *= v.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator*(const Vector<T, 3>& v) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) * v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const Vector<T, 3>& v) {
	this->data[E1] /= v.x;
	this->data[E2] /= v.y;
	this->data[E3] /= v.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator/(const Vector<T, 3>& v) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) / v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const T s) {
	this->data[E1] *= s;
	this->data[E2] *= s;
	this->data[E3] *= s;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator*(const T s) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) * s;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const T s) {
	this->data[E1] /= s;
	this->data[E2] /= s;
	this->data[E3] /= s;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator/(const T s) const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]) / s;
}

}
}

#endif
