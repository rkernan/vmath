#ifndef MATH_CORE_MATRIX_HPP
#define MATH_CORE_MATRIX_HPP

#include <array>
#include <cstddef>

#include "vector.hpp"

#ifdef minor
#undef minor
#endif

namespace math {
namespace core {
namespace {

/**
 * @struct is_square_matrix
 * @param M Number of rows in the matrix.
 * @param N Number of columns in the matrix.
 * Checks that the given matrix dimensions make a square matrix.
 */
template<std::size_t M, std::size_t N>
struct is_square_matrix : std::integral_constant<bool, N == M> {};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns.
 * Definition of the components available in a generic matrix. Column-major.
 */
template<typename T, std::size_t M, std::size_t N>
class MatrixComponents {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, N>& data) : data(data) {}
	explicit MatrixComponents(const MatrixComponents<T, M, N>&) = default;
	explicit MatrixComponents(MatrixComponents<T, M, N>&&) = default;

	std::array<Vector<T, M>, N> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for column vectors. Column-major.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 1> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 1>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V) : data({{V}}) {}
	explicit MatrixComponents(const MatrixComponents<T, M, 1>&) = default;
	explicit MatrixComponents(MatrixComponents<T, M, 1>&&) = default;

	std::array<Vector<T, M>, 1> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 2 columns. Column-major.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 2> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 2>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2) : data({{V1, V2}}) {}
	explicit MatrixComponents(const MatrixComponents<T, M, 2>&) = default;
	explicit MatrixComponents(MatrixComponents<T, M, 2>&&) = default;

	std::array<Vector<T, M>, 2> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 3 columns. Column-major.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 3> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 3>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2, const Vector<T, M>& V3) :
		data({{V1, V2, V3}}) {}
	explicit MatrixComponents(const MatrixComponents<T, M, 3>&) = default;
	explicit MatrixComponents(MatrixComponents<T, M, 3>&&) = default;

	std::array<Vector<T, M>, 3> data;
};

/**
 * @class MatrixComponents
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * Matrix component specialization for matrices with 4 columns. Column-major.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 4> {
public:
	explicit MatrixComponents(void) : data() {}
	explicit MatrixComponents(const std::array<Vector<T, M>, 4>& data) : data(data) {}
	explicit MatrixComponents(const Vector<T, M>& V1, const Vector<T, M>& V2, const Vector<T, M>& V3, const Vector<T, M>& V4) :
		data({{V1, V2, V3, V4}}) {}
	explicit MatrixComponents(const MatrixComponents<T, M, 4>&) = default;
	explicit MatrixComponents(MatrixComponents<T, M, 4>&&) = default;

	std::array<Vector<T, M>, 4> data;
};

}

/**
 * @class Matrix
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns. Defaults to number of rows.
 * A matrix with generic size and type. Column-major.
 */
template<typename T, std::size_t M, std::size_t N = M>
class Matrix : public MatrixComponents<T, M, N> {
public:
	using MatrixComponents<T, M, N>::MatrixComponents;

	~Matrix(void) = default;

	Matrix<T, M, N>& operator=(const Matrix<T, M, N>&);

	Vector<T, M> operator[](const std::size_t) const;
	Vector<T, M>& operator[](const std::size_t);

	Matrix<T, M, N> operator-(void) const;
	Matrix<T, M, N> operator+(const Matrix<T, M, N>&) const;
	Matrix<T, M, N>& operator+=(const Matrix<T, M, N>&);
	Matrix<T, M, N> operator-(const Matrix<T, M, N>&) const;
	Matrix<T, M, N>& operator-=(const Matrix<T, M, N>&);

	template<std::size_t P>
	Matrix<T, M, P> operator*(const Matrix<T, N, P>&) const;

	Matrix<T, M, N> operator*(const T&) const;
	Matrix<T, M, N>& operator*=(const T&);
	Matrix<T, M, N> operator/(const T&) const;
	Matrix<T, M, N>& operator/=(const T&);

	Matrix<T, N, M> transpose(void) const;

	bool operator==(const Matrix<T, M, N>&) const;
	bool operator!=(const Matrix<T, M, N>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	T minor(const std::size_t, const std::size_t) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	T det(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	Matrix<T, M, N> minors(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	Matrix<T, M, N> cofactor(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	Matrix<T, M, N> adjugate(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	Matrix<T, M, N> inverse(void) const;
};

}
}

#include "matrix.inl"

#endif
