#ifndef MATH_CORE_VECTOR2_HPP
#define MATH_CORE_VECTOR2_HPP

#include <ostream>
#include "swizzle.hpp"
#include "swizzle_gen.hpp"

namespace math {
namespace core {

/**
 * @class vector2
 * @tparam T Storage type.
 */
template<typename T>
class vector2 {
public:
	vector2(void);
	vector2(const T&, const T&);
	// TODO VS2012 doesn't support C++11 explicitly defaulted constructors. Reassess with VS2013.
	//vector2(const vector2<T>&) = default;
	//vector2(vector2<T>&&) = default;
	//~vector2(void) = default;

	vector2<T>& operator=(const vector2<T>&);
	vector2<T> operator-(void) const;
	vector2<T> operator+(const vector2<T>&) const;
	vector2<T>& operator+=(const vector2<T>&);
	vector2<T> operator-(const vector2<T>&) const;
	vector2<T>& operator-=(const vector2<T>&);
	vector2<T> operator*(const vector2<T>&) const;
	vector2<T>& operator*=(const vector2<T>&);
	vector2<T> operator/(const vector2<T>&) const;
	vector2<T>& operator/=(const vector2<T>&);
	T norm(void) const;
	T mag(void) const;
	vector2<T> normal(void) const;
	vector2<T>& normalize(void);

	bool operator==(const vector2<T>&) const;
	bool operator!=(const vector2<T>&) const;
	
	static T dot(const vector2<T>&, const vector2<T>&);
	static T cross(const vector2<T>&, const vector2<T>&);
	static vector2<T> reflect(const vector2<T>&, const vector2<T>&);
	static vector2<T> refract(const vector2<T>&, const vector2<T>&, const T&);
	static vector2<T> lerp(const vector2<T>&, const vector2<T>&, const T&);

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
vector2<T> operator*(const T&, const vector2<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const vector2<T>&);

}
}

#include "vector2.inl"

#endif
