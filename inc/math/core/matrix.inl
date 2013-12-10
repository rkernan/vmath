#ifndef MATH_CORE_MATRIX_INL
#define MATH_CORE_MATRIX_INL

#include <array>
#include <cstddef>

#include "matrix.hpp"

using namespace math::core;

/**
 * Set this matrix equal to another.
 * @param other Matrix to set equal to.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator=(const Matrix<T, N, M>& other) {
	for (std::size_t i = 0; i < N; i++) {
		this->data[i] = other.data[i];
	}
	return *this;
}

/**
 * Access a matrix element using an index.
 * @param idx Location of element to access.
 * @return Accessed element.
 */
template<typename T, std::size_t N, std::size_t M>
T Matrix<T, N, M>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

/**
 * Add and modify a vector element by index.
 * @param idx Location of element to access.
 * @return Modified element.
 */
template<typename T, std::size_t N, std::size_t M>
T& Matrix<T, N, M>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

/**
 * Negate a matrix.
 * @return The matrix negated.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator-(void) const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = -this->data[i];
	}
	return R;
}

/**
 * Matrix addition.
 * @param W Matrix to add.
 * @return The matrix sum.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator+(const Matrix<T, N, M>& W) const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] + W.data[i];
	}
	return R;
}

/**
 * Matrix addition. Copy the result into this matrix.
 * @param W Matrix to add.
 * @return The modified matrix (matrix sum).
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const Matrix<T, N, M>& W) {
	return *this = *this + W;
}

/**
 * Matrix subtraction.
 * @param W Matrix to subtract.
 * @return The matrix difference.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator-(const Matrix<T, N, M>& W) const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] - W.data[i];
	}
	return R;
}

/**
 * Matrix subtraction. Copy the result into this matrix.
 * @param W Matrix to subtract.
 * @return The modified matrix (matrix difference).
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator-=(const Matrix<T, N, M>& W) {
	return *this = *this - W;
}

/**
 * Matrix multiplication.
 * @param W Matrix to multiply by.
 * @return Matrix product.
 */
template<typename T, std::size_t N, std::size_t M>
template<std::size_t P>
Matrix<T, P, M> Matrix<T, N, M>::operator*(const Matrix<T, P, N>& W) const {
	// TODO
	(void)W;
	return Matrix<T, P, M>();
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return Matrix-scalar product.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator*(const T& s) const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] * s;
	}
	return R;
}

/**
 * Scalar multiplication. Copy the result into this matrix.
 * @param s Scalar to multiply by.
 * @return The modified matrix (matrix-scalar product).
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Matrix-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator/(const T& s) const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] / s;
	}
	return R;
}

/**
 * Scalar division. Copy the result into this matrix.
 * @param s Scalar to divide by.
 * @return The modified matrix (matrix-scalar quotient).
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Traspose this matrix.
 * @return Matrix transpose.
 */
template<typename T, std::size_t N, std::size_t M>
Matrix<T, M, N> Matrix<T, N, M>::transpose(void) const {
	Matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = 0; j < M; j++) {
			R.data[j][i] = this->data[i][j];
		}
	}
	return R;
}

/**
 * Check matrix equality.
 * @param other Matrix to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t M>
bool Matrix<T, N, M>::operator==(const Matrix<T, N, M>& other) const {
	bool equal = true;
	for (std::size_t i = 0; i < N; i++) {
		equal = equal && this->data[i] == other.data[i];
	}
	return equal;
}

/**
 * Check matrix inequality.
 * @param other Matrix to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t M>
bool Matrix<T, N, M>::operator!=(const Matrix<T, N, M>& other) const {
	return !(*this == other);
}

/**
 * Calculate this matrix determinant.
 * @return Matrix determinant.
 */
template<typename T, std::size_t N, std::size_t M>
template<typename U, typename>
T Matrix<T, N, M>::det(void) const {
	// TODO
	return T();
}

/**
 * Calculate the matrix inverse.
 * @return Matrix inverse.
 */
template<typename T, std::size_t N, std::size_t M>
template<typename U, typename>
Matrix<T, N, M> Matrix<T, N, M>::inverse(void) const {
	// TODO
	return Matrix<T, N, M>();
}

#endif
