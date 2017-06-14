#ifndef VMATH_QUATERNION_HPP
#define VMATH_QUATERNION_HPP

#include <array>
#include <cmath>
#include <ostream>
#include <type_traits>
#include <vmath/vector3.hpp>

#define VMATH_QUATERNION_BINARY_OPERATOR(OP) \
	template<typename T> \
	Quaternion<T> operator OP (Quaternion<T> lhs, const Quaternion<T>& rhs) { \
		return lhs OP##= rhs; \
	}

#define VMATH_QUATERNION_BINARY_OPERATOR_ASSIGN(OP) \
	Quaternion<T>& operator OP (const Quaternion<T>& h) { \
		this->x OP h.x; \
		this->y OP h.y; \
		this->z OP h.z; \
		this->w OP h.w; \
		return *this; \
	}

#define VMATH_QUATERNION_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T> \
	Quaternion<T> operator OP (Quaternion<T> h, const T& s) { \
		return h OP##= s; \
	}

#define VMATH_QUATERNION_BINARY_SCALAR_OPERATOR_ASSIGN(OP) \
	Quaternion<T>& operator OP (const T& s) { \
		this->x OP s; \
		this->y OP s; \
		this->z OP s; \
		this->w OP s; \
		return *this; \
	}

namespace vmath {

/*!
 * A quaternion rotation
 */
template<typename T>
class Quaternion {
public:
	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
	};

