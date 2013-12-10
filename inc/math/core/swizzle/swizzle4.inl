#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_INL
#define MATH_CORE_SWIZZLE_SWIZZLE4_INL

#include "swizzle4.hpp"

#include "../vector.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a Vector.
 * @return Converted Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector<T, 4>(void) {
	return Vector<T, 4>(this->data[E1], this->data[E2], this->data[E3], this->data[E4]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.
 * @param V Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector<T, 4>& V) {
	this->data[E1] = V.x;
	this->data[E2] = V.y;
	this->data[E3] = V.z;
	this->data[E4] = V.w;
	return *(Vector<T, 4>*)this;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator+(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector<T, 4>& V) {
	return *this = *this + V;
}

/**
 * Subtract a vector from this swizzle.
 * @param V Vector to subtract.
 * @return The vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator-(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector<T, 4>& V) {
	return *this= *this - V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator*(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector<T, 4>& V) {
	return *this = *this * V;
}

/**
 * Divide this swizzle by a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator/(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this / V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector<T, 4>& V) {
	return *this = *this / V;
}

/**
 * Vector-scalar multiplication.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator*(const T& s) const {
	return *(Vector<T, 4>*)this * s;
}

/**
 * Vector-scalar multiplication. Set this swizzle (and the underlying vector) to
 * the result.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Vector-scalar division.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> Swizzle4<T, N, E1, E2, E3, E4>::operator/(const T& s) const {
	return *(Vector<T, 4>*)this / s;
}

/**
 * Vector-scalar division. Set this swizzle (and the underlying vector) to the
 * result.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
template<typename U, typename>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
bool Swizzle4<T, N, E1, E2, E3, E4>::operator==(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
bool Swizzle4<T, N, E1, E2, E3, E4>::operator!=(const Vector<T, 4>& V) const {
	return *(Vector<T, 4>*)this != V;
}

#endif
