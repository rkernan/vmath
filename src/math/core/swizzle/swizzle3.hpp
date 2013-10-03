#ifndef MATH_CORE_SWIZZLE_SWIZZLE3_HPP
#define  MATH_CORE_SWIZZLE_SWIZZLE3_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T>
class Vector3;

/**
 * @class Swizzle3
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3>
class Swizzle3 : Swizzle<T, N> {
public:
	operator Vector3<T>();
	Vector3<T>& operator=(const Vector3<T>&);
	Vector3<T>& operator+=(const Vector3<T>&);
	Vector3<T>& operator-=(const Vector3<T>&);
	Vector3<T>& operator*=(const Vector3<T>&);
	Vector3<T>& operator/=(const Vector3<T>&);
};

}
}

#include "swizzle3.inl"

#endif
