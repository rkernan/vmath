#ifndef MATH_CORE_SWIZZLE_SWIZZLE2_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE2_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T, std::size_t N>
class Vector;

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
	operator Vector<T, 2>(void);

	Vector<T, 2>& operator=(const Vector<T, 2>&);
	Vector<T, 2> operator+(const Vector<T, 2>&) const;
	Vector<T, 2>& operator+=(const Vector<T, 2>&);
	Vector<T, 2> operator-(const Vector<T, 2>&) const;
	Vector<T, 2>& operator-=(const Vector<T, 2>&);
	Vector<T, 2> operator*(const Vector<T, 2>&) const;
	Vector<T, 2>& operator*=(const Vector<T, 2>&);
	Vector<T, 2> operator/(const Vector<T, 2>&) const;
	Vector<T, 2>& operator/=(const Vector<T, 2>&);

	Vector<T, 2> operator*(const T&) const;
	Vector<T, 2>& operator*=(const T&);
	Vector<T, 2> operator/(const T&) const;
	Vector<T, 2>& operator/=(const T&);

	bool operator==(const Vector<T, 2>&) const;
	bool operator!=(const Vector<T, 2>&) const;

#if defined(MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1(void) { return this->values[E1]; }
	T getE2(void) { return this->values[E2]; }
#endif
};

}
}

#include "swizzle2.inl"

#endif
