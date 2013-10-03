#ifndef MATH_CORE_VECTOR3_HPP
#define MATH_CORE_VECTOR3_HPP

#include <ostream>
#include "swizzle/swizzle2.hpp"
#include "swizzle/swizzle3.hpp"
#include "swizzle/swizzle4.hpp"
#include "swizzle/swizzle_gen.hpp"

namespace math {
namespace core {

template<typename T>
class Vector2;

/**
 * @class Vector3
 * @tparam T Storage type.
 */
template<typename T>
class Vector3 {
public:
	Vector3(void);
	Vector3(const T&, const T&, const T&);
	Vector3(const Vector2<T>&, const T&);
#if !defined(WINDOWS)
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors.
	// Reassess with VS2013.
	Vector3(const Vector3<T>&) = default;
	Vector3(Vector3<T>&&) = default;
	~Vector3(void) = default;

	Vector3<T>& operator=(const Vector3<T>&) = default;
#endif
	Vector3<T> operator-(void) const;
	Vector3<T> operator+(const Vector3<T>&) const;
	Vector3<T>& operator+=(const Vector3<T>&);
	Vector3<T> operator-(const Vector3<T>&) const;
	Vector3<T>& operator-=(const Vector3<T>&);
	Vector3<T> operator*(const Vector3<T>&) const;
	Vector3<T>& operator*=(const Vector3<T>&);
	Vector3<T> operator/(const Vector3<T>&) const;
	Vector3<T>& operator/=(const Vector3<T>&);
	Vector3<T> operator/(const T&) const;

	T mag(void) const;
	T mag2(void) const;
	Vector3<T> normal(void) const;
	Vector3<T>& normalize(void);

	bool operator==(const Vector3<T>&) const;
	bool operator!=(const Vector3<T>&) const;
	
	static T dot(const Vector3<T>&, const Vector3<T>&);
	static Vector3<T> cross(const Vector3<T>&, const Vector3<T>&);
	static Vector3<T> reflect(const Vector3<T>&, const Vector3<T>&);
	static Vector3<T> refract(const Vector3<T>&, const Vector3<T>&, const T&);
	static Vector3<T> lerp(const Vector3<T>&, const Vector3<T>&, const T&);

	union {
		// axis coords
		struct { T x, y, z; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, x, y, z)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, x, y, z)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, x, y, z)
		// texture coords
		struct { T s, t, p; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, s, t, p)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, s, t, p)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, s, t, p)
		// color values
		struct { T r, g, b; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, r, g, b)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, r, g, b)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, r, g, b)
	};
};

template<typename T>
Vector3<T> operator*(const T&, const Vector3<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const Vector3<T>&);

}
}

#include "vector3.inl"

#endif
