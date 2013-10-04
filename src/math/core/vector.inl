#ifndef MATH_CORE_VECTOR_INL
#define MATH_CORE_VECTOR_INL

#include "vector.hpp"

using namespace math::core;

template<typename T, std::size_t N>
Vector<T, N>::Vector(void) {
	for (std::size_t i = 0; i < N; i++) {
		this->values[i] = T();
	}
}

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
	// TODO Check for index out of bounds.
	return this->values[idx];
}

/**
 * Access and modify a vector element by index.
 * @param idx Location of element to access.
 */
template<typename T, std::size_t N>
T& Vector<T, N>::operator[](const std::size_t idx) {
	// TODO Check for index out of bounds.
	return this->values[idx];
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& other) {
	for (std::size_t i = 0; i < N; i++) {
		this->value[i] = other.values[i];
	}
	return *this;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(void) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = -this->values[i];
	}
	return Vector<T, N>(values);
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] + V.values[i];
	}
	return Vector<T, N>(values);
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& V) {
	return *this = *this + V;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] - V.values[i];
	}
	return Vector<T, N>(values);
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& V) {
	return *this = *this - V;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] * V.values[i];
	}
	return Vector<T, N>(values);
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(const Vector<T, N>& V) {
	return *this = *this * V;
}

template<typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(const Vector<T, N>& V) const {
	T values[N];
	for (std::size_t i = 0; i < N; i++) {
		values[i] = this->values[i] / V.values[i];
	}
	return Vector<T, N>(values);
}

template<typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(const Vector<T, N>& V) {
	return *this = *this / V;
}

#endif