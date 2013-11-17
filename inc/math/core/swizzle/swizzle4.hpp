#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE4_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T, std::size_t N>
class Vector;

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
class Swizzle4 : public Swizzle<T, N> {
public:
	operator Vector<T, 4>();
	Vector<T, 4>& operator=(const Vector<T, 4>&);
	Vector<T, 4> operator+(const Vector<T, 4>&) const;
	Vector<T, 4>& operator+=(const Vector<T, 4>&);
	Vector<T, 4> operator-(const Vector<T, 4>&) const;
	Vector<T, 4>& operator-=(const Vector<T, 4>&);
	Vector<T, 4> operator*(const Vector<T, 4>&) const;
	Vector<T, 4>& operator*=(const Vector<T, 4>&);
	Vector<T, 4> operator/(const Vector<T, 4>&) const;
	Vector<T, 4>& operator/=(const Vector<T, 4>&);
	bool operator==(const Vector<T, 4>&) const;
	bool operator!=(const Vector<T, 4>&) const;
	Vector<T, 4> operator/(const T&) const;
};

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
Vector<T, 4> operator*(const T&, const Swizzle4<T, N, E1, E2, E3, E4>);

}
}

#include "swizzle4.inl"

#endif
