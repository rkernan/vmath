#ifndef VMATH_VECTOR_HPP
#define VMATH_VECTOR_HPP

#include <array>
#include <cstddef>

namespace vmath {

/*!
 * Vector of generic length
 */
template<typename T, std::size_t N>
class Vector {
public:
	std::array<T, N> data;
};

} // namespace vmath

#endif
