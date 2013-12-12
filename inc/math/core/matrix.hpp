#ifndef MATH_CORE_MATRIX_HPP
#define MATH_CORE_MATRIX_HPP

#include <array>
#include <cstddef>

#include "vector.hpp"

namespace math {
namespace core {

/**
 * @struct is_square_matrix
 * @param N Number of columns in the matrix.
 * @param M Number of rows in the matrix.
 * Checks that the given matrix dimensions make a square matrix.
 */
template<std::size_t N, std::size_t M>
struct is_square_matrix : std::integral_constant<bool, N == M> {};

/**
 * @class Matrix
 * @tparam T Storage type.
 * @tparam N Number of columns.
 * @tparam M Number of rows. Defaults to the number of columns.
 */
template<typename T, std::size_t N, std::size_t M = N>
class Matrix {
public:
	Matrix(void) : data() {}
	Matrix(const std::array<Vector<T, M>, N>& data) : data(data) {}
	Matrix(const Matrix<T, N, M>&) = default;
	Matrix(Matrix<T, N, M>&&) = default;

	~Matrix(void) = default;

	Matrix<T, N, M>& operator=(const Matrix<T, N, M>&);

	Vector<T, M> operator[](const std::size_t) const;
	Vector<T, M>& operator[](const std::size_t);

	Matrix<T, N, M> operator-(void) const;
	Matrix<T, N, M> operator+(const Matrix<T, N, M>&) const;
	Matrix<T, N, M>& operator+=(const Matrix<T, N, M>&);
	Matrix<T, N, M> operator-(const Matrix<T, N, M>&) const;
	Matrix<T, N, M>& operator-=(const Matrix<T, N, M>&);

	template<std::size_t P>
	Matrix<T, P, M> operator*(const Matrix<T, P, N>&) const;

	Matrix<T, N, M> operator*(const T&) const;
	Matrix<T, N, M>& operator*=(const T&);
	Matrix<T, N, M> operator/(const T&) const;
	Matrix<T, N, M>& operator/=(const T&);

	Matrix<T, M, N> transpose(void) const;

	bool operator==(const Matrix<T, N, M>&) const;
	bool operator!=(const Matrix<T, N, M>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<N, M>::value && std::is_same<T, U>::value, U>::type>
	T det(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<N, M>::value && std::is_same<T, U>::value, U>::type>
	Matrix<T, N, M> inverse(void) const;

	std::array<Vector<T, M>, N> data;
};

}
}

#include "matrix.inl"

#endif
