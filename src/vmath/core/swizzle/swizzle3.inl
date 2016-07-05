#ifndef VMATH_CORE_SWIZZLE_SWIZZLE3_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE3_INL

#include <vmath/core/swizzle/swizzle3.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::to_vector() const {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::from_vector(const Vector<T, 3> other) {
	this->data[E1] = other.x;
	this->data[E2] = other.y;
	this->data[E3] = other.z;
	return *(Vector<T, 3>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector<T, 3>() {
	return this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator=(const Vector<T, 3>& v) {
	return this->from_vector(v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator-() const {
	return -this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator+=(const Vector<T, 3>& v) {
	return this->from_vector(this->to_vector() + v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator-=(const Vector<T, 3>& v) {
	return this->from_vector(this->to_vector() - v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const Vector<T, 3>& v) {
	return this->from_vector(this->to_vector() * v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const Vector<T, 3>& v) {
	return this->from_vector(this->to_vector() / v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const T s) {
	return this->from_vector(this->to_vector() * s);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const T s) {
	return this->from_vector(this->to_vector() / s);
}

}
}

#endif
