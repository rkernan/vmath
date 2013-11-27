#ifndef MATH_TUPLE_EULER_HPP
#define MATH_TUPLE_EULER_HPP

#include <tuple>

namespace math {
namespace tuple {

/**
 * @class EulerAngles
 * @tparam T Storage type.
 */
template<typename T>
class EulerAngles : public std::tuple<T, T, T> {
public:
	EulerAngles(const T&, const T&, const T&);

	EulerAngles(const EulerAngles<T>&) = default;
	EulerAngles(EulerAngles<T>&&) = default;

	~EulerAngles(void) = default;

	T pitch(void) const;
	T yaw(void) const;
	T roll(void) const;

private:
	static const std::size_t pitch_idx = 0;
	static const std::size_t yaw_idx = 1;
	static const std::size_t roll_idx = 2;
};

}
}

#include "euler.inl"

#endif
