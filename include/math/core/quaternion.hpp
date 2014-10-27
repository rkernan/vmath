#ifndef MATH_CORE_QUATERNION_HPP
#define MATH_CORE_QUATERNION_HPP

#include <array>
#include <cstddef>

namespace math {
namespace core {

template<typename T, std::size_t N>
class vector;

template<typename T, std::size_t M, std::size_t N>
class matrix;

/**
 * A quaternion rotation.
 * @class quaternion
 * @tparam T Storage type.
 */
template<typename T>
class quaternion {
public:
	quaternion(void) : x(), y(), z(), w() {}
	quaternion(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	quaternion(const T&, const T&, const T&);
	quaternion(const vector<T, 3>&, const T&);
	explicit quaternion(const matrix<T, 4, 4>&);
	quaternion(const quaternion&) = default;
	quaternion<T>& operator=(const quaternion<T>&) = default;
	quaternion(quaternion&&) = default;

	~quaternion(void) = default;


	T operator[](const std::size_t) const;
	T& operator[](const std::size_t);

	quaternion<T> operator-(void) const;

	quaternion<T> operator+(const quaternion<T>&) const;
	quaternion<T>& operator+=(const quaternion<T>&);
	quaternion<T> operator-(const quaternion<T>&) const;
	quaternion<T>& operator-=(const quaternion<T>&);

	quaternion<T> operator*(const quaternion<T>&) const;
	quaternion<T>& operator*=(const quaternion<T>&);

	vector<T, 3> operator*(const vector<T, 3>&) const;

	quaternion<T> operator*(const T&) const;
	quaternion<T>& operator*=(const T&);
	quaternion<T> operator/(const T&) const;
	quaternion<T>& operator/=(const T&);

	T mag2(void) const;
	T mag(void) const;

	quaternion<T> normal(void) const;
	quaternion<T>& normalize(void);

	quaternion<T> inverse(void) const;
	quaternion<T>& invert(void);

	T pitch(void) const;
	T yaw(void) const;
	T roll(void) const;

	vector<T, 3> axis(void) const;
	T angle(void) const;

	matrix<T, 4, 4> to_matrix(void) const;

	bool operator==(const quaternion<T>&) const;
	bool operator!=(const quaternion<T>&) const;

	static T dot(const quaternion<T>&, const quaternion<T>&);

	static quaternion<T> lerp(const quaternion<T>&, const quaternion<T>&, const T&);
	static quaternion<T> slerp(const quaternion<T>&, const quaternion<T>&, const T&, const bool = false);

	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
	};
};

}
}

#include <math/core/quaternion.inl>

#endif
