#ifndef VMATH_CORE_SWIZZLE_SWIZZLE4_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE4_INL

#include <vmath/core/swizzle/swizzle4.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::to_vector() const {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::from_vector(const Vector<T, 4> other) {
	this->data[E1] = other.x;
	this->data[E2] = other.y;
	this->data[E3] = other.z;
	this->data[E4] = other.w;
	return *(Vector<T, 4>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector<T, 4>() {
	return this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector<T, 4>& v) {
	return this->from_vector(v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator-() const {
	return -this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector<T, 4>& v) {
	return this->from_vector(this->to_vector() + v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector<T, 4>& v) {
	return this->from_vector(this->to_vector() - v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector<T, 4>& v) {
	return this->from_vector(this->to_vector() * v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector<T, 4>& v) {
	return this->from_vector(this->to_vector() / v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const T s) {
	return this->from_vector(this->to_vector() * s);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const T s) {
	return this->from_vector(this->to_vector() / s);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
bool Swizzle4<T, N, E1, E2, E3, E4>::equals(const Vector<T, 4>& other) const {
	return this->to_vector().equals(other);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
bool Swizzle4<T, N, E1, E2, E3, E4>::equals(const Vector<T, 4>& other, const int ulp) const {
	return this->to_vector().equals(other, ulp);
}

}
}

#endif
