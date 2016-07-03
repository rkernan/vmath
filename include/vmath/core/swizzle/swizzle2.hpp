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

#if defined(VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1() { return this->data[E1]; }
	T getE2() { return this->data[E2]; }
#endif
};

}
}

#include <vmath/core/swizzle/swizzle2.inl>

#endif
