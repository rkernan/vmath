#ifndef VMATH_HPP
#define VMATH_HPP

#include <vmath/functions.hpp>
#include <vmath/matrix2.hpp>
#include <vmath/matrix2x3.hpp>
#include <vmath/matrix2x4.hpp>
#include <vmath/matrix3.hpp>
#include <vmath/matrix3x2.hpp>
#include <vmath/matrix3x4.hpp>
#include <vmath/matrix4.hpp>
#include <vmath/matrix4x2.hpp>
#include <vmath/matrix4x3.hpp>
#include <vmath/matrix_functions.hpp>
#include <vmath/quaternion.hpp>
#include <vmath/quaternion_functions.hpp>
#include <vmath/vector2.hpp>
#include <vmath/vector3.hpp>
#include <vmath/vector4.hpp>
#include <vmath/vector_functions.hpp>

namespace vmath {

typedef Matrix<float, 2, 2> Matrix2x2;
typedef Matrix<float, 2, 3> Matrix2x3;
typedef Matrix<float, 2, 4> Matrix2x4;
typedef Matrix<float, 3, 2> Matrix3x2;
typedef Matrix<float, 3, 3> Matrix3x3;
typedef Matrix<float, 3, 4> Matrix3x4;
typedef Matrix<float, 4, 2> Matrix4x2;
typedef Matrix<float, 4, 3> Matrix4x3;
typedef Matrix<float, 4, 4> Matrix4x4;
typedef Matrix2x2 Matrix2;
typedef Matrix3x3 Matrix3;
typedef Matrix4x4 Matrix4;

typedef Quaternion<float> Quaternion;

typedef Vector<float, 2> Vector2;
typedef Vector<float, 3> Vector2;
typedef Vector<float, 4> Vector2;

} // namespace vmath

#endif
