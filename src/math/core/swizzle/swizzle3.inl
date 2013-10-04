#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_INL
#define MATH_CORE_SWIZZLE_SWIZZLE3_INL

#include "swizzle3.hpp"
#include "../vector3.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector3<T>() {
	return Vector3<T>(this->values[E1], this->values[E2], this->values[E3]);
}

/**
 * Set this swizzle (and the underlying vector) equal to a vector.
 * @param V Vector to set equal to.
 * @return The modified vector.
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
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T> Swizzle3<T, N, E1, E2, E3>::operator+(const Vector3<T>& V) const {
	return *(Vector3<T>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator+=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	return *this = *this + V;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T> Swizzle3<T, N, E1, E2, E3>::operator-(const Vector3<T>& V) const {
	return *(Vector3<T>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator-=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	return *this = *this - V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply by.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T> Swizzle3<T, N, E1, E2, E3>::operator*(const Vector3<T>& V) const {
	return *(Vector3<T>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator*=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	return *this = *this * V;
}

/**
 * Divide this swizzle be a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T> Swizzle3<T, N, E1, E2, E3>::operator/(const Vector3<T>& V) const {
	return *(Vector3<T>*)this * V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator/=(const Vector3<T>& V) {
	// TODO possible if: E1 != E2 != E3
	return *this = *this / V;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool Swizzle3<T, N, E1, E2, E3>::operator==(const Vector3<T>& V) const {
	return *(Vector3<T>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
bool Swizzle3<T, N, E1, E2, E3>::operator!=(const Vector3<T>& V) const {
	return *(Vector3<T>*)this != V;
}

#endif
