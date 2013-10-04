#ifndef MATH_TYPES_HPP
#define MATH_TYPES_HPP

#include "core/matrix2x2.hpp"
#include "core/matrix2x3.hpp"
#include "core/matrix2x4.hpp"
#include "core/matrix3x2.hpp"
#include "core/matrix3x3.hpp"
#include "core/matrix3x4.hpp"
#include "core/matrix4x2.hpp"
#include "core/matrix4x3.hpp"
#include "core/matrix4x4.hpp"
#include "core/quaternion.hpp"
#include "core/vector2.hpp"
#include "core/vector3.hpp"
#include "core/vector4.hpp"

namespace math {

typedef core::Matrix2x2<float> Matrix2x2;
typedef core::Matrix2x3<float> Matrix2x3;
typedef core::Matrix2x4<float> Matrix2x4;
typedef core::Matrix3x2<float> Matrix3x2;
typedef core::Matrix3x3<float> Matrix3x3;
typedef core::Matrix3x4<float> Matrix3x4;
typedef core::Matrix4x2<float> Matrix4x2;
typedef core::Matrix4x3<float> Matrix4x3;
typedef core::Matrix4x4<float> Matrix4x4;

typedef Matrix2x2 Matrix2;
typedef Matrix3x3 Matrix3;
typedef Matrix4x4 Matrix4;

typedef core::Quaternion<float> Quaternion;

typedef core::Vector2<float> Vector2;
typedef core::Vector3<float> Vector3;
typedef core::Vector4<float> Vector4;

}

#endif
