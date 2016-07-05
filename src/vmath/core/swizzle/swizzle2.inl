#ifndef VMATH_CORE_SWIZZLE_SWIZZLE2_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE2_INL

#include <vmath/core/swizzle/swizzle2.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::to_vector() const {
	return Vector<T, 2>(this->data[E1], this->data[E2]);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::from_vector(const Vector<T, 2> other) {
	this->data[E1] = other.x;
	this->data[E2] = other.y;
	return *(Vector<T, 2>*)this;
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator Vector<T, 2>() {
	return this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator=(const Vector<T, 2>& v) {
	return this->from_vector(v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator-() const {
	return -this->to_vector();
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator+=(const Vector<T, 2>& v) {
	return this->from_vector(this->to_vector() + v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator-=(const Vector<T, 2>& v) {
	return this->from_vector(this->to_vector() - v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const Vector<T, 2>& v) {
	return this->from_vector(this->to_vector() * v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const Vector<T, 2>& v) {
	return this->from_vector(this->to_vector() / v);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const T s) {
	return this->from_vector(this->to_vector() * s);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const T s) {
	return this->from_vector(this->to_vector() / s);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
bool Swizzle2<T, N, E1, E2>::equals(const Vector<T, 2> other) const {
	return this->to_vector().equals(other);
}

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
bool Swizzle2<T, N, E1, E2>::equals(const Vector<T, 2> other, const int ulp) const {
	return this->to_vector().equals(other, ulp);
}

}
}

#endif
