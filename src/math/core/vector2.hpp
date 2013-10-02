#ifndef MATH_CORE_VECTOR2_HPP
#define MATH_CORE_VECTOR2_HPP

#include <ostream>
#include "swizzle.hpp"

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
	vector2(const vector2<T>&) = default;
	vector2(vector2<T>&&) = default;
	~vector2(void) = default;

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
		struct { T x, y; };
		// 2d swizzles
		Swizzle2<T, 2, 0, 0> xx;
		Swizzle2<T, 2, 0, 1> xy;
		Swizzle2<T, 2, 1, 0> yx;
		Swizzle2<T, 2, 1, 1> yy;
		// 3d swizzles
		Swizzle3<T, 2, 0, 0, 0> xxx;
		Swizzle3<T, 2, 0, 0, 1> xxy;
		Swizzle3<T, 2, 0, 1, 0> xyx;
		Swizzle3<T, 2, 0, 1, 1> xyy;
		Swizzle3<T, 2, 1, 0, 0> yxx;
		Swizzle3<T, 2, 1, 0, 1> yxy;
		Swizzle3<T, 2, 1, 1, 0> yyx;
		Swizzle3<T, 2, 1, 1, 1> yyy;
		// 4d swizzles
		Swizzle4<T, 2, 0, 0, 0, 0> xxxx;
		Swizzle4<T, 2, 0, 0, 0, 1> xxxy;
		Swizzle4<T, 2, 0, 0, 1, 0> xxyx;
		Swizzle4<T, 2, 0, 0, 1, 1> xxyy;
		Swizzle4<T, 2, 0, 1, 0, 0> xyxx;
		Swizzle4<T, 2, 0, 1, 0, 1> xyxy;
		Swizzle4<T, 2, 0, 1, 1, 0> xyyx;
		Swizzle4<T, 2, 0, 1, 1, 1> xyyy;
		Swizzle4<T, 2, 1, 0, 0, 0> yxxx;
		Swizzle4<T, 2, 1, 0, 0, 1> yxxy;
		Swizzle4<T, 2, 1, 0, 1, 0> yxyx;
		Swizzle4<T, 2, 1, 0, 1, 1> yxyy;
		Swizzle4<T, 2, 1, 1, 0, 0> yyxx;
		Swizzle4<T, 2, 1, 1, 0, 1> yyxy;
		Swizzle4<T, 2, 1, 1, 1, 0> yyyx;
		Swizzle4<T, 2, 1, 1, 1, 1> yyyy;
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
