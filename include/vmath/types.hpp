#ifndef VMATH_TYPES_HPP
#define VMATH_TYPES_HPP

#include <vmath/core/matrix.hpp>
#include <vmath/core/quaternion.hpp>
#include <vmath/core/vector.hpp>

namespace vmath {

typedef core::matrix<float, 2>    matrix2x2;
typedef core::matrix<float, 2, 3> matrix2x3;
typedef core::matrix<float, 2, 4> matrix2x4;
typedef core::matrix<float, 3, 2> matrix3x2;
typedef core::matrix<float, 3>    matrix3x3;
typedef core::matrix<float, 3, 4> matrix3x4;
typedef core::matrix<float, 4, 2> matrix4x2;
typedef core::matrix<float, 4, 3> matrix4x3;
typedef core::matrix<float, 4>    matrix4x4;
typedef matrix2x2 matrix2;
typedef matrix3x3 matrix3;
typedef matrix4x4 matrix4;

typedef core::quaternion<float> quaternion;

typedef core::vector<float, 2> vector2;
typedef core::vector<float, 3> vector3;
typedef core::vector<float, 4> vector4;

}

#endif
