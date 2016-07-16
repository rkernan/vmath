#ifndef VMATH_FUNCTIONS_INL
#define VMATH_FUNCTIONS_INL

#include <vmath/functions.hpp>

#include <cmath>
#include <limits>

namespace vmath {

template<typename T, typename>
bool equals(const T a, const T b, const int ulp) {
	return std::abs(a - b) < std::numeric_limits<T>::epsilon() * std::abs(a + b) * ulp ||
	       // unless the result is sub-normal
	       std::abs(a - b) < std::numeric_limits<T>::min();
}

template<typename T, typename>
T radians(const T degrees) {
	static const T PI_OVER_180 = static_cast<T>(vmath::PI / 180.0L);
	return degrees * PI_OVER_180;
}

template<typename T, typename>
T degrees(const T radians) {
	static const T PI_UNDER_180 = static_cast<T>(180.0L / vmath::PI);
	return radians * PI_UNDER_180;
}

template<typename T, typename>
T clamp(const T s, const T lo, const T hi) {
	return (s <= lo) ? lo : ((s >= hi) ? hi : s);
}

template<typename T, typename>
T lerp(const T s, const T e, const T t) {
	return s + ((e - s) * t);
}

}

#endif
