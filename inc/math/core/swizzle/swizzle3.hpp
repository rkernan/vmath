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
 * A 3-dimensional vector swizzle.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : public Swizzle<T, N> {
private:
	inline Vector<T, 3> to_vector3(void) const;
public:
	operator Vector<T, 3>(void);

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator=(const Vector<T, 3>&);

	Vector<T, 3> operator-(void) const;

	Vector<T, 3> operator+(const Vector<T, 3>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator+=(const Vector<T, 3>&);

	Vector<T, 3> operator-(const Vector<T, 3>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator-=(const Vector<T, 3>&);

	Vector<T, 3> operator*(const Vector<T, 3>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const Vector<T, 3>&);

	Vector<T, 3> operator/(const Vector<T, 3>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const Vector<T, 3>&);

	Vector<T, 3> operator*(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const T&);

	Vector<T, 3> operator/(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<3, E1, E2, E3>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const T&);

	bool operator==(const Vector<T, 3>&) const;
	bool operator!=(const Vector<T, 3>&) const;

#if defined(MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1(void) { return this->data[E1]; }
	T getE2(void) { return this->data[E2]; }
	T getE3(void) { return this->data[E3]; }
#endif
};

}
}

#include "swizzle3.inl"

#endif
