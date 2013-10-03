#ifndef MATH_CORE_QUATERNION_HPP
#define MATH_CORE_QUATERNION_HPP

#include <ostream>

namespace math {
namespace core {

template<typename T>
class vector3;

/**
 * @class quaternion
 * @tparam T Storage type.
 */
template<typename T>
class quaternion {
public:
	quaternion(void);
	quaternion(const T&, const T&, const T&, const T&);
#if !defined(WIN32)
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors.
	// Reassess with VS2013.
	quaternion(const quaternion<T>&) = default;
	quaternion(quaternion<T>&&) = default;
	~quaternion(void) = default;

	quaternion<T>& operator=(const quaternion<T>&) = default;
#endif
	quaternion<T> operator-(void) const;
	quaternion<T> operator+(const quaternion<T>&) const;
	quaternion<T>& operator+=(const quaternion<T>&);
	quaternion<T> operator-(const quaternion<T>&) const;
	quaternion<T>& operator-=(const quaternion<T>&);
	quaternion<T> operator*(const quaternion<T>&) const;
	quaternion<T>& operator*=(const quaternion<T>&);
	quaternion<T> operator/(const quaternion<T>&) const;
	quaternion<T>& operator/=(const quaternion<T>&);
	vector3<T> operator*(const vector3<T>&) const;
	quaternion<T> operator/(const T&) const;

	T mag(void) const;
	T mag2(void) const;
	quaternion<T> normal(void) const;
	quaternion<T>& normalize(void);
	quaternion<T> conjugate(void) const;
	quaternion<T> inverse(void) const;
	
	bool operator==(const quaternion<T>&) const;
	bool operator!=(const quaternion<T>&) const;

	static T dot(const quaternion<T>&, const quaternion<T>&);
	static quaternion<T> lerp(const quaternion<T>&, const quaternion<T>&, const T&);
	static quaternion<T> slerp(const quaternion<T>&, const quaternion<T>&, const T&, const bool=false);

	T x, y, z, w;
};

template<typename T>
quaternion<T> operator*(const T&, const quaternion<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const quaternion<T>&);

}
}

#include "quaternion.inl"

#endif
