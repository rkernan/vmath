#ifndef VMATH_CORE_SWIZZLE_SWIZZLE4_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE4_HPP

#include <vmath/core/swizzle/swizzle.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * \brief A 4-dimensional vector swizzle
 * \tparam T Storage type
 * \tparam N Storage size
 * \tparam E1 Index of first element
 * \tparam E2 Index of second element
 * \tparam E3 Index of third element
 * \tparam E4 Index of fourth element
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
class Swizzle4 : public Swizzle<T, N> {
public:
	/**
	 * \brief Contruct a vector from a 4-dimensional swizzle
	 */
	operator Vector<T, 4>();

	/**
	 * \brief Copy operator
	 * \param[in] v Vector to copy
	 * \return Reference to self converted to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator=(const Vector<T, 4>& v);

	/**
	 *
	 */
	Vector<T, 4> operator-() const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator+=(const Vector<T, 4>& v);

	/**
	 *
	 */
	Vector<T, 4> operator+(const Vector<T, 4>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator-=(const Vector<T, 4>& v);

	/**
	 *
	 */
	Vector<T, 4> operator-(const Vector<T, 4>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator*=(const Vector<T, 4>& v);

	/**
	 *
	 */
	Vector<T, 4> operator*(const Vector<T, 4>& v) const;

	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator/=(const Vector<T, 4>& v);

	/**
	 *
	 */
	Vector<T, 4> operator/(const Vector<T, 4>& v) const;
	
	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator*=(const T s);

	/**
	 *
	 */
	Vector<T, 4> operator*(const T s) const;
	
	/**
	 *
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<4, E1, E2, E3, E4>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator/=(const T s);

	/**
	 *
	 */
	Vector<T, 4> operator/(const T s) const;

#if defined(VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1() { return this->data[E1]; }
	T getE2() { return this->data[E2]; }
	T getE3() { return this->data[E3]; }
	T getE4() { return this->data[E4]; }
#endif
};

}
}

#include <vmath/core/swizzle/swizzle4.inl>

#endif
