#ifndef VMATH_FUNCTIONS_INL
#define VMATH_FUNCTIONS_INL

#include <vmath/functions.hpp>

#include <cmath>

namespace vmath {

/**
 * Determine if two floats are equivalent within a default tolerance.
 * @param a Float to compare.
 * @param b Float to compare.
 * @return True if they are equivalent, otherwise false.
 */
template<typename T, typename>
bool equals(const T a, const T b) {
	static const T epsilon = static_cast<T>(0.00001L);
	return vmath::equals<T>(a, b, epsilon);
}

/**
 * Determine if two float are equivalent within a given tolerance.
 * @param a Float to compare.
 * @param b Float to compare.
 * @param epsilon Tolerance to compare with. Defaults to 0.00001.
 * @return True if they are equivalent, otherwise false.
 */
template<typename T, typename>
bool equals(const T a, const T b, const T epsilon) {
	// TODO This breaks with certain edge cases.
	return vmath::abs(a - b) < epsilon;
}

/**
 * Convert degrees to radians.
 * @param degrees Degrees to convert.
 * @return The given degrees in radians.
 */
template<typename T, typename>
T radians(const T degrees) {
	static const T PI_OVER_180 = static_cast<T>(vmath::PI / 180.0L);
	return degrees * PI_OVER_180;
}

/**
 * Convert radians to degrees.
 * @param radians Radians to convert.
 * @return The given radians in degrees.
 */
template<typename T, typename>
T degrees(const T radians) {
	static const T PI_UNDER_180 = static_cast<T>(180.0L / vmath::PI);
	return radians * PI_UNDER_180;
}

/**
 * Cosing function.
 * @param s Scalar (in radians) to find cosine of.
 * @return Cosine.
 */
template<typename T, typename>
T cos(const T s) {
	return std::cos(s);
}

/**
 * Sine function.
 * @param s Scalar (in radians) to find sine of.
 * @return Sine.
 */
template<typename T, typename>
T sin(const T s) {
	return std::sin(s);
}

/**
 * Tangent function.
 * @param s Scalar (in radians) to find tangent of.
 * @return Tangent.
 */
template<typename T, typename>
T tan(const T s) {
	return std::tan(s);
}

/**
 * Arccosine function.
 * @param s Scalar (in radians) to find arccosine of.
 * @return Arccosine.
 */
template<typename T, typename>
T acos(const T s) {
	return std::acos(s);
}

/**
 * Arcsine function.
 * @param s Scalar (in radians) to find arcsine of.
 * @return Arcsine.
 */
template<typename T, typename>
T asin(const T s) {
	return std::asin(s);
}

/**
 * Arctangent function.
 * @param s Scalar (in radians) to find arctangent of.
 * @return Arctangent.
 */
template<typename T, typename>
T atan(const T s) {
	return std::atan(s);
}

/**
 * Arctangent function with two arguments.
 * @param y Y-coordinate (in radians).
 * @param x X-coordinate (in radians).
 * @return The angle in radians between the given point and the positive x-axis.
 */
template<typename T, typename>
T atan2(const T y, const T x) {
	// TODO When y = x = 0 a domain error occurs.
	return std::atan2(y, x);
}

/**
 * Power function.
 * @param s Scalar.
 * @param e Exponent.
 * @return Scalar to the exponent.
 */
template<typename T, typename>
T pow(const T s, const T e) {
	return std::pow(s, e);
}

/**
 * Square root function.
 * @param s Scalar to find square root of.
 * @return Square root of the scalar.
 */
template<typename T, typename>
T sqrt(const T s) {
	return std::sqrt(s);
}

/**
 * Round up to the nearest whole number.
 * @param s Scalar to round.
 * @return Rounded scalar.
 */
template<typename T, typename>
T ceil(const T s) {
	return std::ceil(s);
}

/**
 * Round down to the nearest whole number.
 * @param s Scalar to round.
 * @return Rounded scalar.
 */
template<typename T, typename>
T floor(const T s) {
	return std::floor(s);
}

/**
 * Round to the nearest whole number. Rounds away from zero.
 * @param s Scalar to round.
 * @return Rounded scalar.
 */
template<typename T, typename>
T round(const T s) {
	return (s < static_cast<T>(0.0L)) ? vmath::ceil(s - static_cast<T>(0.5L)) : vmath::floor(s + static_cast<T>(0.5L));
}

/**
 * Truncate the decimal points.
 * @param s Scalar to truncate.
 * @return Truncated scalar.
 */
template<typename T, typename>
T trunc(const T s) {
	return (s < static_cast<T>(0.0L)) ? vmath::ceil(s) : vmath::floor(s);
}

/**
 * Clamp into a range.
 * @param s Scalar to clamp.
 * @param lo Lowest number included in the range.
 * @param hi Highest number included in the range.
 * @return Clamped scalar.
 */
template<typename T, typename>
T clamp(const T s, const T lo, const T hi) {
	return (s <= lo) ? lo : ((s >= hi) ? hi : s);
}

/**
 * Absolute value.
 * @param s Scalar to get absolute value of.
 * @return Absolute value of scalar.
 */
template<typename T, typename>
T abs(const T s) {
	return (s < static_cast<T>(0.0L)) ? -s : s;
}

/**
 * Copy the magnitude of the first element and the sign of the second.
 * @param x Magnitude to use.
 * @param y Sign to use. If zero, returns 0.
 * @return Number with the given magnitude and sign.
 */
template<typename T, typename>
T copysign(const T x, const T y) {
	if (vmath::equals(y, static_cast<T>(0.0L))) {
		return static_cast<T>(0.0L);
	} else {
#if defined(_WIN32)
		return static_cast<T>(copysign(
			static_cast<long double>(x), static_cast<long double>(y)));
#else
		return std::copysign(x, y);
#endif
	}
}

/**
 * Linearly interpolate scalars.
 * @param s Start value.
 * @param e End value.
 * @param t Amound to interpolate by.
 * @return Interpolated scalar.
 */
template<typename T, typename>
T lerp(const T s, const T e, const T t) {
	return s + ((e - s) * t);
}

/**
 * Find the max of two scalars.
 * @param a First scalar.
 * @param b Second scalar.
 * @return The max of a and b.
 */
template<typename T, typename>
T max(const T a, const T b) {
	return (a > b) ? a : b;
}

/**
 * Find the min of two scalars.
 * @param a First scalar.
 * @param b Second scalar.
 * @return the min of a and b.
 */
template<typename T, typename>
T min(const T a, const T b) {
	return (a < b) ? a : b;
}

}

#endif
