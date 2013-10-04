#ifndef MATH_CORE_SWIZZLE_SWIZZLE2_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE2_HPP

#include "swizzle.hpp"
#include <type_traits>

namespace math {
namespace core {

template<typename T>
class Vector2;

/**
 * @class Swizzle2
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
class Swizzle2 : public Swizzle<T, N> {
public:
	operator Vector2<T>();
	Vector2<T>& operator=(const Vector2<T>&);
	Vector2<T> operator+(const Vector2<T>&) const;
	Vector2<T>& operator+=(const Vector2<T>&);
	Vector2<T> operator-(const Vector2<T>&) const;
	Vector2<T>& operator-=(const Vector2<T>&);
	Vector2<T> operator*(const Vector2<T>&) const;
	Vector2<T>& operator*=(const Vector2<T>&);
	Vector2<T> operator/(const Vector2<T>&) const;
	Vector2<T>& operator/=(const Vector2<T>&);
	bool operator==(const Vector2<T>&) const;
	bool operator!=(const Vector2<T>&) const;
	Vector2<T> operator/(const T&) const;
};

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector2<T> operator*(const T&, const Swizzle2<T, N, E1, E2>);

}
}

#include "swizzle2.inl"

#endif
