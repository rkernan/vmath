#ifndef VMATH_MATRIX2X2_HPP
#define VMATH_MATRIX2X2_HPP

#include <array>
#include <ostream>
#include <type_traits>
#include <vmath/matrix.hpp>
#include <vmath/vector2.hpp>

#define VMATH_MATRIX2X2_BINARY_OPERATOR(OP) \
	template<typename T> \
	Matrix<T, 2, 2> operator OP (Matrix<T, 2, 2> lhs, const Matrix<T, 2, 2>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_MATRIX2X2_BINARY_OPERATOR_ASSIGN(OP) \
	Matrix<T, 2, 2>& operator OP (const Matrix<T, 2, 2>& m) { \
		this->data[0] OP m[0]; \
		this->data[1] OP m[1]; \
		return *this; \
	}

#define VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T> \
	Matrix<T, 2, 2> operator OP (Matrix<T, 2, 2>& m, const T s) { \
		return m OP##= s; \
	}

#define VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Matrix<T, 2, 2>& operator OP (const T s) { \
		this->data[0] OP s; \
		this->data[1] OP s; \
		return *this; \
	}

namespace vmath {

/*!
 * Matrix specialization for 2x2 matrix in column-major form
 */
template<typename T>
class Matrix<T, 2, 2> {
public:
	std::array<Vector<T, 2>, 2> data;

	Matrix() : data() {}
	Matrix(const Vector<T, 2>& a, const Vector<T, 2>& b) : data({a, b}) {}
	explicit Matrix(const std::array<Vector<T, 2>, 2>& data) : data(data) {}

	Vector<T, 2> operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	Vector<T, 2>& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_MATRIX2X2_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_MATRIX2X2_BINARY_OPERATOR_ASSIGN(-=)

	VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
};

VMATH_MATRIX2X2_BINARY_OPERATOR(+)
VMATH_MATRIX2X2_BINARY_OPERATOR(-)

VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR(*)
VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR(/)

template<typename T>
bool operator==(const Matrix<T, 2, 2>& lhs, const Matrix<T, 2, 2>& rhs) {
	return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}

template<typename T>
bool operator!=(const Matrix<T, 2, 2>& lhs, const Matrix<T, 2, 2>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T, 2, 2>& m) {
	os << "[" << m[0] << "," << m[1] << "]";
}

} // namespace vmath

#undef VMATH_MATRIX2X2_BINARY_OPERATOR
#undef VMATH_MATRIX2X2_BINARY_OPERATOR_ASSIGN
#undef VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR
#undef VMATH_MATRIX2X2_BINARY_SCALAR_OPERATOR_ASSIGN

#endif
