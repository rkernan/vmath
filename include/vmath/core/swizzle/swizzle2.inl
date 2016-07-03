#ifndef VMATH_CORE_SWIZZLE_SWIZZLE2_INL
#define VMATH_CORE_SWIZZLE_SWIZZLE2_INL

#include <vmath/core/swizzle/swizzle2.hpp>

#include <vmath/core/vector.hpp>

namespace vmath {
namespace core {

template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator Vector<T, 2>() {
	return Vector<T, 2>(this->data[E1], this->data[E2]);
}

}
}

#endif
