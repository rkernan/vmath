#ifndef VMATH_VECTOR3_HPP
#define VMATH_VECTOR3_HPP

#include <array>
#include <cmath>
#include <ostream>
#include <type_traits>
#include <vmath/swizzle.hpp>
#include <vmath/vector.hpp>
#include <vmath/vector2.hpp>

#define VMATH_VECTOR3_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T> \
	Vector<T, 3> operator OP (Vector<T, 3> v, const T& s) { \
		return v OP##= s; \
	} \

#define VMATH_VECTOR3_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Vector<T, 3>& operator OP (const T& s) { \
		this->x OP s; \
		this->y OP s; \
		this->z OP s; \
		return *this; \
	}

#define VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR(OP) \
	template<typename T> \
	Vector<T, 3> operator OP (Vector<T, 3> lhs, const Vector<T, 3>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(OP) \
	Vector<T, 3>& operator OP (const Vector<T, 3>& v) { \
		this->x OP v.x; \
		this->y OP v.y; \
		this->z OP v.z; \
		return *this; \
	}

namespace vmath {

/*!
 * Vector specialization for 3-dimensional vectors
 */
template<typename T>
class Vector<T, 3> {
public:
	union {
		std::array<T, 3> data;
		// axis coords
		struct { T x, y, z; };
		VMATH_SWIZZLE2_FOR_VECTOR3(T, x, y, z)
		VMATH_SWIZZLE3_FOR_VECTOR3(T, x, y, z)
		VMATH_SWIZZLE4_FOR_VECTOR3(T, x, y, z)
		// texture coords
		struct { T s, t, p; };
		VMATH_SWIZZLE2_FOR_VECTOR3(T, s, t, p)
		VMATH_SWIZZLE3_FOR_VECTOR3(T, s, t, p)
		VMATH_SWIZZLE4_FOR_VECTOR3(T, s, t, p)
		// color values
		struct { T r, g, b; };
		VMATH_SWIZZLE2_FOR_VECTOR3(T, r, g, b)
		VMATH_SWIZZLE3_FOR_VECTOR3(T, r, g, b)
		VMATH_SWIZZLE4_FOR_VECTOR3(T, r, g, b)
	};

	Vector() : x(), y(), z() {}
	Vector(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
	Vector(const Vector<T, 2>& v, const T& z) : x(v.x), y(v.y), z(z) {}

	T operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	T& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_VECTOR3_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR3_BINARY_SCALAR_OPERATOR_ASSIGN(/=)

	VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(+=)
	VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(-=)
	VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(*=)
	VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN(/=)

	Vector<T, 3> operator-() const {
		return *this * static_cast<T>(-1.0);
	}

	T mag() const {
		return std::sqrt(this->mag2());
	}

	T mag2() const {
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
	}

	Vector<T, 3> normal() const {
		return *this / this->mag();
	}

	Vector<T, 3>& normalize() {
		return *this = this->normal();
	}
};

VMATH_VECTOR3_BINARY_SCALAR_OPERATOR(*)
VMATH_VECTOR3_BINARY_SCALAR_OPERATOR(/)

VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR(+)
VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR(-)
VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR(*)
VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR(/)

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type operator==(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs) {
	return vmath::equals(lhs.x, rhs.x) && vmath::equals(lhs.y, rhs.y) && vmath::equals(lhs.z, rhs.z);
}

template<typename T>
typename std::enable_if<!std::is_floating_point<T>::value, bool>::type operator==(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

template<typename T>
bool operator!=(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T, 3>& v) {
    return os << "<" << v.x << "," << v.y << "," << v.z << ">";
}

template<typename T>
T dot(const Vector<T, 3>& v1, const Vector<T, 3>& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

template<typename T>
Vector<T, 3> cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2) {
    T x = (v1.y * v2.z) - (v1.z * v2.y);
    T y = (v1.z * v2.x) - (v1.x * v2.z);
    T z = (v1.x * v2.y) - (v1.y * v2.x);
    return Vector<T, 3>(x, y, z);
}

} // namespace vmath

#undef VMATH_VECTOR3_BINARY_SCALAR_OPERATOR
#undef VMATH_VECTOR3_BINARY_SCALAR_OPERATOR_ASSIGN
#undef VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR
#undef VMATH_VECTOR3_BINARY_COMPONENTWISE_OPERATOR_ASSIGN

#endif
