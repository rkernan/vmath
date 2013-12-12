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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator=(const Matrix<T, M, N>& other) {
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
template<typename T, std::size_t M, std::size_t N>
Vector<T, M> Matrix<T, M, N>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

/**
 * Add and modify a vector element by index.
 * @param idx Location of element to access.
 * @return Modified element.
 */
template<typename T, std::size_t M, std::size_t N>
Vector<T, M>& Matrix<T, M, N>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

/**
 * Negate a matrix.
 * @return The matrix negated.
 */
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator-(void) const {
	Matrix<T, M, N> R;
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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator+(const Matrix<T, M, N>& W) const {
	Matrix<T, M, N> R;
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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator+=(const Matrix<T, M, N>& W) {
	return *this = *this + W;
}

/**
 * Matrix subtraction.
 * @param W Matrix to subtract.
 * @return The matrix difference.
 */
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator-(const Matrix<T, M, N>& W) const {
	Matrix<T, M, N> R;
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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator-=(const Matrix<T, M, N>& W) {
	return *this = *this - W;
}

/**
 * Matrix multiplication.
 * @param W Matrix to multiply by.
 * @return Matrix product.
 */
template<typename T, std::size_t M, std::size_t N>
template<std::size_t P>
Matrix<T, M, P> Matrix<T, M, N>::operator*(const Matrix<T, N, P>& W) const {
	Matrix<T, M, P> R;
	for (std::size_t m = 0; m < M; m++) {
		for (std::size_t p = 0; p < P; p++) {
			for (std::size_t n = 0; n < N; n++) {
				R[p][m] += this->data[n][m] * W[p][n];
			}
		}
	}
	return R;
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return Matrix-scalar product.
 */
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator*(const T& s) const {
	Matrix<T, M, N> R;
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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return Matrix-scalar quotient.
 */
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator/(const T& s) const {
	Matrix<T, M, N> R;
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
template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Traspose this matrix.
 * @return Matrix transpose.
 */
template<typename T, std::size_t M, std::size_t N>
Matrix<T, N, M> Matrix<T, M, N>::transpose(void) const {
	Matrix<T, N, M> R;
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
template<typename T, std::size_t M, std::size_t N>
bool Matrix<T, M, N>::operator==(const Matrix<T, M, N>& other) const {
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
template<typename T, std::size_t M, std::size_t N>
bool Matrix<T, M, N>::operator!=(const Matrix<T, M, N>& other) const {
	return !(*this == other);
}

/**
 * Calculate this matrix determinant.
 * @return Matrix determinant.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
T Matrix<T, M, N>::det(void) const {
	// TODO
	return T();
}

/**
 * Calculate the matrix inverse.
 * @return Matrix inverse.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::inverse(void) const {
	// TODO
	return Matrix<T, M, N>();
}

#endif
