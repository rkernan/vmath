#ifndef MATH_CORE_SWIZZLE_INL
#define MATH_CORE_SWIZZLE_INL

#include "swizzle.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator vector2<T>() {
	return vector2<T>(this->values[E1], this->values[E2]);
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.  @param V
 * Vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator=(const vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	return *(vector2<T>*)this;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator+=(const vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	return *(vector2<T>*)this;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator-=(const vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	return *(vector2<T>*)this;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator*=(const vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	return *(vector2<T>*)this;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator/=(const vector2<T>& V) {
	// TODO possible if: E1 != E2
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	return *(vector2<T>*)this;
}

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator vector3<T>() {
	return vector3<T>(this->values[E1], this->values[E2], this->values[E3]);
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.  @param V
 * Vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator=(const vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	return *(vector3<T>*)this;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator+=(const vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->valeus[E3] += V.z;
	return *(vector3<T>*)this;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator-=(const vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	return *(vector3<T>*)this;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator*=(const vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	return *(vector3<T>*)this;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator/=(const vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	return *(vector3<T>*)this;
}

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator vector4<T>() {
	return vector4<T>(this->values[E1], this->values[E2], this->values[E3], this->values[E4]);
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.  @param V
 * Vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	this->values[E4] = V.w;
	return *(vector3<T>*)this;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->values[E3] += V.z;
	this->values[E4] += V.w;
	return *(vector3<T>*)this;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	this->values[E4] -= V.w;
	return *(vector3<T>*)this;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector (component-wise product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	this->values[E4] *= V.w;
	return *(vector3<T>*)this;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param v Vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	this->values[E4] /= V.w;
	return *(vector3<T>*)this;
}

#endif
