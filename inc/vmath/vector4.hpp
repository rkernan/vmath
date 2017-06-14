#ifndef VMATH_VECTOR4_HPP
#define VMATH_VECTOR4_HPP

#include <array>
#include <cmath>
#include <ostream>
#include <type_traits>
#include <vmath/swizzle.hpp>
#include <vmath/vector.hpp>
#include <vmath/vector2.hpp>
#include <vmath/vector3.hpp>

#define VMATH_VECTOR4_BINARY_OPERATOR(OP) \
	template<typename T> \
	Vector<T, 4> operator OP (Vector<T, 4> lhs, const Vector<T, 4>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(OP) \
	Vector<T, 4>& operator OP (const Vector<T, 4>& v) { \
		this->x OP v.x; \
		this->y OP v.y; \
		this->z OP v.z; \
		this->w OP v.w; \
		return *this; \
	}

#define VMATH_VECTOR4_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T> \
	Vector<T, 4> operator OP (Vector<T, 4> v, const T& s) { \
		return v OP##= s; \
	}

#define VMATH_VECTOR4_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Vector<T, 4>& operator OP (const T& s) { \
		this->x OP s; \
		this->y OP s; \
		this->z OP s; \
		this->w OP s; \
		return *this; \
	}

namespace vmath {

/*!
 * Vector specialization for 4-dimensional vectors
 */
template<typename T>
class Vector<T, 4> {
public:
	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
		VMATH_SWIZZLE2_FOR_VECTOR4(T, x, y, z, w)
		VMATH_SWIZZLE3_FOR_VECTOR4(T, x, y, z, w)
		VMATH_SWIZZLE4_FOR_VECTOR4(T, x, y, z, w)
		// texture coords
		struct { T s, t, p, q; };
		VMATH_SWIZZLE2_FOR_VECTOR4(T, s, t, p, q)
		VMATH_SWIZZLE3_FOR_VECTOR4(T, s, t, p, q)
		VMATH_SWIZZLE4_FOR_VECTOR4(T, s, t, p, q)
		// color values
		struct { T r, g, b, a; };
		VMATH_SWIZZLE2_FOR_VECTOR4(T, r, g, b, a)
		VMATH_SWIZZLE3_FOR_VECTOR4(T, r, g, b, a)
		VMATH_SWIZZLE4_FOR_VECTOR4(T, r, g, b, a)
	};

	Vector() : x(), y(), z(), w() {}
	Vector(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	Vector(const Vector<T, 2>& v, const T& z, const T& w) : x(v.x), y(v.y), z(z), w(w) {}
	Vector(const Vector<T, 3>& v, const T& w) : x(v.x), y(v.y), z(v.z), w(w) {}
	explicit Vector(const std::array<T, 4> data) : data(data) {}

	T operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	T& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(-=)
	VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(/=)
	VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN(%=)

	VMATH_VECTOR4_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR4_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
	VMATH_VECTOR4_BINARY_SCALAR_OPERATOR_ASSIGN(%=)

	Vector<T, 4> operator-() const {
		return *this * static_cast<T>(-1.0);
	}

	T mag() const {
		return std::sqrt(this->mag2());
	}

	T mag2() const {
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
	}

	Vector<T, 4> normal() const {
		return *this / this->mag();
	}

	Vector<T, 4>& normalize() {
		return *this = this->normal();
	}
};

VMATH_VECTOR4_BINARY_OPERATOR(+)
VMATH_VECTOR4_BINARY_OPERATOR(-)
VMATH_VECTOR4_BINARY_OPERATOR(*)
VMATH_VECTOR4_BINARY_OPERATOR(/)

VMATH_VECTOR4_BINARY_SCALAR_OPERATOR(*)
VMATH_VECTOR4_BINARY_SCALAR_OPERATOR(/)

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type operator==(const Vector<T, 4>& lhs, const Vector<T, 4>& rhs) {
	return vmath::equals(lhs.x, rhs.x) && vmath::equals(lhs.y, rhs.y) && vmath::equals(lhs.z, rhs.z) && vmath::equals(lhs.w, rhs.w);
}

template<typename T>
typename std::enable_if<!std::is_floating_point<T>::value, bool>::type operator==(const Vector<T, 4>& lhs, const Vector<T, 4>& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

template<typename T>
bool operator!=(const Vector<T, 4>& lhs, const Vector<T, 4>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T, 4>& v) {
	return os << "<" << v.x << "," << v.y << "," << v.z << "," << v.w << ">";
}

template<typename T>
T dot(const Vector<T, 4>& v1, const Vector<T, 4>& v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

} // namespace vmath

#undef VMATH_VECTOR4_BINARY_OPERATOR
#undef VMATH_VECTOR4_BINARY_OPERATOR_ASSIGN
#undef VMATH_VECTOR4_BINARY_SCALAR_OPERATOR
#undef VMATH_VECTOR4_BINARY_SCALAR_OPERATOR_ASSIGN

#endif
