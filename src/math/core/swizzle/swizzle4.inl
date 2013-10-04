#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_INL
#define MATH_CORE_SWIZZLE_SWIZZLE4_INL

#include "swizzle4.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a Vector.
 * @return Converted Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector4<T>() {
	return Vector4<T>(this->values[E1], this->values[E2], this->values[E3], this->values[E4]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.
 * @param V Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	this->values[E4] = V.w;
	return *(Vector4<T>*)this;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T> Swizzle4<T, N, E1, E2, E3, E4>::operator+(const Vector4<T>& V) const {
	return *(Vector4<T>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	return *this = *this + V;
}

/**
 * Subtract a vector from this swizzle.
 * @param V Vector to subtract.
 * @return The vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T> Swizzle4<T, N, E1, E2, E3, E4>::operator-(const Vector4<T>& V) const {
	return *(Vector4<T>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	return *this= *this - V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T> Swizzle4<T, N, E1, E2, E3, E4>::operator*(const Vector4<T>& V) const {
	return *(Vector4<T>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	return *this = *this * V;
}

/**
 * Divide this swizzle by a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T> Swizzle4<T, N, E1, E2, E3, E4>::operator/(const Vector4<T>& V) const {
	return *(Vector4<T>*)this / V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector4<T>& V) {
	// TODO possible if: E1 != E2 != E3 != E4
	return *this = *this / V;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
bool Swizzle4<T, N, E1, E2, E3, E4>::operator==(const Vector4<T>& V) const {
	return *(Vector4<T>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
bool Swizzle4<T, N, E1, E2, E3, E4>::operator!=(const Vector4<T>& V) const {
	return *(Vector4<T>*)this != V;
}

#endif
