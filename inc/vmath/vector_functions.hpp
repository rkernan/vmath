#ifndef VMATH_VECTOR_FUNCTIONS_HPP
#define VMATH_VECTOR_FUNCTIONS_HPP

#include <vmath/vector.hpp>

namespace vmath {

template<typename T, std::size_t N>
Vector<T, N> lerp(const Vector<T, N>& start, const Vector<T, N>& end, const T t) {
	return start + (end - start) * t;
}

template<typename T, std::size_t N>
Vector<T, N> reflect(const Vector<T, N>& incident, const Vector<T, N>& surface_normal) {
	return incident - surface_normal * static_cast<T>(2.0) * vmath::dot(surface_normal, incident);
}

template<typename T, std::size_t N>
Vector<T, N> refract(const Vector<T, N>& incident, const Vector<T, N>& surface_normal, const T eta) {
	T s_dot_i = vmath::dot(surface_normal, incident);
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - s_dot_i * s_dot_i);
	if (k < static_cast<T>(0.0)) {
		return Vector<T, N>();
	} else {
		return incident * eta - surface_normal * (eta * s_dot_i + std::sqrt(k));
	}
}

template<typename T, std::size_t N>
bool equals(const Vector<T, N>& a, const Vector<T, N>& b) {
	return a == b;
}

} // namespace vmath

#endif
