#ifndef MATH_TUPLE_AXIS_ANGLE_HPP
#define MATH_TUPLE_AXIS_ANGLE_HPP

#include <tuple>

namespace math {
namespace core {

template<typename T>
class Vector3;

}

namespace tuple {

/**
 * @class AxisAnglePair
 * @tparam T Storage type.
 */
template<typename T>
class AxisAngle : public std::tuple<math::core::Vector3<T>, T> {
public:
	AxisAngle(const math::core::Vector3<T>&, const T&);

	math::core::Vector3<T> axis(void) const;
	T angle(void) const;
private:
	static const std::size_t axis_idx = 0;
	static const std::size_t angle_idx = 1;
};

}
}

#include "axis_angle.inl"

#endif
