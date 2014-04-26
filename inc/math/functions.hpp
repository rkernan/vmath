#ifndef MATH_FUNCIONS_HPP
#define MATH_FUNCIONS_HPP

#include <cmath>
#include <type_traits>

namespace math {

const long double PI = std::acos(-1.0L);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
bool equals(const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
bool equals(const T, const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T radians(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T degrees(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T cos(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T sin(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T tan(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T acos(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T asin(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T atan(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T atan2(const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T pow(const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T sqrt(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T ceil(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T floor(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T round(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T trunc(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T clamp(const T, const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T abs(const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T copysign(const T, const T);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
T lerp(const T, const T, const T);

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
T max(const T, const T);

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
T min(const T, const T);

}

#include <math/functions.inl>

#endif
