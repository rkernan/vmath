#ifndef MATH_CORE_VECTOR2_HPP
#define MATH_CORE_VECTOR2_HPP

#include <ostream>
#include "swizzle.hpp"
#include "swizzle_gen.hpp"

namespace math {
namespace core {

/**
 * @class Vector2
 * @tparam T Storage type.
 */
template<typename T>
class Vector2 {
public:
	Vector2(void);
	Vector2(const T&, const T&);
#if !defined(WIN32)
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors.
	// Reassess with VS2013.
	Vector2(const Vector2<T>&) = default;
	Vector2(Vector2<T>&&) = default;
	~Vector2(void) = default;

	Vector2<T>& operator=(const Vector2<T>&) = default;
#endif
	Vector2<T> operator-(void) const;
	Vector2<T> operator+(const Vector2<T>&) const;
	Vector2<T>& operator+=(const Vector2<T>&);
	Vector2<T> operator-(const Vector2<T>&) const;
	Vector2<T>& operator-=(const Vector2<T>&);
	Vector2<T> operator*(const Vector2<T>&) const;
	Vector2<T>& operator*=(const Vector2<T>&);
	Vector2<T> operator/(const Vector2<T>&) const;
	Vector2<T>& operator/=(const Vector2<T>&);
	Vector2<T> operator/(const T&) const;

	T mag(void) const;
	T mag2(void) const;
	Vector2<T> normal(void) const;
	Vector2<T>& normalize(void);

	bool operator==(const Vector2<T>&) const;
	bool operator!=(const Vector2<T>&) const;
	
	static T dot(const Vector2<T>&, const Vector2<T>&);
	static T cross(const Vector2<T>&, const Vector2<T>&);
	static Vector2<T> reflect(const Vector2<T>&, const Vector2<T>&);
	static Vector2<T> refract(const Vector2<T>&, const Vector2<T>&, const T&);
	static Vector2<T> lerp(const Vector2<T>&, const Vector2<T>&, const T&);

	union {
		// axis coords
		struct { T x, y; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, x, y)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, x, y)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, x, y)
		// texture coords
		struct {T s, t; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, s, t)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, s, t)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, s, t)
		// color values
		struct { T r, g; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, r, g)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, r, g)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, r, g)
	};
};

template<typename T>
Vector2<T> operator*(const T&, const Vector2<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const Vector2<T>&);

}
}

#include "vector2.inl"

#endif