	Quaternion() : x(), y(), z(), w() {}
	Quaternion(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

	Quaternion(const T& pitch, const T& yaw, const T& roll) {
		auto half_pitch = pitch / static_cast<T>(2.0);
		auto half_yaw = yaw / static_cast<T>(2.0);
		auto half_roll = roll / static_cast<T>(2.0);
		auto sinp = std::sin(half_pitch);
		auto siny = std::sin(half_yaw);
		auto sinr = std::sin(half_roll);
		auto cosp = std::cos(half_pitch);
		auto cosy = std::cos(half_yaw);
		auto cosr = std::cos(half_roll);
		this->w = cosp * cosy * cosr + sinp * siny * sinr;
		this->x = sinp * cosy * cosr - cosp * siny * sinr;
		this->y = cosp * siny * cosr + sinp * cosy * sinr;
		this->z = cosp * cosy * sinr - sinp * siny * cosr;
		this->normalize();
	}

	Quaternion(const Vector<T, 3>& axis, const T& angle) {
		auto half_angle = angle / static_cast<T>(2.0);
		auto n =  axis.normal() * std::sin(half_angle);
		this->x = n.x;
		this->y = n.y;
		this->z = n.z;
		this->w = std::cos(half_angle);
	}

/* 	explicit Quaternion(const Matrix<T, 4, 4>& mat) { */
/* 		// TODO */
/* 	} */

	T operator[](const std::size_t i) const {
		return this->data.at(i);
	}

	T& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	T pitch() const {
		return std::atan2(static_cast<T>(2.0) * (this->y * this->z + this->w * this->x),
			this->w * this->w - this->x * this->x - this->y * this->y + this->z * this->z);
	}

	T yaw() const {
		return std::asin(static_cast<T>(-2.0) * (this->x * this->z - this-> w * this->y));
	}

	T roll() const {
		return std::atan2(static_cast<T>(2.0) * (this->x * this->y + this->w * this->z),
			this->w * this->w + this->x * this->x - this->y * this->y - this->z * this->z);
	}

	Vector<T, 3> axis() const {
		return Vector<T, 3>(this->x, this->y, this->z).normal();
	}

	T angle() const {
		return std::acos(this->w) * static_cast<T>(2.0);
	}

	VMATH_QUATERNION_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_QUATERNION_BINARY_SCALAR_OPERATOR_ASSIGN(/=)

	VMATH_QUATERNION_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_QUATERNION_BINARY_OPERATOR_ASSIGN(-=)
	VMATH_QUATERNION_BINARY_OPERATOR_ASSIGN(/=)

	Quaternion<T>& operator*=(const Quaternion<T>& h) {
		auto x = (this->w * h.x) + (this->x * h.w) + (this->y * h.z) - (this->z * h.y);
		auto y = (this->w * h.y) + (this->y * h.w) + (this->z * h.x) - (this->x * h.z);
		auto z = (this->w * h.z) + (this->z * h.w) + (this->x * h.y) - (this->y * h.x);
		auto w = (this->w * h.w) - (this->x * h.x) - (this->y * h.y) - (this->z * h.z);
		return *this = Quaternion<T>(x, y, z, w);
	}

	Quaternion<T> operator-() const {
		return *this * static_cast<T>(-1.0);
	}

	T mag() const {
		return std::sqrt(this->mag2());
	}

	T mag2() const {
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
	}

	Quaternion<T> normal() const {
		return *this / this->mag();
	}

	Quaternion<T>& normalize() {
		return *this = this->normal();
	}


	Quaternion<T> inverse() const {
		return Quaternion<T>(-this->x, -this->y, -this->z, this->w) / this->mag2();
	}

	Quaternion<T>& invert() {
		return *this = this->inverse();
	}
};

VMATH_QUATERNION_BINARY_SCALAR_OPERATOR(*)
VMATH_QUATERNION_BINARY_SCALAR_OPERATOR(/)

VMATH_QUATERNION_BINARY_OPERATOR(+)
VMATH_QUATERNION_BINARY_OPERATOR(-)
VMATH_QUATERNION_BINARY_OPERATOR(*)
VMATH_QUATERNION_BINARY_OPERATOR(/)

template<typename T>
Vector<T, 3> operator*(const Quaternion<T>& h, const Vector<T, 3>& v) {
	auto n = v.normal();
	Quaternion<T> vq(n.x, n.y, n.z, static_cast<T>(0.0));
	Quaternion<T> cq(h.inverse());
	Quaternion<T> rq(vq * cq);
	rq = h * rq;
	return Vector<T, 3>(rq.x, rq.y, rq.z);
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
	return vmath::equals(lhs.x, rhs.x) && vmath::equals(lhs.y, rhs.y) && vmath::equals(lhs.z, rhs.z) && vmath::equals(lhs.w, rhs.w);
}

template<typename T>
typename std::enable_if<!std::is_floating_point<T>::value, bool>::type operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

template<typename T>
bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Quaternion<T>& h) {
	return os << "<" << h.x << "," << h.y < "," << h.z << "," << h.w << ">";
}

template<typename T>
T dot(const Quaternion<T>& h1, const Quaternion<T>& h2) {
	return (h1.x * h2.x) + (h1.y * h2.y) + (h1.z * h2.z) + (h1.w * h2.w);
}

template<typename T>
Quaternion<T> lerp(const Quaternion<T>& start, const Quaternion<T>& end, const T& t) {
	return start + (end - start) * t;
}

template<typename T>
Quaternion<T> slerp(const Quaternion<T>& start, const Quaternion<T>& end, const T& t, const bool shortest=true) {
	T d = vmath::dot(start, end);
	auto h = end;
	if (d < static_cast<T>(0.0) && shortest) {
		d = -d;
		h = -end;
	}
	auto angle = std::acos(d);
	return (start * std::sin(angle * (static_cast<T>(1.0) - t)) + h * (std::sin(angle * t))) / std::sin(angle);
}

template<typename T>
bool equals(const Quaternion<T>& a, const Quaternion<T>& b) {
	return a == b;
}

} // namespace vmath

#undef VMATH_QUATERNION_BINARY_OPERATOR
#undef VMATH_QUATERNION_BINARY_OPERATOR_ASSIGN
#undef VMATH_QUATERNION_BINARY_SCALAR_OPERATOR
#undef VMATH_QUATERNION_BINARY_SCALAR_OPERATOR_ASSIGN

#endif
