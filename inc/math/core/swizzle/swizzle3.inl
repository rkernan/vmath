#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_INL
#define MATH_CORE_SWIZZLE_SWIZZLE3_INL

#include "swizzle3.hpp"

#include "../vector.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector<T, 3>(void) {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.
 * @param V Vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator=(const Vector<T, 3>& V) {
	this->data[E1] = V.x;
	this->data[E2] = V.y;
	this->data[E3] = V.z;
	return *(Vector<T, 3>*)this;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator+(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator+=(const Vector<T, 3>& V) {
	return *this = *this + V;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator-(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator-=(const Vector<T, 3>& V) {
	return *this = *this - V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply by.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator*(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const Vector<T, 3>& V) {
	return *this = *this * V;
}

/**
 * Divide this swizzle be a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator/(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this * V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const Vector<T, 3>& V) {
	return *this = *this / V;
}

/**
 * Vector-scalar multiplication.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator*(const T& s) const {
	return *(Vector<T, 3>*)this * s;
}

/**
 * Vector-scalar multiplication. Set this swizzle (and the underlying vector) to
 * the result.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Vector-scalar division.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> Swizzle3<T, N, E1, E2, E3>::operator/(const T& s) const {
	return *(Vector<T, 3>*)this / s;
}

/**
 * Vector-scalar division. Set this swizzle (and the underlying vector) to the
 * result.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
template<typename U, typename>
Vector<T, 3>& Swizzle3<T, N, E1, E2, E3>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool Swizzle3<T, N, E1, E2, E3>::operator==(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool Swizzle3<T, N, E1, E2, E3>::operator!=(const Vector<T, 3>& V) const {
	return *(Vector<T, 3>*)this != V;
}

#endif
