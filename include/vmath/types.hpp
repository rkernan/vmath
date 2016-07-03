#ifndef VMATH_TYPES_HPP
#define VMATH_TYPES_HPP

#include <vmath/core/Matrix.hpp>
#include <vmath/core/Quaternion.hpp>
#include <vmath/core/Vector.hpp>

namespace vmath {

typedef core::Matrix<float, 2>    Matrix2x2;
typedef core::Matrix<float, 2, 3> Matrix2x3;
typedef core::Matrix<float, 2, 4> Matrix2x4;
typedef core::Matrix<float, 3, 2> Matrix3x2;
typedef core::Matrix<float, 3>    Matrix3x3;
typedef core::Matrix<float, 3, 4> Matrix3x4;
typedef core::Matrix<float, 4, 2> Matrix4x2;
typedef core::Matrix<float, 4, 3> Matrix4x3;
typedef core::Matrix<float, 4>    Matrix4x4;
typedef Matrix2x2 Matrix2;
typedef Matrix3x3 Matrix3;
typedef Matrix4x4 Matrix4;

typedef core::Quaternion<float> Quaternion;

typedef core::Vector<float, 2> Vector2;
typedef core::Vector<float, 3> Vector3;
typedef core::Vector<float, 4> Vector4;

}

#endif
