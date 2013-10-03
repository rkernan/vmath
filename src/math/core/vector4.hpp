#ifndef MATH_CORE_vector4_HPP
#define MATH_CORE_vector4_HPP

#include <ostream>
#include "swizzle.hpp"
#include "swizzle_gen.hpp"

namespace math {
namespace core {

/**
 * @class vector4
 * @tparam T Storage type.
 */
template<typename T>
class vector4 {
public:
	vector4(void);
	vector4(const T&, const T&, const T&, const T&);
	vector4(const vector2<T>&, const T&, const T&);
	vector4(const vector3<T>&, const T&);
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors. Reassess with VS2013.
	//vector4(const vector4<T>&) = default;
	//vector4(vector4<T>&&) = default;
	//~vector4(void) = default;

	// vector4<T>& operator=(const vector4<T>&) = default;
	vector4<T> operator-(void) const;
	vector4<T> operator+(const vector4<T>&) const;
	vector4<T>& operator+=(const vector4<T>&);
	vector4<T> operator-(const vector4<T>&) const;
	vector4<T>& operator-=(const vector4<T>&);
	vector4<T> operator*(const vector4<T>&) const;
	vector4<T>& operator*=(const vector4<T>&);
	vector4<T> operator/(const vector4<T>&) const;
	vector4<T>& operator/=(const vector4<T>&);
	T norm(void) const;
	T mag(void) const;
	vector4<T> normal(void) const;
	vector4<T>& normalize(void);

	bool operator==(const vector4<T>&) const;
	bool operator!=(const vector4<T>&) const;
	
	static T dot(const vector4<T>&, const vector4<T>&);
	static vector4<T> reflect(const vector4<T>&, const vector4<T>&);
	static vector4<T> refract(const vector4<T>&, const vector4<T>&, const T&);
	static vector4<T> lerp(const vector4<T>&, const vector4<T>&, const T&);

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
vector4<T> operator*(const T&, const vector4<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const vector4<T>&);

}
}

#include "vector4.inl"

#endif
