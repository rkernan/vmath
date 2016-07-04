#ifndef VMATH_CORE_SWIZZLE_SWIZZLE4_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE4_INL

#include <vmath/core/swizzle/swizzle4.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector<T, 4>() {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector<T, 4>& v) {
	this->data[E1] = v.x;
	this->data[E2] = v.y;
	this->data[E3] = v.z;
	this->data[E4] = v.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator-() const {
	return -Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector<T, 4>& v) {
	this->data[E1] += v.x;
	this->data[E2] += v.y;
	this->data[E3] += v.z;
	this->data[E4] += v.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator+(const Vector<T, 4>& v) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) + v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector<T, 4>& v) {
	this->data[E1] -= v.x;
	this->data[E2] -= v.y;
	this->data[E3] -= v.z;
	this->data[E4] -= v.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator-(const Vector<T, 4>& v) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) - v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector<T, 4>& v) {
	this->data[E1] *= v.x;
	this->data[E2] *= v.y;
	this->data[E3] *= v.z;
	this->data[E4] *= v.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator*(const Vector<T, 4>& v) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) * v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector<T, 4>& v) {
	this->data[E1] /= v.x;
	this->data[E2] /= v.y;
	this->data[E3] /= v.z;
	this->data[E4] /= v.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator/(const Vector<T, 4>& v) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) / v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const T s) {
	this->data[E1] *= s;
	this->data[E2] *= s;
	this->data[E3] *= s;
	this->data[E4] *= s;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator*(const T s) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) * s;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const T s) {
	this->data[E1] /= s;
	this->data[E2] /= s;
	this->data[E3] /= s;
	this->data[E4] /= s;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator/(const T s) const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]) / s;
}

}
}

#endif
