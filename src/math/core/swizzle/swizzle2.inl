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
 * Set this swizzle (and the underlying Vector) equal to a Vector.  @param V
 * Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator=(const Vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	return *(Vector2<T>*)this;
}

/**
 * Add a Vector to this swizzle. Set this swizzle (and the underlying Vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator+=(const Vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	return *(Vector2<T>*)this;
}

/**
 * Subtract a Vector from this swizzle. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator-=(const Vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	return *(Vector2<T>*)this;
}

/**
 * Multiply this swizzle by a Vector. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified Vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator*=(const Vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	return *(Vector2<T>*)this;
}

/**
 * Divide this swizzle by a Vector. Set this swizzle (and the underlying Vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified Vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T>& Swizzle2<T, N, E1, E2>::operator/=(const Vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	return *(Vector2<T>*)this;
}


#endif
