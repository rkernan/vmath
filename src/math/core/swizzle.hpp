#ifndef MATH_CORE_SWIZZLE_HPP
#define MATH_CORE_SWIZZLE_HPP

#include <cstddef>

namespace math {
namespace core {

template<typename T>
class Vector2;

template<typename T>
class Vector3;

template<typename T>
class Vector4;

/**
 * @class Swizzle
 * @tparam T Storage type.
 * @tparam N Storage size.
 */
template<typename T, std::size_t N>
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
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
class Swizzle2 : Swizzle<T, N> {
public:
	operator Vector2<T>();
	Vector2<T>& operator=(const Vector2<T>&);
	Vector2<T>& operator+=(const Vector2<T>&);
	Vector2<T>& operator-=(const Vector2<T>&);
	Vector2<T>& operator*=(const Vector2<T>&);
	Vector2<T>& operator/=(const Vector2<T>&);
};

/**
 * @class Swizzle3
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : Swizzle<T, N> {
public:
	operator Vector3<T>();
	Vector3<T>& operator=(const Vector3<T>&);
	Vector3<T>& operator+=(const Vector3<T>&);
	Vector3<T>& operator-=(const Vector3<T>&);
	Vector3<T>& operator*=(const Vector3<T>&);
	Vector3<T>& operator/=(const Vector3<T>&);
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
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
class Swizzle4 : Swizzle<T, N> {
public:
	operator Vector4<T>();
	Vector4<T>& operator=(const Vector4<T>&);
	Vector4<T>& operator+=(const Vector4<T>&);
	Vector4<T>& operator-=(const Vector4<T>&);
	Vector4<T>& operator*=(const Vector4<T>&);
	Vector4<T>& operator/=(const Vector4<T>&);
};

}
}

#include "swizzle.inl"

#endif
