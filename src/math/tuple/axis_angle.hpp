#ifndef MATH_TUPLE_AXIS_ANGLE_HPP
#define MATH_TUPLE_AXIS_ANGLE_HPP

#include <tuple>

namespace math {
namespace core {

template<typename T, std::size_t N>
class Vector;

}

namespace tuple {

/**
 * @class AxisAnglePair
 * @tparam T Storage type.
 */
template<typename T>
class AxisAngle : public std::tuple<math::core::Vector<T, 3>, T> {
public:
	AxisAngle(const math::core::Vector<T, 3>&, const T&);

	math::core::Vector<T, 3> axis(void) const;
	T angle(void) const;
private:
	static const std::size_t axis_idx = 0;
	static const std::size_t angle_idx = 1;
};

}
}

#include "axis_angle.inl"

#endif
