#ifndef MATH_CORE_MATRIX_HPP
#define MATH_CORE_MATRIX_HPP

#include <array>
#include <cstddef>

#include "vector.hpp"

namespace math {
namespace core {

/**
 * @class Matrix
 * @tparam T Storage type.
 * @tparam N Number of columns.
 * @tparam M Number of rows. Defaults to the number of columns.
 */
template<typename T, std::size_t N, std::size_t M=N>
class Matrix {
public:
	Matrix(void) : data() {}
	Matrix(const std::array<Vector<T, N>, M>& data) : data(data) {}
	Matrix(const Matrix<T, N, M>&) = default;
	Matrix(Matrix<T, N, M>&&) = default;

	~Matrix(void) = default;

	Matrix<T, N, M>& operator=(const Matrix<T, N, M>&);

	T operator[](const std::size_t) const;
	T& operator[](const std::size_t);

	Matrix<T, N, M> operator+(const Matrix<T, N, M>&) const;
	Matrix<T, N, M>& operator+=(const Matrix<T, N, M>&);
	Matrix<T, N, M> operator-(const Matrix<T, N, M>&) const;
	Matrix<T, N, M>& operator-=(const Matrix<T, N, M>&);

	template<std::size_t P>
	Matrix<T, P, M> operator*(const Matrix<T, P, N>&) const;

	Matrix<T, N, M> operator-(void) const;
	Matrix<T, N> operator*(const T&) const;
	Matrix<T, N>& operator*=(const T&);
	Matrix<T, N> operator/(const T&) const;
	Matrix<T, N>& operator/=(const T&);

	bool operator==(const Matrix<T, N, M>&) const;
	bool operator!=(const Matrix<T, N, M>&) const;

	T det(void) const;
	Matrix<T, M, N> transpose(void) const;

	template<typename = typename std::enable_if<N == M, T>::type>
	Matrix<T, N, M> inverse(void) const;

	std::array<Vector<T, N>, M> data;
};

}
}

#include "matrix.inl"

#endif
