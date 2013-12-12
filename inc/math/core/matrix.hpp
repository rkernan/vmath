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
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam N Number of columns.
 * @tparam M Number of rows.
 * Definition of the components available in a generic matrix.
 */
template<typename T, std::size_t N, std::size_t M>
class MatrixComponents {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, N>& data) : data(data) {}
	explicit MatrixComponents(const MatrixComponents<T, N, M>&) = default;
	explicit MatrixComponents(MatrixComponents<T, N, M>&&) = default;

	std::array<Vector<T, M>, N> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for column vectors.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, 1, M> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 1>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V) : data({{V}}) {}
	explicit MatrixComponents(const MatrixComponents<T, 1, M>&) = default;
	explicit MatrixComponents(MatrixComponents<T, 1, M>&&) = default;

	std::array<Vector<T, M>, 2> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 2 columns.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, 2, M> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 2>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2) : data({{V1, V2}}) {}
	explicit MatrixComponents(const MatrixComponents<T, 2, M>&) = default;
	explicit MatrixComponents(MatrixComponents<T, 2, M>&&) = default;

	std::array<Vector<T, M>, 2> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 3 columns.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, 3, M> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 3>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2, const Vector<T, M>& V3) :
		data({{V1, V2, V3}}) {}
	explicit MatrixComponents(const MatrixComponents<T, 3, M>&) = default;
	explicit MatrixComponents(MatrixComponents<T, 3, M>&&) = default;

	std::array<Vector<T, M>, 3> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 4 columns.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, 4, M> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 4>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2, const Vector<T, M>& V3, const Vector<T, M>& V4) :
		data({{V1, V2, V3, V4}}) {}
	explicit MatrixComponents(const MatrixComponents<T, 4, M>&) = default;
	explicit MatrixComponents(MatrixComponents<T, 4, M>&&) = default;

	std::array<Vector<T, M>, 4> data;
};

/**
 * @class Matrix
 * @tparam T Storage type.
 * @tparam N Number of columns.
 * @tparam M Number of rows. Defaults to the number of columns.
 */
template<typename T, std::size_t N, std::size_t M = N>
class Matrix : public MatrixComponents<T, N, M> {
public:
	using MatrixComponents<T, N, M>::MatrixComponents;

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
};

}
}

#include "matrix.inl"

#endif
