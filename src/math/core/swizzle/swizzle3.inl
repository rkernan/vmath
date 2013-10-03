#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_INL
#define MATH_CORE_SWIZZLE_SWIZZLE3_INL

#include "swizzle3.hpp"
#include "../vector3.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a Vector.
 * @return Converted Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector3<T>() {
	return Vector3<T>(this->values[E1], this->values[E2], this->values[E3]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.  @param V
 * Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	return *(Vector3<T>*)this;
}

/**
 * Add a Vector to this swizzle. Set this swizzle (and the underlying Vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator+=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->valeus[E3] += V.z;
	return *(Vector3<T>*)this;
}

/**
 * Subtract a Vector from this swizzle. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator-=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	return *(Vector3<T>*)this;
}

/**
 * Multiply this swizzle by a Vector. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified Vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator*=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	return *(Vector3<T>*)this;
}

#endif
