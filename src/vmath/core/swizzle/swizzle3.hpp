#ifndef VMATH_CORE_SWIZZLE_SWIZZLE3_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE3_HPP

#include <vmath/core/swizzle/swizzle.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

/*!
 * \brief A 3-dimensional vector swizzle
 * \tparam T Storage type
 * \tparam N Storage size
 * \tparam E1 Index of first element
 * \tparam E2 Index of second element
 * \tparam E3 Index of third element
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : public Swizzle<T, N> {
private:
	inline Vector<T, 3> to_vector() const;
	inline Vector<T, 3>& from_vector(const Vector<T, 3> other);
public:
	/*!
	 * \brief Construct a vector from a 3-dimensional swizzle
	 */
	operator Vector<T, 3>();

	/*!
	 * \brief Copy operator
	 * \param[in] v Vector to copy
	 * \return Reference to self cast to a vector
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator=(const Vector<T, 3>& v);

	/*!
	 * \brief Negation operator
	 * \return Negated vector
	 */
	Vector<T, 3> operator-() const;

	/*!
	 * \brief Component-wise addition assignment operator
	 * \param[in] v Vector to add
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator+=(const Vector<T, 3>& v);

	/*!
	 * \brief Component-wise addition operator
	 * \param[in] lhs Vector to add to
	 * \param[in] rhs Vector to add
	 * \return Component-wise sum
	 */
	friend Vector<T, 3> operator+(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return lhs.to_vector() + rhs;
	}

	/*!
	 * \brief Component-wise subtraction assignment operator
	 * \param[in] v Vector to subtract
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator-=(const Vector<T, 3>& v);

	/*!
	 * \brief Component-wise subtraction operator
	 * \param[in] lhs Vector to subtract from
	 * \param[in] rhs Vector to subtract
	 * \return Component-wise difference
	 */
	friend Vector<T, 3> operator-(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return lhs.to_vector() - rhs;
	}

	/*!
	 * \brief Component-wise multiplication assignment operator
	 * \param[in] v Vector to multiply by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const Vector<T, 3>& v);

	/*!
	 * \brief Component-wise multiplication operator
	 * \param[in] lhs Vector to multiply
	 * \param[in] rhs Vector to multiply by
	 * \return Component-wise product
	 */
	friend Vector<T, 3> operator*(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return lhs.to_vector() * rhs;
	}

	/*!
	 * \brief Component-wise division assignment operator
	 * \param[in] v Vector to divide by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const Vector<T, 3>& v);

	/*!
	 * \brief Component-wise division operator
	 * \param[in] lhs Vector to divide
	 * \param[in] rhs Vector to divide by
	 * \return Component-wise quotient
	 */
	friend Vector<T, 3> operator/(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return lhs.to_vector() / rhs;
	}
	
	/*!
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator*=(const T s);

	/*!
	 * \brief Scalar multiplication operator
	 * \param[in] v Vector to multiply
	 * \param[in] s Scalar to multiply by
	 * \return Vector-scalar product
	 */
	friend Vector<T, 3> operator*(const Swizzle3<T, N, E1, E2, E3>& v, const T s) {
		return v.to_vector() * s;
	}
	
	/*!
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self
	 */
	template<typename U = T, typename = typename std::enable_if<
		is_assignable_swizzle<3, E1, E2, E3>::value &&
		std::is_same<T, U>::value>::type>
	Vector<T, 3>& operator/=(const T s);

	/*!
	 * \brief Scalar division operator
	 * \param[in] v Vector to divide
	 * \param[in] s Scalar to divide by
	 * \return Vector-scalar quotient
	 */
	friend Vector<T, 3> operator/(const Swizzle3<T, N, E1, E2, E3>& v, const T s) {
		return v.to_vector() / s;
	}

	/*!
	 * \brief Check vector equality
	 * \param[in] other Vector to check equality with
	 * \return True if equal, else false
	 */
	bool equals(const Vector<T, 3>& other) const;

	/*!
	 * \brief Check vector equality
	 * \param[in] other Vector to check equality with
	 * \param[in] ulp The desired floating point precision in ULPs
	 * \return True if equal, else false
	 */
	template<typename U = T, typename = typename std::enable_if<std::is_floating_point<U>::value>::type>
	bool equals(const Vector<T, 3>& other, const int ulp) const;

	/*!
	 * \brief Equality operator
	 * \param[in] lhs Vector to check equality
	 * \param[in] rhs Vector to check equality with
	 * \return True if equal, else false
	 */
	friend bool operator==(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return lhs.equals(rhs);
	}

	/*!
	 * \brief Inequality operator
	 * \param[in] lhs Vector to check inequality
	 * \param[in] rhs Vector to check inequality with
	 * \return False if equal, else true
	 */
	friend bool operator!=(const Swizzle3<T, N, E1, E2, E3>& lhs, const Vector<T, 3>& rhs) {
		return !lhs.equals(rhs);
	}

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
