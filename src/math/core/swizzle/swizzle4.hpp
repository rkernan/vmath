#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE4_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T>
class Vector4;

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
	Vector4<T> operator+(const Vector4<T>&) const;
	Vector4<T>& operator+=(const Vector4<T>&);
	Vector4<T> operator-(const Vector4<T>&) const;
	Vector4<T>& operator-=(const Vector4<T>&);
	Vector4<T> operator*(const Vector4<T>&) const;
	Vector4<T>& operator*=(const Vector4<T>&);
	Vector4<T> operator/(const Vector4<T>&) const;
	Vector4<T>& operator/=(const Vector4<T>&);
	bool operator==(const Vector4<T>&) const;
	bool operator!=(const Vector4<T>&) const;
};

}
}

#include "swizzle4.inl"

#endif
