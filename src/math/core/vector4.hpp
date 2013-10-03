#ifndef MATH_CORE_VECTOR4_HPP
#define MATH_CORE_VECTOR4_HPP

#include <ostream>
#include "swizzle/swizzle2.hpp"
#include "swizzle/swizzle3.hpp"
#include "swizzle/swizzle4.hpp"
#include "swizzle/swizzle_gen.hpp"

namespace math {
namespace core {

template<typename T>
class Vector2;

template<typename T>
class Vector3;

/**
 * @class Vector4
 * @tparam T Storage type.
 */
template<typename T>
class Vector4 {
public:
	Vector4(void);
	Vector4(const T&, const T&, const T&, const T&);
	Vector4(const Vector2<T>&, const T&, const T&);
	Vector4(const Vector3<T>&, const T&);
#if !defined(WINDOWS)
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors.
	// Reassess with VS2013.
	Vector4(const Vector4<T>&) = default;
	Vector4(Vector4<T>&&) = default;
	~Vector4(void) = default;

	Vector4<T>& operator=(const Vector4<T>&) = default;
#endif
	Vector4<T> operator-(void) const;
	Vector4<T> operator+(const Vector4<T>&) const;
	Vector4<T>& operator+=(const Vector4<T>&);
	Vector4<T> operator-(const Vector4<T>&) const;
	Vector4<T>& operator-=(const Vector4<T>&);
	Vector4<T> operator*(const Vector4<T>&) const;
	Vector4<T>& operator*=(const Vector4<T>&);
	Vector4<T> operator/(const Vector4<T>&) const;
	Vector4<T>& operator/=(const Vector4<T>&);
	Vector4<T> operator/(const T&) const;

	T mag(void) const;
	T mag2(void) const;
	Vector4<T> normal(void) const;
	Vector4<T>& normalize(void);

	bool operator==(const Vector4<T>&) const;
	bool operator!=(const Vector4<T>&) const;
	
	static T dot(const Vector4<T>&, const Vector4<T>&);
	static Vector4<T> reflect(const Vector4<T>&, const Vector4<T>&);
	static Vector4<T> refract(const Vector4<T>&, const Vector4<T>&, const T&);
	static Vector4<T> lerp(const Vector4<T>&, const Vector4<T>&, const T&);

	union {
		// axis coords
		struct { T x, y, z, w; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, x, y, z, w)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, x, y, z, w)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, x, y, z, w)
		// texture coords
		struct { T s, t, p, q; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, s, t, p, q)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, s, t, p, q)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, s, t, p, q)
		// color values
		struct { T r, g, b, a; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, r, g, b, a)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, r, g, b, a)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, r, g, b, a)
	};
};

template<typename T>
Vector4<T> operator*(const T&, const Vector4<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const Vector4<T>&);

}
}

#include "vector4.inl"

#endif
