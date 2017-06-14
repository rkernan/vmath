#ifndef VMATH_MATRIX3X3_HPP
#define VMATH_MATRIX3X3_HPP

#include <array>
#include <ostream>
#include <type_traits>
#include <vmath/matrix.hpp>
#include <vmath/vector3.hpp>

#define VMATH_MATRIX3X3_BINARY_OPERATOR(OP) \
	template<typename T> \
	Matrix<T, 3, 3> operator OP (Matrix<T, 3, 3> lhs, const Matrix<T, 3, 3>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_MATRIX3X3_BINARY_OPERATOR_ASSIGN(OP) \
	Matrix<T, 3, 3>& operator OP (const Matrix<T, 3, 3>& m) { \
		this->data[0] OP m[0]; \
		this->data[1] OP m[1]; \
		this->data[2] OP m[2]; \
		this->data[3] OP m[3]; \
	}

#define VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T> \
	Matrix<T, 3, 3> operator OP (Matrix<T, 3, 3> m, const T s) { \
		return m OP##= s; \
	}

#define VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Matrix<T, 3, 3>& operator OP (const T s) { \
		this->data[0] OP s; \
		this->data[1] OP s; \
		this->data[2] OP s; \
		this->data[3] OP s; \
	}


namespace vmath {

/*!
 * Matrix specialization for 3x3 matrix in column-major form
 */
template<typename T>
class Matrix<T, 3, 3> {
public:
	std::array<Vector<T, 3>, 3> data;

	Matrix() : data() {}
	Matrix(const Vector<T, 3>& a, const Vector<T, 3>& b, const Vector<T, 3>& c) : data({a, b, c}) {}
	explicit Matrix(const std::array<Vector<T, 3>, 3>& data) : data(data) {}

	Vector<T, 3> operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	Vector<T, 3>& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_MATRIX3X3_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_MATRIX3X3_BINARY_OPERATOR_ASSIGN(-=)

	VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
};

VMATH_MATRIX3X3_BINARY_OPERATOR(+)
VMATH_MATRIX3X3_BINARY_OPERATOR(-)

VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR(*)
VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR(/)

template<typename T>
bool operator==(const Matrix<T, 3, 3>& lhs, const Matrix<T, 3, 3>& rhs) {
	return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

template<typename T>
bool operator!=(const Matrix<T, 3, 3>& lhs, const Matrix<T, 3, 3>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T, 3, 3>& m) {
	os << "[" << m[0] << "," << m[1] << "," << m[2] << "]";
}

} // namespace vmath

#undef VMATH_MATRIX3X3_BINARY_OPERATOR
#undef VMATH_MATRIX3X3_BINARY_OPERATOR_ASSIGN
#undef VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR
#undef VMATH_MATRIX3X3_BINARY_SCALAR_OPERATOR_ASSIGN

#endif
