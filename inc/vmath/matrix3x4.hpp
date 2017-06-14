#ifndef VMATH_MATRIX3X4_HPP
#define VMATH_MATRIX3X4_HPP

#include <array>
#include <ostream>
#include <type_traits>
#include <vmath/matrix.hpp>
#include <vmath/vector3.hpp>

// TODO
#define VMATH_MATRIX3X4_BINARY_OPERATOR(OP)
#define VMATH_MATRIX3X4_BINARY_OPERATOR_ASSIGN(OP)
#define VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR(OP)
#define VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR_ASSIGN(OP)

namespace vmath {

/*!
 * Matrix specialization for 3x4 matrix in column-major form
 */
template<typename T>
class Matrix<T, 3, 4> {
public:
	std::array<Vector<T, 3>, 4> data;

	Matrix() : data() {}
	Matrix(const Vector<T, 3>& a, const Vector<T, 3>& b, const Vector<T, 3>& c, const Vector<T, 3>& d) : data({a, b, c, d}) {}
	explicit Matrix(const std::array<Vector<T, 3>, 4>& data) : data(data) {}

	Vector<T, 3> operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	Vector<T, 3>& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_MATRIX3X4_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_MATRIX3X4_BINARY_OPERATOR_ASSIGN(-=)

	VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
};

VMATH_MATRIX3X4_BINARY_OPERATOR(+)
VMATH_MATRIX3X4_BINARY_OPERATOR(-)

VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR(*)
VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR(/)

template<typename T>
bool operator==(const Matrix<T, 3, 4>& lhs, const Matrix<T, 3, 4>& rhs) {
	return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

template<typename T>
bool operator!=(const Matrix<T, 3, 4>& lhs, const Matrix<T, 3, 4>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T, 3, 4>& m) {
	os << "[" << m[0] << "," << m[1] << "," << m[2] << "," << m[3] << "]";
}

} // namespace vmath

#undef VMATH_MATRIX3X4_BINARY_OPERATOR
#undef VMATH_MATRIX3X4_BINARY_OPERATOR_ASSIGN
#undef VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR
#undef VMATH_MATRIX3X4_BINARY_SCALAR_OPERATOR_ASSIGN

#endif
