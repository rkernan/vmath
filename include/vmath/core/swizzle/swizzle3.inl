#ifndef VMATH_CORE_SWIZZLE_SWIZZLE3_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE3_INL

#include <vmath/core/swizzle/swizzle3.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
Swizzle3<T, N, E1, E2, E3>::operator Vector<T, 3>() {
	return Vector<T, 3>(this->data[E1], this->data[E2], this->data[E3]);
}

}
}

#endif
