#ifndef MATH_CORE_VECTOR3_HPP
#define MATH_CORE_VECTOR3_HPP

#include <ostream>
#include "swizzle.hpp"
#include "swizzle_gen.hpp"

namespace math {
namespace core {

template<typename T>
class vector2;

/**
 * @class vector3
 * @tparam T Storage type.
 */
template<typename T>
class vector3 {
public:
	vector3(void);
	vector3(const T&, const T&, const T&);
	vector3(const vector2<T>&, const T&);
	vector3(const vector3<T>&) = default;
	vector3(vector3<T>&&) = default;
	~vector3(void) = default;

	vector3<T>& operator=(const vector3<T>&);
	vector3<T> operator-(void) const;
	vector3<T> operator+(const vector3<T>&) const;
	vector3<T>& operator+=(const vector3<T>&);
	vector3<T> operator-(const vector3<T>&) const;
	vector3<T>& operator-=(const vector3<T>&);
	vector3<T> operator*(const vector3<T>&) const;
	vector3<T>& operator*=(const vector3<T>&);
	vector3<T> operator/(const vector3<T>&) const;
	vector3<T>& operator/=(const vector3<T>&);
	T norm(void) const;
	T mag(void) const;
	vector3<T> normal(void) const;
	vector3<T>& normalize(void);

	bool operator==(const vector3<T>&) const;
	bool operator!=(const vector3<T>&) const;
	
	static T dot(const vector3<T>&, const vector3<T>&);
	static vector3<T> cross(const vector3<T>&, const vector3<T>&);
	static vector3<T> reflect(const vector3<T>&, const vector3<T>&);
	static vector3<T> refract(const vector3<T>&, const vector3<T>&, const T&);
	static vector3<T> lerp(const vector3<T>&, const vector3<T>&, const T&);

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
vector3<T> operator*(const T&, const vector3<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const vector3<T>&);

}
}

#include "vector3.inl"

#endif
