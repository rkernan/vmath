#ifndef MATH_CORE_VECTOR_INL
#define MATH_CORE_VECTOR_INL

#include <math/core/vector.hpp>

#include <stdexcept>
#include <string>
#include <math/functions.hpp>

namespace math {
namespace core {

/**
 * Access a vector element using an index.
 * @param idx Location of element to access.
 * @return Accessed element.
 */
template<typename T, std::size_t N>
T vector<T, N>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

/**
 * Access and modify a vector element by index.
 * @param idx Location of element to access.
 * @return Modified element.
 */
template<typename T, std::size_t N>
T& vector<T, N>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator-(void) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = -this->data[i];
	}
	return R;
}

/**
 * Component-wise addition.
 * @param V vector to add.
 * @return The component-wise sum.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator+(const vector<T, N>& V) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] + V.data[i];
	}
	return R;
}

/**
 * Component-wise addition. Copy the result into this vector.
 * @param V vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator+=(const vector<T, N>& V) {
	return *this = *this + V;
}

/**
 * Component-wise subtraction.
 * @param V vector to subtract.
 * @return The component-wise difference.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator-(const vector<T, N>& V) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] - V.data[i];
	}
	return R;
}

/**
 * Component-wise subtraction. Copy the result into this vector.
 * @param V vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator-=(const vector<T, N>& V) {
	return *this = *this - V;
}

/**
 * Component-wise multiplication.
 * @param V vector to multiply.
 * @return The component-wise product.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator*(const vector<T, N>& V) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] * V.data[i];
	}
	return R;
}

/**
 * Component-wise multiplication. Copy the result into this vector.
 * @param V vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator*=(const vector<T, N>& V) {
	return *this = *this * V;
}

/**
 * Component-wise division.
 * @param V vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator/(const vector<T, N>& V) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] / V.data[i];
	}
	return R;
}

/**
 * Component-wise division. Copy the result into this vector.
 * @param V vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator/=(const vector<T, N>& V) {
	return *this = *this / V;
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return vector-scalar product.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator*(const T& s) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] * s;
	}
	return R;
}

/**
 * Scalar multiplication. Copy the result into this vector.
 * @param s Scalar to multiply by.
 * @return vector-scalar product.
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return vector-scalar quotient.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::operator/(const T& s) const {
	vector<T, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] / s;
	}
	return R;
}

/**
 * Scalar division. Copy the result into this vector.
 * @param s Scalar to divide by.
 * @return vector-scalar quotient.
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Calculate the vector length.
 * @return vector magnitude.
 */
template<typename T, std::size_t N>
T vector<T, N>::mag(void) const {
	return math::sqrt(this->mag2());
}

/**
 * Calculate the magnitude squared.
 * @return Magnitude squared.
 */
template<typename T, std::size_t N>
T vector<T, N>::mag2(void) const {
	T mag2 = T();
	for (std::size_t i = 0; i < N; i++) {
		mag2 += this->data[i] * this->data[i];
	}
	return mag2;
}

/**
 * Calculate the vector normal.
 * @return vector normal.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::normal(void) const {
	return *this / this->mag();
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T, std::size_t N>
vector<T, N>& vector<T, N>::normalize(void) {
	return *this = this->normal();
}

/**
 * Equals helper. Allows for partial specialization of the equality operator.
 * Specialization for vector with floats.
 * @param V1 vector to check equality with.
 * @param V2 vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
static inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type
		equals_helper(const vector<T, N>& V1, const vector<T, N>& V2) {
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && math::equals(V1.data[i], V2.data[i]);
	}
	return equal;
}

/**
 * Equals helper. Allows for partial specialization of the equality operator.
 * Specialization for vector with integers or other.
 * @param V1 vector to check equality with.
 * @param V2 vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
static inline typename std::enable_if<!std::is_floating_point<T>::value, bool>::type
		equals_helper(const vector<T, N>& V1, const vector<T, N>& V2) {
	bool equal = true;
	for (std::size_t i = 0; i < N; ++i) {
		equal = equal && V1.data[i] == V2.data[i];
	}
	return equal;
}

/**
 * Check vector equality.
 * @param other vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N>
bool vector<T, N>::operator==(const vector<T, N>& other) const {
	return equals_helper(*this, other);
}

/**
 * Check vector inequality.
 * @param other vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N>
bool vector<T, N>::operator!=(const vector<T, N>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner vector product (dot product).
 * @param V1 vector to take dot product of.
 * @param V2 vector to take dot product of.
 * @return vector dot product.
 */
template<typename T, std::size_t N>
T vector<T, N>::dot(const vector<T, N>& V1, const vector<T, N>& V2) {
	T dot = T();
	for (std::size_t i = 0; i < N; ++i) {
		dot += V1.data[i] * V2.data[i];
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
vector<T, N> vector<T, N>::reflect(const vector<T, N>& I, const vector<T, N>& S) {
	return I - S * static_cast<T>(2.0) * vector<T, N>::dot(S, I);
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param S Surface normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T, std::size_t N>
vector<T, N> vector<T, N>::refract(const vector<T, N>& I, const vector<T, N>& S, const T& eta) {
	T S_dot_I = vector<T, N>::dot(S, I);
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - S_dot_I * S_dot_I);
	if (k < static_cast<T>(0.0)) {
		return vector<T, N>();
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
vector<T, N> vector<T, N>::lerp(const vector<T, N>& S, const vector<T, N>& E, const T& t) {
	return S + ((E - S) * t);
}

/**
 * Calculate the outer vector product (cross product). Only valid for 2d
 * vectors.
 * @param V1 vector to take outer product of.
 * @param V2 vector to take outer product of.
 * @return 2-dimensional vector cross product.
 */
template<typename T, std::size_t N>
template<typename U, typename>
T vector<T, N>::cross(const vector<T, N>& V1, const vector<T, N>& V2) {
	return (V1.x * V2.y) - (V1.y * V2.x);
}

/**
 * Calculate the outer vector product (cross product). Only valid for 3d
 * vectors.
 * @param V1 vector to take outer product of.
 * @param V2 vector to take outer product of.
 * @return 3-dimensional vector cross product.
 */
template<typename T, std::size_t N>
template<typename U, typename>
vector<T, N> vector<T, N>::cross(const vector<T, N>& V1, const vector<T, N>& V2) {
	U x = (V1.y * V2.z) - (V1.z * V2.y);
	U y = (V1.z * V2.x) - (V1.x * V2.z);
	U z = (V1.x * V2.y) - (V1.y * V2.x);
	return vector<U, N>(x, y, z);
}

} // namespace core
} // namespace math

#endif
