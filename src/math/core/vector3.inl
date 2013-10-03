#ifndef MATH_CORE_vector3_INL
#define MATH_CORE_vector3_INL

#include "vector3.hpp"
#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
vector3<T>::vector3(void) : x(), y() {}

/**
 * Parameterized constructor.
 * @param x Vector x-component.
 * @param y Vector y-component.
 * @param z Vector z-component.
 */
template<typename T>
vector3<T>::vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

/**
 * Parameterized constructor.
 * @param V 2-d vector.
 * @param z Vector z-component.
 */
template<typename T>
vector3<T>::vector3(const vector2<T>& V, const T& z) : vector3(V.x, V.y, z) {}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T>
vector3<T> vector3<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	T z = -this->z;
	return vector3<T>(x, y, z);
}

/**
 * Component-wise addition.
 * @param V Vector to add.
 * @return The component-wise sum.
 */
template<typename T>
vector3<T> vector3<T>::operator+(const vector3<T>& V) const {
	T x = this->x + V.x;
	T y = this->y + V.y;
	T z = this->z + V.z;
	return vector3<T>(x, y, z);
}

/**
 * Component-wise addition. Copy the result into this vector.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T>
vector3<T>& vector3<T>::operator+=(const vector3<T>& V) {
	return *this = *this + V;
}

/**
 * Component-wise subtraction.
 * @param V Vector to subtract.
 * @return The component-wise vector difference.
 */
template<typename T>
vector3<T> vector3<T>::operator-(const vector3<T>& V) const {
	T x = this->x - V.x;
	T y = this->y - V.y;
	T z = this->z - V.z;
	return vector3<T>(x, y, z);
}

/**
 * Component-wise subtraction. Copy the result into this vector.
 * @param V Vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T>
vector3<T>& vector3<T>::operator-=(const vector3<T>& V) {
	return *this = *this - V;
}

/**
 * Component-wise multiplication.
 * @param V Vector to multiply.
 * @return The component-wise product.
 */
template<typename T>
vector3<T> vector3<T>::operator*(const vector3<T>& V) const {
	T x = this->x * V.x;
	T y = this->y * V.y;
	T z = this->z * V.z;
	return vector3<T>(x, y, z);
}

/**
 * Component-wise multiplication. Copy the result into this vector.
 * @param V Vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T> 
vector3<T>& vector3<T>::operator*=(const vector3<T>& V) {
	return *this = *this * V;
}

/**
 * Component-wise division.
 * @param V Vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T>
vector3<T> vector3<T>::operator/(const vector3<T>& V) const {
	T x = this->x / V.x;
	T y = this->y / V.y;
	T z = this->z / V.z;
	return vector3<T>(x, y, z);
}

/**
 * Component-wise division. Copy the result into this vector.
 * @param V Vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T>
vector3<T>& vector3<T>::operator/=(const vector3<T>& V) {
	return *this = *this / V;
}

/**
 * Scalar division
 * @param s Scalar to divide by.
 * @return Vector-scalar quotient.
 */
template<typename T>
vector3<T> vector3<T>::operator/(const T& s) const {
	T x = this->x / s;
	T y = this->y / s;
	T z = this->z / s;
	return vector3<T>(x, y, z);
}

/**
 * Calculate the vector length.
 * @return Vector magnitude.
 */
template<typename T>
T vector3<T>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T>
T vector3<T>::mag2(void) const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

/**
 * Calculate the vector normal.
 * @return Vector normal.
 */
template<typename T>
vector3<T> vector3<T>::normal(void) const {
	return *this / this->mag();
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T>
vector3<T>& vector3<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Check vector equality.
 * @param other Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool vector3<T>::operator==(const vector3<T>& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

// TODO Use enable_if to specialize.
template<>
bool vector3<float>::operator==(const vector3<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z);
}

template<>
bool vector3<double>::operator==(const vector3<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z);
}

template<>
bool vector3<long double>::operator==(const vector3<long double>& other) const {
	return math::equals(this->y, other.x) && math::equals(this->y, other.y) && math::equals(this->z, other.z);
}

/**
 * Check vector inequality.
 * @param other Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T>
bool vector3<T>::operator!=(const vector3<T>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner vector product (dot product).
 * @param V1 Vector to take inner product of.
 * @param V2 Vector to take inner product of.
 * @return Vector dot product.
 */
template<typename T>
T vector3<T>::dot(const vector3<T>& V1, const vector3<T>& V2) {
	return (V1.x * V2.x) + (V1.y * V2.y) + (V1.z * V2.z);
}

/**
 * Calculate the outer vector product (cross product).
 * @param V1 Vector to take outer product of.
 * @param V2 Vector to take outer product of.
 * @return 3-dimensional vector cross product.
 */
template<typename T>
vector3<T> vector3<T>::cross(const vector3<T>& V1, const vector3<T>& V2) {
	T x = (V1.y * V2.z) - (V1.z * V2.y);
	T y = (V1.z * V2.x) - (V1.x * V2.z);
	T z = (V1.x * V2.y) - (V1.y * V2.x);
	return vector3<T>(x, y, z);
}

/**
 * Calculate the reflection direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @return Reflection of incident over the normal.
 */
template<typename T>
vector3<T> vector3<T>::reflect(const vector3<T>& I, const vector3<T>& N) {
	return I - static_cast<T>(2.0) * vector3::dot(N, I) * N;
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T>
vector3<T> vector3<T>::refract(const vector3<T>& I, const vector3<T>& N, const T& eta) {
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - vector3::dot(N, I) * vector3::dot(N, I));
	if (k < static_cast<T>(0.0)) {
		return vector3<T>();
	} else {
		return eta * I - (eta * vector3::dot(N, I) + math::sqrt(k)) * N;
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
vector3<T> lerp(const vector3<T>& S, const vector3<T>& E, const T& t) {
	return S + (t * (E - S));
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return Scalar-vector product.
 */
template<typename T>
vector3<T> math::core::operator*(const T& s, const vector3<T>& V) {
	T x = s * V.x;
	T y = s * V.y;
	T z = s * V.z;
	return vector3<T>(x, y, z);
}

/**
 * Ouput to stream.
 * @param out Stream to ouput to.
 * @param V Vector to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& math::core::operator<<(std::ostream& out, const vector3<T>& V) {
	return out << "<" << V.x << ", " << V.y << ", " << V.z << ">";
}

#endif
