#ifndef MATH_CORE_SWIZZLE_SWIZZLE2_INL
#define MATH_CORE_SWIZZLE_SWIZZLE2_INL

#include "swizzle.hpp"
#include "swizzle2.hpp"
#include "../vector2.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a Vector.
 * @return Converted Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator Vector2<T>() {
	return Vector2<T>(this->values[E1], this->values[E2]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.
 * @param V Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator=(const Vector2<T>& V) {
	static_assert(swizzle_has_unique_elems<N, E1, E2>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	return *(Vector2<T>*)this;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> Swizzle2<T, N, E1, E2>::operator+(const Vector2<T>& V) const {
	return *(Vector2<T>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator+=(const Vector2<T>& V) {
	static_assert(swizzle_has_unique_elems<N, E1, E2>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	return *this = *this + V;
}

/**
 * Subtract a vector from this swizzle.
 * @param V Vector to subtract.
 * @return Vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> Swizzle2<T, N, E1, E2>::operator-(const Vector2<T>& V) const {
	return *(Vector2<T>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator-=(const Vector2<T>& V) {
	static_assert(swizzle_has_unique_elems<N, E1, E2>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	return *this = *this + V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply by.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> Swizzle2<T, N, E1, E2>::operator*(const Vector2<T>& V) const {
	return *(Vector2<T>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator*=(const Vector2<T>& V) {
	static_assert(swizzle_has_unique_elems<N, E1, E2>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	return *this = *this * V;
}

/**
 * Divide this swizzle by a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> Swizzle2<T, N, E1, E2>::operator/(const Vector2<T>& V) const {
	return *(Vector2<T>*)this / V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator/=(const Vector2<T>& V) {
	static_assert(swizzle_has_unique_elems<N, E1, E2>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	return *this = *this / V;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
bool Swizzle2<T, N, E1, E2>::operator==(const Vector2<T>& V) const {
	return *(Vector2<T>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
bool Swizzle2<T, N, E1, E2>::operator!=(const Vector2<T>& V) const {
	return *(Vector2<T>*)this != V;
}

/**
 * Vector-scalar division.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> Swizzle2<T, N, E1, E2>::operator/(const T& s) const {
	return *(Vector2<T>*)this / s;
}

/**
 * Scalar-vector multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return The scalar-vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> math::core::operator*(const T& s, const Swizzle2<T, N, E1, E2> V) {
	return s * (Vector2<T>)V;
}

#endif
