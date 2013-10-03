#ifndef MATH_CORE_SWIZZLE_SWIZZLE_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE_HPP

#include <cstddef>

namespace math {
namespace core {

/**
 * @class Swizzle
 * @tparam T Storage type.
 * @tparam N Storage size.
 */
template<typename T, std::size_t N>
class Swizzle {
protected:
	T values[N];
};

}
}

#endif
