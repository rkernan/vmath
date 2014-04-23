#ifndef MATH_CORE_SWIZZLE_SWIZZLE2_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE2_HPP

#include <type_traits>

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T, std::size_t N>
class vector;

/**
 * A 2-dimensional vector swizzle.
 * @class swizzle2
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
class swizzle2 : public swizzle<T, N> {
private:
	inline vector<T, 2> to_vector2(void) const;
public:
	operator vector<T, 2>(void);

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator=(const vector<T, 2>&);

	vector<T, 2> operator-(void) const;

	vector<T, 2> operator+(const vector<T, 2>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator+=(const vector<T, 2>&);

	vector<T, 2> operator-(const vector<T, 2>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator-=(const vector<T, 2>&);

	vector<T, 2> operator*(const vector<T, 2>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator*=(const vector<T, 2>&);

	vector<T, 2> operator/(const vector<T, 2>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator/=(const vector<T, 2>&);

	vector<T, 2> operator*(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator*=(const T&);

	vector<T, 2> operator/(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<2, E1, E2>::value
		&& std::is_same<T, U>::value, U>::type>
	vector<T, 2>& operator/=(const T&);

	bool operator==(const vector<T, 2>&) const;
	bool operator!=(const vector<T, 2>&) const;

#if defined(MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1(void) { return this->data[E1]; }
	T getE2(void) { return this->data[E2]; }
#endif
};

}
}

#include "swizzle2.inl"

#endif
