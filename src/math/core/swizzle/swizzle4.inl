#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_INL
#define MATH_CORE_SWIZZLE_SWIZZLE4_INL

#include "swizzle4.hpp"

using namespace math::core;

/**
 * Divide this swizzle by a Vector. Set this swizzle (and the underlying Vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified Vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator/=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	return *(Vector3<T>*)this;
}

/**
 * Convert from a swizzle to a Vector.
 * @return Converted Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector4<T>() {
	return Vector4<T>(this->values[E1], this->values[E2], this->values[E3], this->values[E4]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.  @param V
 * Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	this->values[E4] = V.w;
	return *(Vector3<T>*)this;
}

/**
 * Add a Vector to this swizzle. Set this swizzle (and the underlying Vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->values[E3] += V.z;
	this->values[E4] += V.w;
	return *(Vector3<T>*)this;
}

/**
 * Subtract a Vector from this swizzle. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to add.
 * @return The modified Vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	this->values[E4] -= V.w;
	return *(Vector3<T>*)this;
}

/**
 * Multiply this swizzle by a Vector. Set this swizzle (and the underlying
 * Vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified Vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	this->values[E4] *= V.w;
	return *(Vector3<T>*)this;
}

/**
 * Divide this swizzle by a Vector. Set this swizzle (and the underlying Vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified Vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	this->values[E4] /= V.w;
	return *(Vector3<T>*)this;
}

#endif
