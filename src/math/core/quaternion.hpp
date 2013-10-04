#ifndef MATH_CORE_QUATERNION_HPP
#define MATH_CORE_QUATERNION_HPP

#include <ostream>
#include <tuple>

namespace math {

namespace tuple {

template<typename T>
class EulerAngles;

template<typename T>
class AxisAngle;

}

namespace core {

template<typename T>
class Vector3;

/**
 * @class Quaternion
 * @tparam T Storage type.
 */
template<typename T>
class Quaternion {
public:
	Quaternion(void);
	Quaternion(const T&, const T&, const T&, const T&);
	Quaternion(const math::tuple::AxisAngle<T>&);
	Quaternion(const math::tuple::EulerAngles<T>&);
#if !defined(WINDOWS)
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors.
	// Reassess with VS2013.
	Quaternion(const Quaternion<T>&) = default;
	Quaternion(Quaternion<T>&&) = default;
	~Quaternion(void) = default;

	Quaternion<T>& operator=(const Quaternion<T>&) = default;
#endif
	Quaternion<T> operator-(void) const;
	Quaternion<T> operator+(const Quaternion<T>&) const;
	Quaternion<T>& operator+=(const Quaternion<T>&);
	Quaternion<T> operator-(const Quaternion<T>&) const;
	Quaternion<T>& operator-=(const Quaternion<T>&);
	Quaternion<T> operator*(const Quaternion<T>&) const;
	Quaternion<T>& operator*=(const Quaternion<T>&);
	Quaternion<T> operator/(const Quaternion<T>&) const;
	Quaternion<T>& operator/=(const Quaternion<T>&);
	Vector3<T> operator*(const Vector3<T>&) const;
	Quaternion<T> operator/(const T&) const;

	T mag(void) const;
	T mag2(void) const;
	Quaternion<T> normal(void) const;
	Quaternion<T>& normalize(void);
	Quaternion<T> conjugate(void) const;
	Quaternion<T> inverse(void) const;

	math::tuple::EulerAngles<T> eulerAngles(void) const;
	math::tuple::AxisAngle<T> axisAngle(void) const;
	
	bool operator==(const Quaternion<T>&) const;
	bool operator!=(const Quaternion<T>&) const;

	static T dot(const Quaternion<T>&, const Quaternion<T>&);
	static Quaternion<T> lerp(const Quaternion<T>&, const Quaternion<T>&, const T&);
	static Quaternion<T> slerp(const Quaternion<T>&, const Quaternion<T>&, const T&, const bool=false);

	T x, y, z, w;
};

template<typename T>
Quaternion<T> operator*(const T&, const Quaternion<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const Quaternion<T>&);

}
}

#include "quaternion.inl"

#endif
