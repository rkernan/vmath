#ifndef MATH_CORE_VECTOR4_INL
#define MATH_CORE_VECTOR4_INL

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
Vector4<T>::Vector4(void) : x(), y() {}

/**
 * Parameterized constructor.
 * @param x Vector x-component.
 * @param y Vector y-component.
 * @param z Vector z-component.
 * @param w Vector w-component.
 */
template<typename T>
Vector4<T>::Vector4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

/**
 * Parameterized constructor.
 * @param V 2-d vector.
 * @param z Vector z-component.
 * @param w Vector w-component.
 */
template<typename T>
Vector4<T>::Vector4(const Vector2<T>& V, const T& z, const T& w) : Vector4(V.x, V.y, z, w) {}

/**
 * Paremeterized constructor.
 * @param V 3-d vector.
 * @param w Vector w-component.
 */
template<typename T>
Vector4<T>::Vector4(const Vector3<T>& V, const T& w) : Vector4(V.x, V.y, V.z, w) {}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T>
Vector4<T> Vector4<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	T z = -this->z;
	T w = -this->w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Component-wise addition.
 * @param V Vector to add.
 * @return The component-wise sum.
 */
template<typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T>& V) const {
	T x = this->x + V.x;
	T y = this->y + V.y;
	T z = this->z + V.z;
	T w = this->w + V.w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Component-wise addition. Copy the result into this vector.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& V) {
	return *this = *this + V;
}

/**
 * Component-wise subtraction.
 * @param V Vector to subtract.
 * @return The component-wise difference.
 */
template<typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T>& V) const {
	T x = this->x - V.x;
	T y = this->y - V.y;
	T z = this->z - V.z;
	T w = this->w - V.w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Component-wise subtraction. Copy the result into this vector.
 * @param V Vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& V) {
	return *this = *this - V;
}

/**
 * Component-wise multiplication.
 * @param V Vector to multiply.
 * @return The component-wise product.
 */
template<typename T>
Vector4<T> Vector4<T>::operator*(const Vector4<T>& V) const {
	T x = this->x * V.x;
	T y = this->y * V.y;
	T z = this->z * V.z;
	T w = this->w * V.w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Component-wise multiplication. Copy the result into this vector.
 * @param V Vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T> 
Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& V) {
	return *this = *this * V;
}

/**
 * Component-wise division.
 * @param V Vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T>
Vector4<T> Vector4<T>::operator/(const Vector4<T>& V) const {
	T x = this->x / V.x;
	T y = this->y / V.y;
	T z = this->z / V.z;
	T w = this->w / V.w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Component-wise division. Copy the result into this vector.
 * @param V Vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T>
Vector4<T>& Vector4<T>::operator/=(const Vector4<T>& V) {
	return *this = *this / V;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Vector-scalar quotient.
 */
template<typename T>
Vector4<T> Vector4<T>::operator/(const T& s) const {
	T x = this->x / s;
	T y = this->y / s;
	T z = this->z / s;
	T w = this->w / s;
	return Vector4<T>(x, y, z, w);
}

/**
 * Calculate the vector length.
 * @return Vector magnitude.
 */
template<typename T>
T Vector4<T>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T>
T Vector4<T>::mag2(void) const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
}

/**
 * Calculate the Vector normal.
 * @return Vector normal.
 */
template<typename T>
Vector4<T> Vector4<T>::normal(void) const {
	// TODO divide by zero
	return *this / this->mag();
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T>
Vector4<T>& Vector4<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Check Vector equality.
 * @param other Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool Vector4<T>::operator==(const Vector4<T>& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

// TODO Use enable_if to specialize.
template<>
bool Vector4<float>::operator==(const Vector4<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool Vector4<double>::operator==(const Vector4<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

template<>
bool Vector4<long double>::operator==(const Vector4<long double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y)
		&& math::equals(this->z, other.z) && math::equals(this->w, other.w);
}

/**
 * Check Vector inequality.
 * @param other Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T>
bool Vector4<T>::operator!=(const Vector4<T>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner vector product (dot product).
 * @param V1 Vector to take inner product of.
 * @param V2 Vector to take inner product of.
 * @return Vector dot product.
 */
template<typename T>
T Vector4<T>::dot(const Vector4<T>& V1, const Vector4<T>& V2) {
	return (V1.x * V2.x) + (V1.y * V2.y) + (V1.z * V2.z) + (V1.w * V2.w);
}

/**
 * Calculate the reflection direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @return Reflection of incident over the normal.
 */
template<typename T>
Vector4<T> Vector4<T>::reflect(const Vector4<T>& I, const Vector4<T>& N) {
	return I - static_cast<T>(2.0) * Vector4::dot(N, I) * N;
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T>
Vector4<T> Vector4<T>::refract(const Vector4<T>& I, const Vector4<T>& N, const T& eta) {
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - Vector4::dot(N, I) * Vector4::dot(N, I));
	if (k < static_cast<T>(0.0)) {
		return Vector4<T>();
	} else {
		return eta * I - (eta * Vector4::dot(N, I) + math::sqrt(k)) * N;
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
Vector4<T> lerp(const Vector4<T>& S, const Vector4<T>& E, const T& t) {
	return S + (t * (E - S));
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return Scalar-vector product.
 */
template<typename T>
Vector4<T> math::core::operator*(const T& s, const Vector4<T>& V) {
	T x = s * V.x;
	T y = s * V.y;
	T z = s * V.z;
	T w = s * V.w;
	return Vector4<T>(x, y, z, w);
}

/**
 * Ouput to stream.
 * @param out Stream to ouput to.
 * @param V Vector to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& math::core::operator<<(std::ostream& out, const Vector4<T>& V) {
	return out << "<" << V.x << ", " << V.y << ", " << V.z << ", " << V.w << ">";
}

#endif
