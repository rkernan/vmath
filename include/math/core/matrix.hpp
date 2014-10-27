#ifndef MATH_CORE_MATRIX_HPP
#define MATH_CORE_MATRIX_HPP

#include <array>
#include <cstddef>
#include <math/core/vector.hpp>

#ifdef minor
#undef minor
#endif

namespace math {
namespace core {

/**
 * Checks that the given matrix dimensions make a square matrix.
 * @struct is_square_matrix
 * @param M Number of rows in the matrix.
 * @param N Number of columns in the matrix.
 */
template<std::size_t M, std::size_t N>
struct is_square_matrix : std::integral_constant<bool, N == M> {};

namespace {

/**
 * Definition of the components available in a generic matrix. Column-major.
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns.
 */
template<typename T, std::size_t M, std::size_t N>
class matrix_components {
public:
	matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, N>& data) : data(data) {}
	matrix_components(const matrix_components<T, M, N>&) = default;
	matrix_components& operator=(const matrix_components&) = default;
	matrix_components(matrix_components<T, M, N>&&) = default;

	std::array<vector<T, M>, N> data;
};

/**
 * Matrix component specialization for column vectors. Column-major.
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 1> {
public:
	matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 1>& data) : data(data) {}
	explicit matrix_components(const vector<T, M>& V) : data({{V}}) {}
	matrix_components(const matrix_components<T, M, 1>&) = default;
	matrix_components<T, M, 1>& operator=(const matrix_components<T, M, 1>&) = default;
	matrix_components(matrix_components<T, M, 1>&&) = default;

	std::array<vector<T, M>, 1> data;
};

/**
 * Matrix component specialization for matrices with 2 columns. Column-major.
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 2> {
public:
	matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 2>& data) : data(data) {}
	matrix_components(const vector<T, M>& V1, const vector<T, M>& V2) : data({{V1, V2}}) {}
	matrix_components(const matrix_components<T, M, 2>&) = default;
	matrix_components<T, M, 2>& operator=(const matrix_components<T, M, 2>&) = default;
	matrix_components(matrix_components<T, M, 2>&&) = default;

	std::array<vector<T, M>, 2> data;
};

/**
 * Matrix component specialization for matrices with 3 columns. Column-major.
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 3> {
public:
	matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 3>& data) : data(data) {}
	matrix_components(
			const vector<T, M>& V1,
			const vector<T, M>& V2,
			const vector<T, M>& V3) :
		data({{V1, V2, V3}}) {}
	matrix_components(const matrix_components<T, M, 3>&) = default;
	matrix_components<T, M, 3>& operator=(const matrix_components<T, M, 3>&) = default;
	matrix_components(matrix_components<T, M, 3>&&) = default;

	std::array<vector<T, M>, 3> data;
};

/**
 * Matrix component specialization for matrices with 4 columns. Column-major.
 * @class matrix_components
 * @tparam T Storage type.
 * @tparam M Number of rows.
 */
template<typename T, std::size_t M>
class matrix_components<T, M, 4> {
public:
	matrix_components(void) : data() {}
	explicit matrix_components(const std::array<vector<T, M>, 4>& data) : data(data) {}
	matrix_components(
			const vector<T, M>& V1,
			const vector<T, M>& V2,
			const vector<T, M>& V3,
			const vector<T, M>& V4) :
		data({{V1, V2, V3, V4}}) {}
	matrix_components(const matrix_components<T, M, 4>&) = default;
	matrix_components<T, M, 4>& operator=(const matrix_components<T, M, 4>&) = default;
	matrix_components(matrix_components<T, M, 4>&&) = default;

	std::array<vector<T, M>, 4> data;
};

}

/**
 * A matrix with generic size and type. Column-major.
 * @class matrix
 * @tparam T Storage type.
 * @tparam M Number of rows.
 * @tparam N Number of columns. Defaults to number of rows.
 */
template<typename T, std::size_t M, std::size_t N = M>
class matrix : public matrix_components<T, M, N> {
public:
#if defined(_WIN32)
	matrix(void) : matrix_components<T, M, N>() {}
	explicit matrix(const std::array<vector<T, M>, N>& data) : matrix_components<T, M, N>(data) {}
	explicit matrix(const vector<T, M>& V) : matrix_components<T, M, N>(V) {}
	explicit matrix(const vector<T, M>& V1, const vector<T, M>& V2)
		: matrix_components<T, M, N>(V1, V2) {}
	explicit matrix(
			const vector<T, M>& V1,
			const vector<T, M>& V2,
			const vector<T, M>& V3)
		: matrix_components<T, M, N>(V1, V2, V3) {}
	explicit matrix(
			const vector<T, M>& V1,
			const vector<T, M>& V2,
			const vector<T, M>& V3,
			const vector<T, M>& V4)
		: matrix_components<T, M, N>(V1, V2, V3, V4) {}
	matrix(const matrix<T, M, N>& orig) : matrix_components<T, M, N>(orig) {}
	matrix(matrix<T, M, N>&& orig) : matrix_components<T, M, N>(orig) {}
#else
	using matrix_components<T, M, N>::matrix_components;
#endif

	~matrix(void) = default;

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
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	T minor(const std::size_t, const std::size_t) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	T det(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	matrix<T, M, N> minors(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	matrix<T, M, N> cofactor(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	matrix<T, M, N> adjugate(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	matrix<T, M, N> inverse(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static matrix<T, M, N> translation(const vector<T, 3>&);

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static matrix<T, M, N> rotation(const vector<T, 3>&, const vector<T, 3>&);

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static matrix<T, M, N> scale(const T&, const T&, const T&);

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static matrix<T, M, N> orthographic(const T&, const T&, const T&, const T&, const T&, const T&);

	template<typename U = T,
		typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static matrix<T, M, N> perspective(const T&, const T&, const T&, const T&);
};

}
}

#include <math/core/matrix.inl>

#endif
