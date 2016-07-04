#ifndef VMATH_CORE_SWIZZLE_SWIZZLE3_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE3_HPP

#include <vmath/core/swizzle/swizzle.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * \brief A 3-dimensional vector swizzle
 * \tparam T Storage type
 * \tparam N Storage size
 * \tparam E1 Index of first element
 * \tparam E2 Index of second element
 * \tparam E3 Index of third element
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : public Swizzle<T, N> {
public:
	/**
	 * \brief Construct a vector from a 3-dimensional swizzle
	 */
	operator Vector<T, 3>();

	/**
	 * \brief Copy operator
	 * \param[in] v Vector to copy
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator=(const Vector<T, 3>& v);

	/**
	 *
	 */
	Vector<T, 3> operator-() const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator+=(const Vector<T, 3>& v);

	/**
	 *
	 */
	Vector<T, 3> operator+(const Vector<T, 3>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator-=(const Vector<T, 3>& v);

	/**
	 *
	 */
	Vector<T, 3> operator-(const Vector<T, 3>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const Vector<T, 3>& v);

	/**
	 *
	 */
	Vector<T, 3> operator*(const Vector<T, 3>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const Vector<T, 3>& v);

	/**
	 *
	 */
	Vector<T, 3> operator/(const Vector<T, 3>& v) const;
	
	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const T s);

	/**
	 *
	 */
	Vector<T, 3> operator*(const T s) const;
	
	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const T s);

	/**
	 *
	 */
	Vector<T, 3> operator/(const T s) const;

#if defined(VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1() { return this->data[E1]; }
	T getE2() { return this->data[E2]; }
	T getE3() { return this->data[E3]; }
#endif
};

}
}

#include <vmath/core/swizzle/swizzle3.inl>

#endif
