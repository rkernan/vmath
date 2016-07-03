#ifndef VMATH_GLSL_TYPES_HPP
#define VMATH_GLSL_TYPES_HPP

#include <vmath/core/Matrix.hpp>
#include <vmath/core/Vector.hpp>

namespace vmath {

// TODO quaternion typedef

typedef core::Matrix<float, 2>    mat2x2;
typedef core::Matrix<float, 2, 3> mat2x3;
typedef core::Matrix<float, 2, 4> mat2x4;
typedef core::Matrix<float, 3, 2> mat3x2;
typedef core::Matrix<float, 3>    mat3x3;
typedef core::Matrix<float, 3, 4> mat3x4;
typedef core::Matrix<float, 4, 2> mat4x2;
typedef core::Matrix<float, 4, 3> mat4x3;
typedef core::Matrix<float, 4>    mat4x4;
typedef mat2x2 mat2;
typedef mat3x3 mat3;
typedef mat4x4 mat4;

typedef core::Matrix<double, 2>    dmat2x2;
typedef core::Matrix<double, 2, 3> dmat2x3;
typedef core::Matrix<double, 2, 4> dmat2x4;
typedef core::Matrix<double, 3, 2> dmat3x2;
typedef core::Matrix<double, 3>    dmat3x3;
typedef core::Matrix<double, 3, 4> dmat3x4;
typedef core::Matrix<double, 4, 2> dmat4x2;
typedef core::Matrix<double, 4, 3> dmat4x3;
typedef core::Matrix<double, 4>    dmat4x4;
typedef dmat2x2 dmat2;
typedef dmat3x3 dmat3;
typedef dmat4x4 dmat4;

typedef core::Vector<float, 2> vec2;
typedef core::Vector<float, 3> vec3;
typedef core::Vector<float, 4> vec4;

typedef core::Vector<double, 2> dvec2;
typedef core::Vector<double, 3> dvec3;
typedef core::Vector<double, 4> dvec4;

typedef core::Vector<bool, 2> bvec2;
typedef core::Vector<bool, 3> bvec3;
typedef core::Vector<bool, 4> bvec4;

typedef core::Vector<int, 2> ivec2;
typedef core::Vector<int, 3> ivec3;
typedef core::Vector<int, 4> ivec4;

typedef core::Vector<unsigned int, 2> uvec2;
typedef core::Vector<unsigned int, 3> uvec3;
typedef core::Vector<unsigned int, 4> uvec4;

}

#endif
