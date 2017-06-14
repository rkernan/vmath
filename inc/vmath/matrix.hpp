#ifndef VMATH_MATRIX_HPP
#define VMATH_MATRIX_HPP

#include <vmath/vector.hpp>

namespace vmath {

/**
 * Column-major generic matrix
 */
template<typename T, std::size_t M, std::size_t N>
class Matrix {
public:
	std::array<Vector<T, M>, N> data;
};

} // namespace vmath

#endif
