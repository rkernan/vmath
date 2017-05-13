#ifndef VMATH_VECTOR2_HPP
#define VMATH_VECTOR2_HPP

#include <array>
#include <cmath>
#include <ostream>
#include <type_traits>
#include <vmath/functions.hpp>
#include <vmath/swizzle.hpp>
#include <vmath/vector.hpp>

#define VMATH_VECTOR2_BINARY_SCALAR_OPERATOR(OP) \
	friend Vector<T, 2> operator OP (Vector<T, 2> v, const T s) { \
		return v OP##= s; \
	}

#define VMATH_VECTOR2_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Vector<T, 2>& operator OP (const T s) { \
		this->x OP s; \
		this->y OP s; \
		return *this; \
	}

#define VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR(OP) \
	friend Vector<T, 2> operator OP (Vector<T, 2> lhs, const Vector<T, 2>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(OP) \
	Vector<T, 2>& operator OP (const Vector<T, 2>& v) { \
		this->x OP v.x; \
		this->y OP v.y; \
		return *this; \
	}

namespace vmath {

/*!
 * Vector specialization for 2-dimensional vectors
 */
template<typename T>
class Vector<T, 2> {
public:
	union {
		std::array<T, 2> data;
		// axis coords
		struct { T x, y; };
		VMATH_SWIZZLE2_FOR_VECTOR2(T, x, y)
		VMATH_SWIZZLE3_FOR_VECTOR2(T, x, y)
		VMATH_SWIZZLE4_FOR_VECTOR2(T, x, y)
		// texture coords
		struct { T s, t; };
		VMATH_SWIZZLE2_FOR_VECTOR2(T, s, t)
		VMATH_SWIZZLE3_FOR_VECTOR2(T, s, t)
		VMATH_SWIZZLE4_FOR_VECTOR2(T, s, t)
		// color values
		struct { T r, g; };
		VMATH_SWIZZLE2_FOR_VECTOR2(T, r, g)
		VMATH_SWIZZLE3_FOR_VECTOR2(T, r, g)
		VMATH_SWIZZLE4_FOR_VECTOR2(T, r, g)
	};

	Vector() : x(), y() {}
	Vector(const T x, const T y) : x(x), y(y) {}

	T operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	T& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_VECTOR2_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR2_BINARY_SCALAR_OPERATOR_ASSIGN(/=)

	VMATH_VECTOR2_BINARY_SCALAR_OPERATOR(*)
	VMATH_VECTOR2_BINARY_SCALAR_OPERATOR(/)

	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(+=)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(-=)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(/=)

	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR(+)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR(-)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR(*)
	VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR(/)

	Vector<T, 2> operator-() const {
		return *this * static_cast<T>(-1.0);
	}

	T mag() const {
		return std::sqrt(this->mag2());
	}

	T mag2() const {
		return (this->x * this->x) + (this->y * this->y);
	}

	Vector<T, 2> normal() const {
		return *this / this->mag();
	}

	Vector<T, 2>& normalize() {
		return *this = this->normal();
	}

	template<typename U = T>
	friend typename std::enable_if<std::is_floating_point<U>::value, bool>::type operator==(const Vector<T, 2>& lhs, const Vector<T, 2>& rhs) {
		return vmath::equals(lhs.x, rhs.x) && vmath::equals(lhs.y, rhs.y);
	}

	template<typename U = T>
	friend typename std::enable_if<!std::is_floating_point<U>::value, bool>::type operator==(const Vector<T, 2>& lhs, const Vector<T, 2>& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	friend bool operator!=(const Vector<T, 2>& lhs, const Vector<T, 2>& rhs) {
		return !(lhs == rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector<T, 2>& v) {
	    return os << "<" << v.x << "," << v.y << ">";
	}
};

template<typename T>
T dot(const Vector<T, 2>& v1, const Vector<T, 2>& v2) {
	return (v1.x * v2.x) + (v1.y * v2.y);
}

template<typename T>
T cross(const Vector<T, 2>& v1, const Vector<T, 2>& v2) {
	return (v1.x * v2.y) - (v1.y * v2.x);
}

} // namespace vmath

#undef VMATH_VECTOR2_BINARY_SCALAR_OPERATOR
#undef VMATH_VECTOR2_BINARY_SCALAR_OPERATOR_ASSIGN
#undef VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR
#undef VMATH_VECTOR2_BINARY_COMPONENTWISE_OPERATOR_ASSIGN

#endif
