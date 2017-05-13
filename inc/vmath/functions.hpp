#ifndef VMATH_FUNCIONS_HPP
#define VMATH_FUNCIONS_HPP

#include <cmath>
#include <type_traits>

namespace vmath {

const long double PI = std::acos(-1.0L);

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
bool equals(const T& a, const T& b) {
	return std::fabs(a - b) < std::numeric_limits<T>::epsilon() * std::fabs(a + b) * std::fmax(a, b) ||
	       // unless the result is sub-normal
	       std::fabs(a - b) < (std::numeric_limits<T>::min)(); // NOTE: parens around min() to prevent collision with windows.h min macro
}

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T radians(const T& degrees) {
	static const T PI_OVER_180 = static_cast<T>(vmath::PI / 180.0L);
	return degrees * PI_OVER_180;
}

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T degrees(const T& radians) {
	static const T PI_UNDER_180 = static_cast<T>(180.0L / vmath::PI);
	return radians * PI_UNDER_180;

}

template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T lerp(const T& s, const T& e, const T& t) {
	return s + ((e - s) * t);
}

// TODO C++17 is adding std::clamp!
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T clamp(const T& s, const T& lo, const T& hi) {
	return (s <= lo) ? lo : ((s >= hi) ? hi : s);
}

} // namespace vmath

#endif
