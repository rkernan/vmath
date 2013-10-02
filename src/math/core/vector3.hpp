#ifndef MATH_CORE_VECTOR3_HPP
#define MATH_CORE_VECTOR3_HPP

#include <ostream>
#include "swizzle.hpp"

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
		struct { T x, y, z; };
		// 2d swizzles
		Swizzle2<T, 3, 0, 0> xx;
		Swizzle2<T, 3, 0, 1> xy;
		Swizzle2<T, 3, 0, 2> xz;
		Swizzle2<T, 3, 1, 0> yx;
		Swizzle2<T, 3, 1, 1> yy;
		Swizzle2<T, 3, 1, 2> yz;
		Swizzle2<T, 3, 2, 0> zx;
		Swizzle2<T, 3, 2, 1> zy;
		Swizzle2<T, 3, 2, 2> zz;
		// 3d swizzles
		Swizzle3<T, 3, 0, 0, 0> xxx;
		Swizzle3<T, 3, 0, 0, 1> xxy;
		Swizzle3<T, 3, 0, 0, 2> xxz;
		Swizzle3<T, 3, 0, 1, 0> xyx;
		Swizzle3<T, 3, 0, 1, 1> xyy;
		Swizzle3<T, 3, 0, 1, 2> xyz;
		Swizzle3<T, 3, 0, 2, 0> xzx;
		Swizzle3<T, 3, 0, 2, 1> xzy;
		Swizzle3<T, 3, 0, 2, 2> xzz;
		Swizzle3<T, 3, 1, 0, 0> yxx;
		Swizzle3<T, 3, 1, 0, 1> yxy;
		Swizzle3<T, 3, 1, 0, 2> yxz;
		Swizzle3<T, 3, 1, 1, 0> yyx;
		Swizzle3<T, 3, 1, 1, 1> yyy;
		Swizzle3<T, 3, 1, 1, 2> yyz;
		Swizzle3<T, 3, 1, 2, 0> yzx;
		Swizzle3<T, 3, 1, 2, 1> yzy;
		Swizzle3<T, 3, 1, 2, 2> yzz;
		Swizzle3<T, 3, 2, 0, 0> zxx;
		Swizzle3<T, 3, 2, 0, 1> zxy;
		Swizzle3<T, 3, 2, 0, 2> zxz;
		Swizzle3<T, 3, 2, 1, 0> zyx;
		Swizzle3<T, 3, 2, 1, 1> zyy;
		Swizzle3<T, 3, 2, 1, 2> zyz;
		Swizzle3<T, 3, 2, 2, 0> zzx;
		Swizzle3<T, 3, 2, 2, 1> zzy;
		Swizzle3<T, 3, 2, 2, 2> zzz;
		// 4d swizzles
		Swizzle4<T, 3, 0, 0, 0, 0> xxxx;
		Swizzle4<T, 3, 0, 0, 0, 1> xxxy;
		Swizzle4<T, 3, 0, 0, 0, 2> xxxz;
		Swizzle4<T, 3, 0, 0, 1, 0> xxyx;
		Swizzle4<T, 3, 0, 0, 1, 1> xxyy;
		Swizzle4<T, 3, 0, 0, 1, 2> xxyz;
		Swizzle4<T, 3, 0, 0, 2, 0> xxzx;
		Swizzle4<T, 3, 0, 0, 2, 1> xxzy;
		Swizzle4<T, 3, 0, 0, 2, 2> xxzz;
		Swizzle4<T, 3, 0, 1, 0, 0> xyxx;
		Swizzle4<T, 3, 0, 1, 0, 1> xyxy;
		Swizzle4<T, 3, 0, 1, 0, 2> xyxz;
		Swizzle4<T, 3, 0, 1, 1, 0> xyyx;
		Swizzle4<T, 3, 0, 1, 1, 1> xyyy;
		Swizzle4<T, 3, 0, 1, 1, 2> xyyz;
		Swizzle4<T, 3, 0, 1, 2, 0> xyzx;
		Swizzle4<T, 3, 0, 1, 2, 1> xyzy;
		Swizzle4<T, 3, 0, 1, 2, 2> xyzz;
		Swizzle4<T, 3, 0, 2, 0, 0> xzxx;
		Swizzle4<T, 3, 0, 2, 0, 1> xzxy;
		Swizzle4<T, 3, 0, 2, 0, 2> xzxz;
		Swizzle4<T, 3, 0, 2, 1, 0> xzyx;
		Swizzle4<T, 3, 0, 2, 1, 1> xzyy;
		Swizzle4<T, 3, 0, 2, 1, 2> xzyz;
		Swizzle4<T, 3, 0, 2, 2, 0> xzzx;
		Swizzle4<T, 3, 0, 2, 2, 1> xzzy;
		Swizzle4<T, 3, 0, 2, 2, 2> xzzz;
		Swizzle4<T, 3, 1, 0, 0, 0> yxxx;
		Swizzle4<T, 3, 1, 0, 0, 1> yxxy;
		Swizzle4<T, 3, 1, 0, 0, 2> yxxz;
		Swizzle4<T, 3, 1, 0, 1, 0> yxyx;
		Swizzle4<T, 3, 1, 0, 1, 1> yxyy;
		Swizzle4<T, 3, 1, 0, 1, 2> yxyz;
		Swizzle4<T, 3, 1, 0, 2, 0> yxzx;
		Swizzle4<T, 3, 1, 0, 2, 1> yxzy;
		Swizzle4<T, 3, 1, 0, 2, 2> yxzz;
		Swizzle4<T, 3, 1, 1, 0, 0> yyxx;
		Swizzle4<T, 3, 1, 1, 0, 1> yyxy;
		Swizzle4<T, 3, 1, 1, 0, 2> yyxz;
		Swizzle4<T, 3, 1, 1, 1, 0> yyyx;
		Swizzle4<T, 3, 1, 1, 1, 1> yyyy;
		Swizzle4<T, 3, 1, 1, 1, 2> yyyz;
		Swizzle4<T, 3, 1, 1, 2, 0> yyzx;
		Swizzle4<T, 3, 1, 1, 2, 1> yyzy;
		Swizzle4<T, 3, 1, 1, 2, 2> yyzz;
		Swizzle4<T, 3, 1, 2, 0, 0> yzxx;
		Swizzle4<T, 3, 1, 2, 0, 1> yzxy;
		Swizzle4<T, 3, 1, 2, 0, 2> yzxz;
		Swizzle4<T, 3, 1, 2, 1, 0> yzyx;
		Swizzle4<T, 3, 1, 2, 1, 1> yzyy;
		Swizzle4<T, 3, 1, 2, 1, 2> yzyz;
		Swizzle4<T, 3, 1, 2, 2, 0> yzzx;
		Swizzle4<T, 3, 1, 2, 2, 1> yzzy;
		Swizzle4<T, 3, 1, 2, 2, 2> yzzz;
		Swizzle4<T, 3, 2, 0, 0, 0> zxxx;
		Swizzle4<T, 3, 2, 0, 0, 1> zxxy;
		Swizzle4<T, 3, 2, 0, 0, 2> zxxz;
		Swizzle4<T, 3, 2, 0, 1, 0> zxyx;
		Swizzle4<T, 3, 2, 0, 1, 1> zxyy;
		Swizzle4<T, 3, 2, 0, 1, 2> zxyz;
		Swizzle4<T, 3, 2, 0, 2, 0> zxzx;
		Swizzle4<T, 3, 2, 0, 2, 1> zxzy;
		Swizzle4<T, 3, 2, 0, 2, 2> zxzz;
		Swizzle4<T, 3, 2, 1, 0, 0> zyxx;
		Swizzle4<T, 3, 2, 1, 0, 1> zyxy;
		Swizzle4<T, 3, 2, 1, 0, 2> zyxz;
		Swizzle4<T, 3, 2, 1, 1, 0> zyyx;
		Swizzle4<T, 3, 2, 1, 1, 1> zyyy;
		Swizzle4<T, 3, 2, 1, 1, 2> zyyz;
		Swizzle4<T, 3, 2, 1, 2, 0> zyzx;
		Swizzle4<T, 3, 2, 1, 2, 1> zyzy;
		Swizzle4<T, 3, 2, 1, 2, 2> zyzz;
		Swizzle4<T, 3, 2, 2, 0, 0> zzxx;
		Swizzle4<T, 3, 2, 2, 0, 1> zzxy;
		Swizzle4<T, 3, 2, 2, 0, 2> zzxz;
		Swizzle4<T, 3, 2, 2, 1, 0> zzyx;
		Swizzle4<T, 3, 2, 2, 1, 1> zzyy;
		Swizzle4<T, 3, 2, 2, 1, 2> zzyz;
		Swizzle4<T, 3, 2, 2, 2, 0> zzzx;
		Swizzle4<T, 3, 2, 2, 2, 1> zzzy;
		Swizzle4<T, 3, 2, 2, 2, 2> zzzz;
	};
};

template<typename T>
vector3<T> operator*(const T&, const vector3<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const vector3<T>&);

}
}

// #include "vector3.inl"

#endif
