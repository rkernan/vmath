#ifndef VMATH_CORE_SWIZZLE_SWIZZLE2_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE2_HPP

#include <vmath/core/swizzle/swizzle.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * \brief A 2-dimensional vector swizzle
 * \tparam T Storage type
 * \tparam N Storage size
 * \tparam E1 Index of first element
 * \tparam E2 Index of second element
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
class Swizzle2 : public Swizzle<T, N> {
public:
	/**
	 * \brief Construct a vector from a 2-dimensional swizzle
	 */
	operator Vector<T, 2>();

	/**
	 * \brief Copy operator
	 * \param[in] v Vector to copy
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator=(const Vector<T, 2>& v);

	/**
	 * TODO
	 */
	Vector<T, 2> operator-() const;

	/**
	 * \brief Component-wise addition assignment operator
	 * \param[in] v Vector to add
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator+=(const Vector<T, 2>& v);

	/**
	 * TODO
	 */
	Vector<T, 2> operator+(const Vector<T, 2>& v) const;

	/**
	 * \brief Component-wise subtraction assignment operator
	 * \param[in] v Vector to subtract
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator-=(const Vector<T, 2>& v);

	/**
	 * TODO
	 */
	Vector<T, 2> operator-(const Vector<T, 2>& v) const;

	/**
	 * \brief Component-wise multiplication assigment operator
	 * \param[in] v Vector to multiply
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator*=(const Vector<T, 2>& v);

	/**
	 * TODO
	 */
	Vector<T, 2> operator*(const Vector<T, 2>& v) const;

	/**
	 * \brief Component-wise division assignment operator
	 * \param[in] v Vector to divide by
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator/=(const Vector<T, 2>& v);

	/**
	 * TODO
	 */
	Vector<T, 2> operator/(const Vector<T, 2>& v) const;

	/**
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator*=(const T s);

	/**
	 * TODO
	 */
	Vector<T, 2> operator*(const T s) const;

	/**
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator/=(const T s);

	/**
	 * TODO
	 */
	Vector<T, 2> operator/(const T s) const;

#if defined(VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1() { return this->data[E1]; }
	T getE2() { return this->data[E2]; }
#endif
};

}
}

#include <vmath/core/swizzle/swizzle2.inl>

#endif
