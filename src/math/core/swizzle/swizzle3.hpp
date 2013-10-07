#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE3_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * @class Swizzle3
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : public Swizzle<T, N> {
public:
	operator Vector<T, 3>();
	Vector<T, 3>& operator=(const Vector<T, 3>&);
	Vector<T, 3> operator+(const Vector<T, 3>&) const;
	Vector<T, 3>& operator+=(const Vector<T, 3>&);
	Vector<T, 3> operator-(const Vector<T, 3>&) const;
	Vector<T, 3>& operator-=(const Vector<T, 3>&);
	Vector<T, 3> operator*(const Vector<T, 3>&) const;
	Vector<T, 3>& operator*=(const Vector<T, 3>&);
	Vector<T, 3> operator/(const Vector<T, 3>&) const;
	Vector<T, 3>& operator/=(const Vector<T, 3>&);
	bool operator==(const Vector<T, 3>&) const;
	bool operator!=(const Vector<T, 3>&) const;
	Vector<T, 3> operator/(const T&) const;
};

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Vector<T, 3> operator*(const T&, const Swizzle3<T, N, E1, E2, E3>&);

}
}

#include "swizzle3.inl"

#endif
