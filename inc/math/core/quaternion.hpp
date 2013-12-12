#ifndef MATH_CORE_QUATERNION_HPP
#define MATH_CORE_QUATERNION_HPP

#include <cstddef>
#include <ostream>

#include "vector.hpp"

namespace math {

namespace tuple {

template<typename T>
class EulerAngles;

template<typename T>
class AxisAngle;

}

namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * @class Quaternion
 * @tparam T Storage type.
 * A quaternion rotation.
 */
template<typename T>
class Quaternion : public Vector<T, 4> {
public:
	using Vector<T, 4>::Vector;

	Quaternion(void) : Vector<T, 4>() {}
	Quaternion(const Vector<T, 4>& V) : Vector<T, 4>(V) {}

	Quaternion(const math::tuple::AxisAngle<T>&);
	Quaternion(const math::tuple::EulerAngles<T>&);

	Quaternion<T> inverse(void) const;
	Quaternion<T>& invert(void);

	math::tuple::EulerAngles<T> eulerAngles(void) const;
	math::tuple::AxisAngle<T> axisAngle(void) const;

	static Quaternion<T> slerp(const Quaternion<T>&, const Quaternion<T>&, const T&, const bool=false);
};

}
}

#include "quaternion.inl"

#endif
