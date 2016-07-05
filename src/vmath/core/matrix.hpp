#ifndef VMATH_CORE_MATRIX_HPP
#define VMATH_CORE_MATRIX_HPP

#include <array>
#include <cstddef>
#include <vmath/core/vector.hpp>

#undef minor

namespace vmath {
namespace core {

/*!
 * \brief Checks that the given matrix dimensions make a square matrix
 * \tparam M Number of rows in the matrix
 * \tparam N Number of columns in the matrix
 */
template<std::size_t M, std::size_t N>
struct is_square_matrix : std::integral_constant<bool, N == M> {};

namespace {

/*!
 * \brief Column-major definition of the components available in a generic matrix
 * \tparam T Storage type
 * \tparam M Number of rows
 * \tparam N Number of columns
 */
template<typename T, std::size_t M, std::size_t N>
class MatrixComponents {
public:
	std::array<Vector<T, M>, N> data;

	/*!
	 * \brief Constructor a zero matrix
	 */
	MatrixComponents() : data() {}
	
	/*!
	 * \brief Construct a matrix from a 2-dimensional array
	 * \param[in] data Array to construct from
	 */
	explicit MatrixComponents(const std::array<Vector<T, M>, N>& data) : data(data) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other Matrix component to copy
	 */
	MatrixComponents(const MatrixComponents<T, M, N>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other Matrix component to copy
	 * \return Reference to self
	 */
	MatrixComponents<T, M, N>& operator=(const MatrixComponents& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other Matrix component to move
	 */
	MatrixComponents(MatrixComponents<T, M, N>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other Matrix component to move
	 * \return Reference to self
	 */
	MatrixComponents<T, M, N>& operator=(MatrixComponents<T, M, N>&& other) = default;
};

/*!
 * \brief Column-major matrix component specialization for column Vectors
 * \tparam T Storage type.
 * \tparam M Number of rows.
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 1> {
public:
	std::array<Vector<T, M>, 1> data;

	/*!
	 * \brief Construct a zero column matrix
	 */
	MatrixComponents() : data() {}

	/*!
	 * \brief Construct a column matrix from an array
	 * \param[in] data Array to construct from
	 */
	explicit MatrixComponents(const std::array<Vector<T, M>, 1>& data) : data(data) {}

	/*!
	 * \brief Construct a column matrix from a vector
	 * \param[in] v Vector to construct from
	 */
	explicit MatrixComponents(const Vector<T, M>& v) : data({{v}}) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other Column matrix component to copy
	 */
	MatrixComponents(const MatrixComponents<T, M, 1>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other Column matrix component to copy
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 1>& operator=(const MatrixComponents<T, M, 1>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other Column matrix component to move
	 */
	MatrixComponents(MatrixComponents<T, M, 1>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other Column matrix component to move
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 1>& operator=(MatrixComponents<T, M, 1>&& other) = default;
};

/*!
 * \brief Column-major matrix component specialization for matrices with 2 columns
 * \tparam T Storage type
 * \tparam M Number of rows
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 2> {
public:
	std::array<Vector<T, M>, 2> data;

	/*!
	 * \brief Construct a zero 2 column matrix
	 */
	MatrixComponents() : data() {}

	/*!
	 * \brief Construct a 2 column matrix from a 2-dimensional array
	 * \param[in] data Array to construct from
	 */
	explicit MatrixComponents(const std::array<Vector<T, M>, 2>& data) : data(data) {}

	/*!
	 * \brief Construct a 2 column matrix from 2 Vectors
	 * \param[in] v1 First column as Vector
	 * \param[in] v2 Second column as Vector
	 */
	MatrixComponents(const Vector<T, M>& v1, const Vector<T, M>& v2) : data({{v1, v2}}) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 2 column matrix component to copy
	 */
	MatrixComponents(const MatrixComponents<T, M, 2>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 2 column matrix component to copy
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 2>& operator=(const MatrixComponents<T, M, 2>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 2 column matrix component to move
	 */
	MatrixComponents(MatrixComponents<T, M, 2>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 2 column matrix component to move
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 2>& operator=(MatrixComponents<T, M, 2>&& other) = default;
};

/*!
 * \brief Column-major matrix component specialization for matrices with 3 columns
 * \tparam T Storage type
 * \tparam M Number of rows
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 3> {
public:
	std::array<Vector<T, M>, 3> data;

	/*!
	 * \brief Construct a zero 3 column matrix
	 */
	MatrixComponents() : data() {}

	/*!
	 * \brief Construct a 3 column matrix from a 2-dimensional array
	 * \param[in] data Array to construct from
	 */
	explicit MatrixComponents(const std::array<Vector<T, M>, 3>& data) : data(data) {}

	/*!
	 * \brief Construct a 3-column matrix from Vector
	 * \param[in] v1 First column as Vector
	 * \param[in] v2 Second column as Vector
	 * \param[in] v3 Third column as Vector
	 */
	MatrixComponents(const Vector<T, M>& v1, const Vector<T, M>& v2, const Vector<T, M>& v3) : data({{v1, v2, v3}}) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 3 column matrix component to copy
	 */
	MatrixComponents(const MatrixComponents<T, M, 3>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 3 column matrix component to copy
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 3>& operator=(const MatrixComponents<T, M, 3>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 3 column matrix component to move
	 */
	MatrixComponents(MatrixComponents<T, M, 3>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 3 column matrix component to move
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 3>& operator=(MatrixComponents<T, M, 3>&& other) = default;
};

/*!
 * \brief Column-major matrix component specialization for matrices with 4 columns
 * \tparam T Storage type
 * \tparam M Number of rows
 */
template<typename T, std::size_t M>
class MatrixComponents<T, M, 4> {
public:
	std::array<Vector<T, M>, 4> data;

	/*!
	 * \brief Construct a zero 4 column matrix
	 */
	MatrixComponents() : data() {}

	/*!
	 * \brief Construct a 4 column matrix from a 2-dimensional array
	 * \param[in] data Array to construct from
	 */
	explicit MatrixComponents(const std::array<Vector<T, M>, 4>& data) : data(data) {}

	/*!
	 * \brief Construct a 4 column matrix from Vectors
	 * \param[in] v1 First column as Vector
	 * \param[in] v2 Second column as Vector
	 * \param[in] v3 Third column as Vector
	 * \param[in] v4 Fourth column as Vector
	 */
	MatrixComponents(const Vector<T, M>& v1, const Vector<T, M>& v2, const Vector<T, M>& v3, const Vector<T, M>& v4) : data({{v1, v2, v3, v4}}) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 4 column matrix component to copy
	 */
	MatrixComponents(const MatrixComponents<T, M, 4>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 4 column matrix component to copy
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 4>& operator=(const MatrixComponents<T, M, 4>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 4 column matrix component to move
	 */
	MatrixComponents(MatrixComponents<T, M, 4>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 4 column matrix component to move
	 * \return Reference to self
	 */
	MatrixComponents<T, M, 4>& operator=(MatrixComponents<T, M, 4>&& other) = default;
};

}

/*!
 * \brief A column-major Matrix with generic size and type
 * \tparam T Storage type.
 * \tparam M Number of rows.
 * \tparam N Number of columns. Defaults to number of rows.
 */
template<typename T, std::size_t M, std::size_t N = M>
class Matrix : public MatrixComponents<T, M, N> {
public:
	using MatrixComponents<T, M, N>::MatrixComponents;

	/*!
	 * \brief Destructor
	 */
	~Matrix() = default;

	/*!
	 * \brief Access a matrix element using an index
	 * \param[in] idx Location of element to access
	 * \return Accessed element
	 */
	Vector<T, M> operator[](const std::size_t idx) const;

	/*!
	 * \brief Access and modify a matrix element by index
	 * \param[in] idx Location of element to access
	 * \return Modified element
	 */
	Vector<T, M>& operator[](const std::size_t idx);

	/*!
	 * \brief Matrix negation operator
	 * \return Negated matrix
	 */
	Matrix<T, M, N> operator-() const;

	/*!
	 * \brief Matrix addition assignment operator
	 * \param[in] w Matrix to add
	 * \return Reference to self
	 */
	Matrix<T, M, N>& operator+=(const Matrix<T, M, N>& w);

	/*!
	 * \brief Matrix addition operator
	 * \param[in] lhs Matrix to add to
	 * \param[in] rhs Matrix to add
	 * \return Matrix sum
	 */
	friend Matrix<T, M, N> operator+(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
		lhs += rhs;
		return lhs;
	}

	/*!
	 * \brief Matrix subtraction assignment operator
	 * \param[in] w Matrix to subtract
	 * \return Reference to self
	 */
	Matrix<T, M, N>& operator-=(const Matrix<T, M, N>& w);

	/*!
	 * \brief Matrix subtraction operator
	 * \param[in] lhs Matrix to subtract from
	 * \param[in] rhs Matrix to subtract
	 * \return Matrix difference
	 */
	friend Matrix<T, M, N> operator-(Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
		lhs -= rhs;
		return lhs;
	}

	/*!
	 * \brief Matrix multiplication operator
	 * \tparam P The number of columns in the result
	 * \param[in] w Matrix to multiply by
	 * \return Matrix product
	 */
	template<std::size_t P>
	Matrix<T, M, P> operator*(const Matrix<T, N, P>& w) const;

	/*!
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self
	 */
	Matrix<T, M, N>& operator*=(const T s);

	/*!
	 * \brief Scalar multiplication operator
	 * \param[in] w Matrix to multiply
	 * \param[in] s Scalar to multiply by
	 * \return Matrix-scalar product
	 */
	friend Matrix<T, M, N> operator*(Matrix<T, M, N> w, const T s) {
		w *= s;
		return w;
	}

	/*!
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self
	 */
	Matrix<T, M, N>& operator/=(const T s);

	/*!
	 * \brief Scalar division operator
	 * \param[in] w Matrix to divide
	 * \param[in] s Scalar to divide by
	 * \return Matrix-scalar quotient
	 */
	friend Matrix<T, M, N> operator/(Matrix<T, M, N> w, const T s) {
		w /= s;
		return w;
	}

	/*!
	 * \brief Calculate the transpose matrix
	 * \return Matrix transpose
	 */
	Matrix<T, N, M> transpose() const;

	/*!
	 * \brief Check matrix equality
	 * \param[in] other Matrix to check equality with
	 * \return True if they are equal, otherwise false
	 */
	bool equals(const Matrix<T, M, N>& other) const;

	/*!
	 * \brief Check matrix equality
	 * \param[in] other Matrix to check equality with
	 * \param[in] ulp The desired floating point precision in ULPs
	 * \return True if equal, else false
	 */
	template<typename U = T, typename = typename std::enable_if<std::is_floating_point<U>::value>::type>
	bool equals(const Matrix<T, M, N>& other, const int ulp) const;

	/*!
	 * \brief Check matrix equality operator
	 * \param[in] lhs Matrix to check equality with
	 * \param[in] rhs Matrix to check equality with
	 * \return True if they are equal, otherwise false
	 */
	friend bool operator==(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
		return lhs.equals(rhs);
	}

	/*!
	 * \brief Check Matrix inequality operator
	 * \param[in] lhs Matrix to check inequality with
	 * \param[in] rhs Matrix to check inequality with
	 * \return False if they are equal, otherwise true
	 */
	friend bool operator!=(const Matrix<T, M, N>& lhs, const Matrix<T, M, N>& rhs) {
		return !lhs.equals(rhs);
	}

	/*!
	 * \brief Calculate the minor matrix
	 * \param[in] row Row of element to calculate minor for
	 * \param[in] col Column of element to calculate minor for
	 * \return Matrix minor of the element at the given position
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	T minor(const std::size_t row, const std::size_t col) const;

	/*!
	 * \brief Calculate the determinant matrix
	 * \return Matrix determinant.
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	T det() const;

	/*!
	 * \brief Calculate the matrix of minors.
	 * \return Matrix of minors.
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	Matrix<T, M, N> minors() const;

	/*!
	 * \brief Calculate the cofactor matrix
	 * \return Cofactor matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	Matrix<T, M, N> cofactor() const;

	/*!
	 * \brief Calculate the matrix adjugate
	 * \return Matrix adjugate
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	Matrix<T, M, N> adjugate() const;

	/*!
	 * \brief Calculate the matrix inverse
	 * \return Matrix inverse
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value, U>::type>
	Matrix<T, M, N> inverse() const;

	/*!
	 * \brief Create an affine translation matrix
	 * \param[in] disp Vector displacement
	 * \return Translation matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static Matrix<T, M, N> translation(const Vector<T, 3>& disp);

	/*!
	 * \brief Create an affine rotation matrix
	 * \param[in] out Outwards direction
	 * \param[in] up Upwards direction
	 * \return Rotation matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static Matrix<T, M, N> rotation(const Vector<T, 3>& out, const Vector<T, 3>& up);

	/*!
	 * \brief Create an affine scale scale matrix
	 * \param[in] x_scale Scale in the x-direction
	 * \param[in] y_scale Scale in the y-direction
	 * \param[in] z_scale Scale in the z-direction
	 * \return Scale matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static Matrix<T, M, N> scale(const T x_scale, const T y_scale, const T z_scale);

	/*!
	 * \brief Create an otrhographic projection matrix
	 * \param[in] left
	 * \param[in] right
	 * \param[in] bottom
	 * \param[in] top
	 * \param[in] near The near clipping plane
	 * \param[in] far The far clipping plane
	 * \return Projection matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static Matrix<T, M, N> orthographic(const T left, const T right, const T bottom, const T top, const T near, const T far);

	/*!
	 * \brief Create a perspective projection matrix
	 * \param[in] fov The field of view
	 * \param[in] aspect The screen's aspect ratio
	 * \param[in] near The near clipping plane
	 * \param[in] far The far clipping plane
	 * \return Projection matrix
	 */
	template<typename U = T, typename = typename std::enable_if<is_square_matrix<M, N>::value && M == 4, U>::type>
	static Matrix<T, M, N> perspective(const T fov, const T aspect, const T near, const T far);
};

}
}

#include <vmath/core/matrix.inl>

#endif
