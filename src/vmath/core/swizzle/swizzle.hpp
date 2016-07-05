#ifndef VMATH_CORE_SWIZZLE_SWIZZLE_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE_HPP

#include <array>
#include <cstddef>
#include <type_traits>

namespace vmath {
namespace core {

/*!
 * \brief Checks that the swizzle contains unique elements and, implicitly, that it is
 *        the same size or smaller than the underlying vector
 * \tparam N Number of elements in the swizzle
 * \tparam E1 Index of first element
 * \tparam E2 Index of seconds element
 * \tparam E3 Index of third element, optional
 * \tparam E4 Index of fourth element, optional
 */
template<std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3 = 0, std::size_t E4 = 0>
struct is_assignable_swizzle : std::integral_constant<bool,
	E1 != E2 &&
	(N < 3 || (E1 != E3 && E2 != E3)) &&
	(N < 4 || (E1 != E4 && E2 != E4 && E3 != E4))> {};

/*!
 * \brief Base swizzle type
 * \tparam T Storage type
 * \tparam N Storage size
 */
template<typename T, std::size_t N>
class Swizzle {
protected:
	std::array<T, N> data;
};

}
}

#endif
