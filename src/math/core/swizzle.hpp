#ifndef MATH_CORE_SWIZZLE_HPP
#define MATH_CORE_SWIZZLE_HPP

#include <cstddef>

namespace math {
namespace core {

template<typename T>
class vector2;

template<typename T>
class vector3;

template<typename T>
class vector4;

/**
 * @class Swizzle
 * @tparam T Storage type.
 * @tparam N Storage size.
 */
template<typename T, size_t N>
class Swizzle {
protected:
	T values[N];
};

/**
 * @class Swizzle2
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 */
template<typename T, size_t N, size_t E1, size_t E2>
class Swizzle2 : Swizzle<T, N> {
public:
	operator vector2<T>();
	vector2<T>& operator=(const vector2<T>&);
	vector2<T>& operator+=(const vector2<T>&);
	vector2<T>& operator-=(const vector2<T>&);
	vector2<T>& operator*=(const vector2<T>&);
	vector2<T>& operator/=(const vector2<T>&);
};

/**
 * @class Swizzle3
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 */
template<typename T, size_t N, size_t E1, size_t E2, size_t E3>
class Swizzle3 : Swizzle<T, N> {
public:
	operator vector3<T>();
	vector3<T>& operator=(const vector3<T>&);
	vector3<T>& operator+=(const vector3<T>&);
	vector3<T>& operator-=(const vector3<T>&);
	vector3<T>& operator*=(const vector3<T>&);
	vector3<T>& operator/=(const vector3<T>&);
};

/**
 * @class Swizzle4
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 * @tparam E4 Index of fourth element.
 */
template<typename T, size_t N, size_t E1, size_t E2, size_t E3, size_t E4>
class Swizzle4 : Swizzle<T, N> {
public:
	operator vector4<T>();
	vector4<T>& operator=(const vector4<T>&);
	vector4<T>& operator+=(const vector4<T>&);
	vector4<T>& operator-=(const vector4<T>&);
	vector4<T>& operator*=(const vector4<T>&);
	vector4<T>& operator/=(const vector4<T>&);
};

}
}

#include "swizzle.inl"

#endif
