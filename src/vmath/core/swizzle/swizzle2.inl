#ifndef VMATH_CORE_SWIZZLE_SWIZZLE2_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE2_INL

#include <vmath/core/swizzle/swizzle2.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator Vector<T, 2>() {
	return Vector<T, 2>(this->data[E1], this->data[E2]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator=(const Vector<T, 2>& v) {
	this->data[E1] = v.x;
	this->data[E2] = v.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator-() const {
	return -Vector<T, 2>(this->data[E1], this->data[E2]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator+=(const Vector<T, 2>& v) {
	this->data[E1] += v.x;
	this->data[E2] += v.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator+(const Vector<T, 2>& v) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) + v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator-=(const Vector<T, 2>& v) {
	this->data[E1] -= v.x;
	this->data[E2] -= v.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator-(const Vector<T, 2>& v) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) - v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const Vector<T, 2>& v) {
	this->data[E1] *= v.x;
	this->data[E2] *= v.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator*(const Vector<T, 2>& v) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) * v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const Vector<T, 2>& v) {
	this->data[E1] /= v.x;
	this->data[E2] /= v.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator/(const Vector<T, 2>& v) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) / v;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const T s) {
	this->data[E1] *= s; 
	this->data[E2] *= s;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator*(const T s) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) * s;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const T s) {
	this->data[E1] /= s;
	this->data[E2] /= s;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator/(const T s) const {
	return Vector<T, 2>(this->data[E1], this->data[E2]) / s;
}

}
}

#endif
