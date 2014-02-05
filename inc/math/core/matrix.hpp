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
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns.
 * Definition of the components available in a generic matrix. Column-major.
 */
template<typename T, std::size_t M, std::size_t N>
class matrix_components {
public:
	explicit matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, N>& data) : data(data) {}
	explicit matrix_components(const matrix_components<T, M, N>&) = default;
	explicit matrix_components(matrix_components<T, M, N>&&) = default;

	std::array<vector<T, M>, N> data;
};

/**
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * matrix component specialization for column vectors. Column-major.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 1> {
public:
	explicit matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 1>& data) : data(data) {}
	explicit matrix_components(const vector<T, M>& V) : data({{V}}) {}
	explicit matrix_components(const matrix_components<T, M, 1>&) = default;
	explicit matrix_components(matrix_components<T, M, 1>&&) = default;

	std::array<vector<T, M>, 1> data;
};

/**
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * matrix component specialization for matrices with 2 columns. Column-major.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 2> {
public:
	explicit matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 2>& data) : data(data) {}
	explicit matrix_components(const vector<T, M>& V1, const vector<T, M>& V2) : data({{V1, V2}}) {}
	explicit matrix_components(const matrix_components<T, M, 2>&) = default;
	explicit matrix_components(matrix_components<T, M, 2>&&) = default;

	std::array<vector<T, M>, 2> data;
};

/**
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * matrix component specialization for matrices with 3 columns. Column-major.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 3> {
public:
	explicit matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 3>& data) : data(data) {}
	explicit matrix_components(const vector<T, M>& V1, const vector<T, M>& V2, const vector<T, M>& V3) :
		data({{V1, V2, V3}}) {}
	explicit matrix_components(const matrix_components<T, M, 3>&) = default;
	explicit matrix_components(matrix_components<T, M, 3>&&) = default;

	std::array<vector<T, M>, 3> data;
};

/**
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * matrix component specialization for matrices with 4 columns. Column-major.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 4> {
public:
	explicit matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 4>& data) : data(data) {}
	explicit matrix_components(const vector<T, M>& V1, const vector<T, M>& V2, const vector<T, M>& V3, const vector<T, M>& V4) :
		data({{V1, V2, V3, V4}}) {}
	explicit matrix_components(const matrix_components<T, M, 4>&) = default;
	explicit matrix_components(matrix_components<T, M, 4>&&) = default;

	std::array<vector<T, M>, 4> data;
};

}

/**
 * @class matrix
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns. Defaults to number of rows.
 * A matrix with generic size and type. Column-major.
 */
template<typename T, std::size_t M, std::size_t N = M>
class matrix : public matrix_components<T, M, N> {
public:
	using matrix_components<T, M, N>::matrix_components;

	~matrix(void) = default;

	matrix<T, M, N>& operator=(const matrix<T, M, N>&);

	vector<T, M> operator[](const std::size_t) const;
	vector<T, M>& operator[](const std::size_t);

	matrix<T, M, N> operator-(void) const;
	matrix<T, M, N> operator+(const matrix<T, M, N>&) const;
	matrix<T, M, N>& operator+=(const matrix<T, M, N>&);
	matrix<T, M, N> operator-(const matrix<T, M, N>&) const;
	matrix<T, M, N>& operator-=(const matrix<T, M, N>&);

	template<std::size_t P>
	matrix<T, M, P> operator*(const matrix<T, N, P>&) const;

	matrix<T, M, N> operator*(const T&) const;
	matrix<T, M, N>& operator*=(const T&);
	matrix<T, M, N> operator/(const T&) const;
	matrix<T, M, N>& operator/=(const T&);

	matrix<T, N, M> transpose(void) const;

	bool operator==(const matrix<T, M, N>&) const;
	bool operator!=(const matrix<T, M, N>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	T minor(const std::size_t, const std::size_t) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	T det(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	matrix<T, M, N> minors(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	matrix<T, M, N> cofactor(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	matrix<T, M, N> adjugate(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && std::is_same<T, U>::value, U>::type>
	matrix<T, M, N> inverse(void) const;
};

}
}

#include "matrix.inl"

#endif
