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
Swizzle4<T, N, E1, E2, E3, E4>::operator Vector<T, 4>() {
	return Vector<T, 4>(this->values[E1], this->values[E2], this->values[E3], this->values[E4]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.
 * @param V Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const Vector<T, 4>& V) {
	static_assert(swizzle_has_unique_elems<4, E1, E2, E3, E4>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	this->values[E4] = V.w;
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
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const Vector<T, 4>& V) {
	static_assert(swizzle_has_unique_elems<4, E1, E2, E3, E4>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
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
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const Vector<T, 4>& V) {
	static_assert(swizzle_has_unique_elems<4, E1, E2, E3, E4>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
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
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const Vector<T, 4>& V) {
	static_assert(swizzle_has_unique_elems<4, E1, E2, E3, E4>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
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
Vector<T, 4>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const Vector<T, 4>& V) {
	static_assert(swizzle_has_unique_elems<4, E1, E2, E3, E4>::value, MATH_CORE_SWIZZLE_ASSIGN_ERROR);
	return *this = *this / V;
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
 * Scalar-vector multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return The scalar-vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> operator*(const T& s, const Swizzle4<T, N, E1, E2, E3, E4> V) {
	return s * (Vector<T, 4>)V;
}

#endif
