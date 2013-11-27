#ifndef MATH_CORE_VECTOR_INL
#define MATH_CORE_VECTOR_INL

#include "vector.hpp"

#include <cstddef>
#include <ostream>
#include <stdexcept>
#include <type_traits>

#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T, std::size_t N>
Vector<T, N>::Vector(void) {
	for (std::size_t i = 0; i < N; i++) {
		this->values[i] = T();
	}
}

/**
 * Parameterized constructor.
 * @param values Array to store as vector.
 */
template<typename T, std::size_t N>
Vector<T, N>::Vector(const T values[N]) {
	for (std::size_t i = 0; i < N; i++) {
		this->values[i] = values[i];
	}
}

/**
 * Access a vector element using an index.
 * @param idx Location of element to access.
 */
template<typename T, std::size_t N>
T Vector<T, N>::operator[](const std::size_t idx) const {
	if (idx >= N) {
		throw std::out_of_range("todo");
	}
	return this->values[idx];
}

/**
 * Access and modify a vector element by index.
 * @param idx Location of element to access.
 */
template<typename T, std::size_t N>
T& Vector<T, N>::operator[](const std::size_t idx) {
	if (idx >= N) {
		throw std::out_of_range("todo");
	}
	return this->values[idx];
}

/**
 * Set this vector equal to another.
 * @param other Vector to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& other) {
	for (std::size_t i = 0; i < N; i++) {
		this->values[i] = other.values[i];
	}
	return *this;
}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(void) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = -this->values[i];
	}
	return Vector<T, N>(values);
}

/**
 * Component-wise addition.
 * @param V Vector to add.
 * @return The component-wise sum.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] + V.values[i];
	}
	return Vector<T, N>(values);
}

/**
 * Component-wise addition. Copy the result into this vector.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& V) {
	return *this = *this + V;
}

/**
 * Component-wise subtraction.
 * @param V Vector to subtract.
 * @return The component-wise difference.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] - V.values[i];
	}
	return Vector<T, N>(values);
}

/**
 * Component-wise subtraction. Copy the result into this vector.
 * @param V Vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& V) {
	return *this = *this - V;
}

/**
 * Component-wise multiplication.
 * @param V Vector to multiply.
 * @return The component-wise product.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] * V.values[i];
	}
	return Vector<T, N>(values);
}

/**
 * Component-wise multiplication. Copy the result into this vector.
 * @param V Vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(const Vector<T, N>& V) {
	return *this = *this * V;
}

/**
 * Component-wise division.
 * @param V Vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] / V.values[i];
	}
	return Vector<T, N>(values);
}

/**
 * Component-wise division. Copy the result into this vector.
 * @param V Vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(const Vector<T, N>& V) {
	return *this = *this / V;
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return Vector-scalar product.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const T& s) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] * s;
	}
	return Vector<T, N>(values);
}

/**
 * Scalar multiplication. Copy the result into this vector.
 * @param s Scalar to multiply by.
 * @return Vector-scalar product.
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Vector-scalar quotient.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(const T& s) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] / s;
	}
	return Vector<T, N>(values);
}

/**
 * Scalar division. Copy the result into this vector.
 * @param s Scalar to divide by.
 * @return Vector-scalar quotient.
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Calculate the vector length.
 * @return Vector magnitude.
 */
template<typename T, std::size_t N>
T Vector<T, N>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T, std::size_t N>
T Vector<T, N>::mag2(void) const {
	T mag2 = T();
	for (std::size_t i = 0; i < N; i++) {
		mag2 += this->values[i] * this->values[i];
	}
	return mag2;
}

/**
 * Calculate the vector normal.
 * @return Vector normal.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::normal(void) const {
	return *this / this->mag();
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::normalize(void) {
	return *this = this->normal();
}

/**
 * Equals helper. Allows for partial specialization of the equality operator.
 * @param V1 Vector to check equality with.
 * @param V2 Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
static inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type
		equals_helper(const Vector<T, N>& V1, const Vector<T, N>& V2) {
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && math::equals(V1.values[i], V2.values[i]);
	}
	return equal;
}

template<typename T, std::size_t N>
static inline typename std::enable_if<!std::is_floating_point<T>::value, bool>::type
		equals_helper(const Vector<T, N>& V1, const Vector<T, N>& V2) {
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && V1.values[i] == V2.values[i];
	}
	return equal;
}

/**
 * Check Vector equality.
 * @param other Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
bool Vector<T, N>::operator==(const Vector<T, N>& other) const {
	return equals_helper(*this, other);
}

/**
 * Check Vector inequality.
 * @param other Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N>
bool Vector<T, N>::operator!=(const Vector<T, N>& other) const {
	return !(*this == other);
}

template<typename T, std::size_t N>
T Vector<T, N>::dot(const Vector<T, N>& V1, const Vector<T, N>& V2) {
	T dot = T();
	for (std::size_t i = 0; i < N; ++i) {
		dot += V1.values[i] * V2.values[i];
	}
	return dot;
}

/**
 * Calculate the reflection direction.
 * @param I Incident vector.
 * @param S Surface normal vector.
 * @return Reflection of incident over the normal.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::reflect(const Vector<T, N>& I, const Vector<T, N>& S) {
	return I - S * static_cast<T>(2.0) * Vector<T, N>::dot(S, I);
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param S Surface normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::refract(const Vector<T, N>& I, const Vector<T, N>& S, const T& eta) {
	T S_dot_I = Vector<T, N>::dot(S, I);
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - S_dot_I * S_dot_I);
	if (k < static_cast<T>(0.0)) {
		return Vector<T, N>();
	} else {
		return I * eta - S * (eta * S_dot_I + math::sqrt(k));
	}
}

/**
 * Linearly interpolate between two vectors.
 * @param S Start vector.
 * @param E End vector.
 * @param t Value to interpolate by.
 * @return Interpolated vector.
 */
template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::lerp(const Vector<T, N>& S, const Vector<T, N>& E, const T& t) {
	return S + ((E - S) * t);
}

/**
 * Calculate the outer vector product (cross product). Only valid for 2d
 * vectors.
 * @param V1 Vector to take outer product of.
 * @param V2 Vector to take outer product of.
 * @return 2-dimensional vector cross product.
 */
template<typename T, std::size_t N>
template<typename>
T Vector<T, N>::cross(const Vector<T, N>& V1, const Vector<T, N>& V2) {
	return (V1.x * V2.y) - (V1.y * V2.x);
}

/**
 * Calculate the outer vector product (cross product). Only valid for 3d
 * vectors.
 * @param V1 Vector to take outer product of.
 * @param V2 Vector to take outer product of.
 * @return 3-dimensional vector cross product.
 */
template<typename T, std::size_t N>
template<typename>
Vector<T, N> Vector<T, N>::cross(const Vector<T, N>& V1, const Vector<T, N>& V2) {
	T x = (V1.y * V2.z) - (V1.z * V2.y);
	T y = (V1.z * V2.x) - (V1.x * V2.z);
	T z = (V1.x * V2.y) - (V1.y * V2.x);
	return Vector<T, N>(x, y, z);
}

#endif
