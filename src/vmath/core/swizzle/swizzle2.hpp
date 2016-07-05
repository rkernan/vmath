#ifndef VMATH_CORE_SWIZZLE_SWIZZLE2_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE2_HPP

#include <vmath/core/swizzle/swizzle.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

/*!
 * \brief A 2-dimensional vector swizzle
 * \tparam T Storage type
 * \tparam N Storage size
 * \tparam E1 Index of first element
 * \tparam E2 Index of second element
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
class Swizzle2 : public Swizzle<T, N> {
private:
	inline Vector<T, 2> to_vector() const;
	inline Vector<T, 2>& from_vector(const Vector<T, 2> other);
public:
	/*!
	 * \brief Construct a vector from a 2-dimensional swizzle
	 */
	operator Vector<T, 2>();

	/*!
	 * \brief Copy operator
	 * \param[in] v Vector to copy
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator=(const Vector<T, 2>& v);

	/*!
	 * \brief Negation operator
	 * \return Negated vector
	 */
	Vector<T, 2> operator-() const;

	/*!
	 * \brief Component-wise addition assignment operator
	 * \param[in] v Vector to add
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator+=(const Vector<T, 2>& v);

	/*!
	 * \brief Component-wise addition operator
	 * \param[in] lhs Vector to add to
	 * \param[in] rhs Vector to add
	 * \return Component-wise sum
	 */
	friend Vector<T, 2> operator+(const Swizzle2<T, N, E1, E2>& lhs, const Vector<T, 2>& rhs) {
		return lhs.to_vector() + rhs;
	}

	/*!
	 * \brief Component-wise subtraction assignment operator
	 * \param[in] v Vector to subtract
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator-=(const Vector<T, 2>& v);

	/*!
	 * \brief Component-wise subtraction operator
	 * \param[in] rhs Vector to subtract from
	 * \param[in] lhs Vector to subtract
	 * \return Component-wise difference
	 */
	friend Vector<T, 2> operator-(const Swizzle2<T, N, E1, E2>& lhs, const Vector<T, 2>& rhs) {
		return lhs.to_vector() - rhs;
	}

	/*!
	 * \brief Component-wise multiplication assigment operator
	 * \param[in] v Vector to multiply by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator*=(const Vector<T, 2>& v);

	/*!
	 * \brief Component-wise multiplication operator
	 * \param[in] lhs Vector to multiply
	 * \param[in] rhs Vector to multiply by
	 * \return Component-wise product
	 */
	friend Vector<T, 2> operator*(const Swizzle2<T, N, E1, E2>& lhs, const Vector<T, 2>& rhs) {
		return lhs.to_vector() * rhs;
	}

	/*!
	 * \brief Component-wise division assignment operator
	 * \param[in] v Vector to divide by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator/=(const Vector<T, 2>& v);

	/*!
	 * \brief Component-wise division operator
	 * \param[in] lhs Vector to divide
	 * \param[in] rhs Vector to divide by
	 * \return Component-wise quotient
	 */
	friend Vector<T, 2> operator/(const Swizzle2<T, N, E1, E2>& lhs, const Vector<T, 2>& rhs) {
		return lhs.to_vector() / rhs;
	}

	/*!
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator*=(const T s);

	/*!
	 * \brief Scalar multiplication operator
	 * \param[in] v Vector to multiply
	 * \param[in] s Scalar to multiply by
	 * \return Vector-scalar product
	 */
	friend Vector<T, 2> operator*(const Swizzle2<T, N, E1, E2>& v, const T s) {
		return v.to_vector() * s;
	}

	/*!
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<2, E1, E2>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 2>& operator/=(const T s);

	/*!
	 * \brief Scalar division operator
	 * \param[in] v Vector to divide
	 * \param[in] s Scalar to divide by
	 * \return Vector-scalar quotient
	 */
	friend Vector<T, 2> operator/(const Swizzle2<T, N, E1, E2>& v, const T s) {
		return v.to_vector() / s;
	}

#if defined(VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1() { return this->data[E1]; }
	T getE2() { return this->data[E2]; }
#endif
};

}
}

#include <vmath/core/swizzle/swizzle2.inl>

#endif
