#ifndef MATH_FUNC_HPP
#define MATH_FUNC_HPP

#include <type_traits>

namespace math {

extern const long double PI;

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type equals(const T&, const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type equals(const T&, const T&, const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type radians(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type degrees(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type cos(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type sin(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type tan(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type acos(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type asin(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type atan(const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type atan2(const T&, const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type pow(const T&, const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type sqrt(const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type ceil(const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type floor(const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type round(const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type trunc(const T&);

template<typename T> 
typename std::enable_if<std::is_arithmetic<T>::value, T>::type clamp(const T&, const T&, const T&);

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type abs(const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type copysign(const T&, const T&);

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type copysign(const T&, const T&);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type lerp(const T&, const T&, const T&);

}

#include "func.inl"

#endif
