#ifndef MATH_CORE_VECTOR2_INL
#define MATH_CORE_VECTOR2_INL

#include "vector2.hpp"
#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
vector2<T>::vector2(void) : x(), y() {}

/**
 * Parameterized constructor.
 * @param x Vector x-component.
 * @param y Vector y-component.
 */
template<typename T>
vector2<T>::vector2(const T& x, const T& y) : x(x), y(y) {}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T>
vector2<T> vector2<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	return vector2<T>(x, y);
}

/**
 * Component-wise vector addition.
 * @param V Vector to add.
 * @return The component-wise vector sum.
 */
template<typename T>
vector2<T> vector2<T>::operator+(const vector2<T>& V) const {
	T x = this->x + V.x;
	T y = this->y + V.y;
	return vector2<T>(x, y);
}

/**
 * Component-wise vector addition. Copy the result into this vector.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T>
vector2<T>& vector2<T>::operator+=(const vector2<T>& V) {
	return *this = *this + V;
}

/**
 * Component-wise vector subtraction.
 * @param V Vector to subtract.
 * @return The component-wise vector difference.
 */
template<typename T>
vector2<T> vector2<T>::operator-(const vector2<T>& V) const {
	return *this + -V;
}

/**
 * Component-wise vector subtraction. Copy the result into this vector.
 * @param V Vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T>
vector2<T>& vector2<T>::operator-=(const vector2<T>& V) {
	return *this = *this - V;
}

/**
 * Component-wise vector multiplication.
 * @param V Vector to multiply.
 * @return The component-wise product.
 */
template<typename T>
vector2<T> vector2<T>::operator*(const vector2<T>& V) const {
	T x = this->x * V.x;
	T y = this->y * V.y;
	return vector2<T>(x, y);
}

/**
 * Component-wise vector multiplication. Copy the result into this vector.
 * @param V Vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T> 
vector2<T>& vector2<T>::operator*=(const vector2<T>& V) {
	return *this = *this * V;
}

/**
 * Component-wise vector division.
 * @param V Vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T>
vector2<T> vector2<T>::operator/(const vector2<T>& V) const {
	T x = this->x / V.x;
	T y = this->y / V.y;
	return vector2<T>(x, y);
}

/**
 * Component-wise vector division. Copy the result into this vector.
 * @param V Vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T>
vector2<T>& vector2<T>::operator/=(const vector2<T>& V) {
	return *this = *this / V;
}

/**
 * Calculate the nor-negative vector norm (magnitude squared).
 * @return Vector magnitude squared.
 */
template<typename T>
T vector2<T>::norm(void) const {
	return (this->x * this->x) + (this->y * this->y);
}

/**
 * Calculate the vector length.
 * @return Vector magnitude.
 */
template<typename T>
T vector2<T>::mag(void) const {
	return math::sqrt(this->norm());
}

/**
 * Calculate the vector normal.
 * @return Vector normal.
 */
template<typename T>
vector2<T> vector2<T>::normal(void) const {
	T mag = this->mag();
	T x = this->x / mag;
	T y = this->y / mag;
	return vector2<T>(x, y);
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T>
vector2<T>& vector2<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Check vector equality.
 * @param other Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool vector2<T>::operator==(const vector2<T>& other) const {
	return this->x == other.x && this->y == other.y;
}

// TODO Use enable_if to specialize.
template<>
bool vector2<float>::operator==(const vector2<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y);
}

template<>
bool vector2<double>::operator==(const vector2<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y);
}

template<>
bool vector2<long double>::operator==(const vector2<long double>& other) const {
	return math::equals(this->y, other.x) && math::equals(this->y, other.y);
}

/**
 * Check vector inequality.
 * @param other Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T>
bool vector2<T>::operator!=(const vector2<T>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner vector product (dot product).
 * @param V1 Vector to take inner product of.
 * @param V2 Vector to take inner product of.
 * @return Vector dot product.
 */
template<typename T>
T vector2<T>::dot(const vector2<T>& V1, const vector2<T>& V2) {
	return (V1.x * V2.x) + (V1.y * V2.y);
}

/**
 * Calculate the outer vector product (cross product).
 * @param V1 Vector to take outer product of.
 * @param V2 Vector to take outer product of.
 * @return 2-dimensional vector cross product.
 */
template<typename T>
T vector2<T>::cross(const vector2<T>& V1, const vector2<T>& V2) {
	return (V1.x * V2.y) - (V1.y * V2.x);
}

/**
 * Calculate the reflection direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @return Reflection of incident over the normal.
 */
template<typename T>
vector2<T> vector2<T>::reflect(const vector2<T>& I, const vector2<T>& N) {
	return I - static_cast<T>(2.0) * vector2::dot(N, I) * N;
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T>
vector2<T> vector2<T>::refract(const vector2<T>& I, const vector2<T>& N, const T& eta) {
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - vector2::dot(N, I) * vector2::dot(N, I));
	if (k < static_cast<T>(0.0)) {
		return vector2<T>();
	} else {
		return eta * I - (eta * vector2::dot(N, I) + math::sqrt(k)) * N;
	}
}

/**
 * Linearly interpolate between two vectors.
 * @param S Start vector.
 * @param E End vector.
 * @param t Value to interpolate by.
 * @return Interpolated vector.
 */
template<typename T>
vector2<T> lerp(const vector2<T>& S, const vector2<T>& E, const T& t) {
	return S + (t * (E - S));
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return Scalar-vector product.
 */
template<typename T>
vector2<T> math::core::operator*(const T& s, const vector2<T>& V) {
	T x = s * V.x;
	T y = s * V.y;
	return vector2<T>(x, y);
}

/**
 * Ouput to stream.
 * @param out Stream to ouput to.
 * @param V Vector to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& math::core::operator<<(std::ostream& out, const vector2<T>& V) {
	return out << "<" << V.x << ", " << V.y << ">";
}

#endif
