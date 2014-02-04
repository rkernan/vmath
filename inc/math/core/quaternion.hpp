#ifndef MATH_CORE_QUATERNION_HPP
#define MATH_CORE_QUATERNION_HPP

#include <cstddef>
#include <ostream>

#include "matrix.hpp"
#include "vector.hpp"

namespace math {

namespace core {

/**
 * @class Quaternion
 * @tparam T Storage type.
 * A quaternion rotation.
 */
template<typename T>
class Quaternion {
public:
	Quaternion(void) : x(), y(), z(), w() {}
	Quaternion(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	Quaternion(const T&, const T&, const T&);
	Quaternion(const Vector<T, 3>&, const T&);
	Quaternion(const Matrix<T, 4>&);

	Quaternion<T>& operator=(const Quaternion<T>&);

	T operator[](const std::size_t) const;
	T& operator[](const std::size_t);

	Quaternion<T> operator-(void) const;

	Quaternion<T> operator+(const Quaternion<T>&) const;
	Quaternion<T>& operator+=(const Quaternion<T>&);
	Quaternion<T> operator-(const Quaternion<T>&) const;
	Quaternion<T>& operator-=(const Quaternion<T>&);

	Quaternion<T> operator*(const Quaternion<T>&) const;
	Quaternion<T>& operator*=(const Quaternion<T>&);

	Vector<T, 3> operator*(const Vector<T, 3>&) const;

	Quaternion<T> operator*(const T&) const;
	Quaternion<T>& operator*=(const T&);
	Quaternion<T> operator/(const T&) const;
	Quaternion<T>& operator/=(const T&);

	T mag2(void) const;
	T mag(void) const;

	Quaternion<T> normal(void) const;
	Quaternion<T>& normalize(void);

	Quaternion<T> inverse(void) const;
	Quaternion<T>& invert(void);

	T pitch(void) const;
	T yaw(void) const;
	T roll(void) const;

	Vector<T, 3> axis(void) const;
	T angle(void) const;

	Matrix<T, 4> matrix4(void) const;

	bool operator==(const Quaternion<T>&) const;
	bool operator!=(const Quaternion<T>&) const;

	static T dot(const Quaternion<T>&, const Quaternion<T>&);

	static Quaternion<T> lerp(const Quaternion<T>&, const Quaternion<T>&, const T&);
	static Quaternion<T> slerp(const Quaternion<T>&, const Quaternion<T>&, const T&, const bool=false);

	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
	};
};

}
}

#include "quaternion.inl"

#endif
