#define VMATH_HEADER_ONLY
#include <vmath/core/matrix.hpp>
#include <vmath/core/quaternion.hpp>
#include <vmath/core/vector.hpp>

template class vmath::core::Matrix<float, 2>;
template class vmath::core::Matrix<float, 2, 3>;
template class vmath::core::Matrix<float, 2, 4>;
template class vmath::core::Matrix<float, 3, 2>;
template class vmath::core::Matrix<float, 3>;
template class vmath::core::Matrix<float, 3, 4>;
template class vmath::core::Matrix<float, 4, 2>;
template class vmath::core::Matrix<float, 4, 3>;
template class vmath::core::Matrix<float, 4>;
template class vmath::core::Matrix<double, 2>;
template class vmath::core::Matrix<double, 2, 3>;
template class vmath::core::Matrix<double, 2, 4>;
template class vmath::core::Matrix<double, 3, 2>;
template class vmath::core::Matrix<double, 3>;
template class vmath::core::Matrix<double, 3, 4>;
template class vmath::core::Matrix<double, 4, 2>;
template class vmath::core::Matrix<double, 4, 3>;
template class vmath::core::Matrix<double, 4>;
template class vmath::core::Matrix<long double, 2>;
template class vmath::core::Matrix<long double, 2, 3>;
template class vmath::core::Matrix<long double, 2, 4>;
template class vmath::core::Matrix<long double, 3, 2>;
template class vmath::core::Matrix<long double, 3>;
template class vmath::core::Matrix<long double, 3, 4>;
template class vmath::core::Matrix<long double, 4, 2>;
template class vmath::core::Matrix<long double, 4, 3>;
template class vmath::core::Matrix<long double, 4>;

template class vmath::core::Quaternion<float>;
template class vmath::core::Quaternion<double>;
template class vmath::core::Quaternion<long double>;

template class vmath::core::Vector<float, 2>;
template class vmath::core::Vector<float, 3>;
template class vmath::core::Vector<float, 4>;
template class vmath::core::Vector<double, 2>;
template class vmath::core::Vector<double, 3>;
template class vmath::core::Vector<double, 4>;
template class vmath::core::Vector<long double, 2>;
template class vmath::core::Vector<long double, 3>;
template class vmath::core::Vector<long double, 4>;
template class vmath::core::Vector<bool, 2>;
template class vmath::core::Vector<bool, 3>;
template class vmath::core::Vector<bool, 4>;
template class vmath::core::Vector<int, 2>;
template class vmath::core::Vector<int, 3>;
template class vmath::core::Vector<int, 4>;
template class vmath::core::Vector<unsigned int, 2>;
template class vmath::core::Vector<unsigned int, 3>;
template class vmath::core::Vector<unsigned int, 4>;
