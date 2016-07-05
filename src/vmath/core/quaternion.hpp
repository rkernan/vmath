#ifndef VMATH_CORE_QUATERNION_HPP
#define VMATH_CORE_QUATERNION_HPP

#include <array>
#include <cstddef>

namespace vmath {
namespace core {

template<typename T, std::size_t N>
class Vector;

template<typename T, std::size_t M, std::size_t N>
class Matrix;

/*!
 * \brief A quaternion rotation
 * \tparam T Storage type
 */
template<typename T>
class Quaternion {
public:
	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
	};

	/*!
	 * \brief Construct a zero quaternion
	 */
	Quaternion() : x(), y(), z(), w() {}

	/*!
	 * \brief Construct a quaternion by value
	 * \param[in] x X coordinate value
	 * \param[in] y Y coordinate value
	 * \param[in] z Z coordinate value
	 * \param[in] w W coordinate value
	 */
	Quaternion(const T x, const T y, const T z, const T w) : x(x), y(y), z(z), w(w) {}

	/*!
	 * \brief Construct a quaternion from euler angles
	 * \param[in] pitch Counter-clockwise x-axis rotation in radians
	 * \param[in] yaw Counter-clockwise y-axis rotation in radians
	 * \param[in] roll Counter-clockwise z-axis rotation in radians
	 */
	Quaternion(const T pitch, const T yaw, const T roll);

	/*!
	 * \brief Construct a quaternion from an axis and angle
	 * \param[in] axis Axis of rotation
	 * \param[in] angle Angle of rotation in radians
	 */
	Quaternion(const Vector<T, 3>& axis, const T angle);

	/*!
	 * \brief Construct a quaternion from a rotation Matrix
	 * \param[in] mat Matrix to convert
	 */
	explicit Quaternion(const Matrix<T, 4, 4>& mat);

	/*!
	 * \brief Copy constructor
	 * \param[in] other Quaternion to copy
	 */
	Quaternion(const Quaternion& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other Quaternion to copy
	 * \return Reference to self
	 */
	Quaternion<T>& operator=(const Quaternion<T>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other Quaternion to move
	 * \return Reference to self
	 */
	Quaternion(Quaternion&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other Quaternion to move
	 * \return Reference to self
	 */
	Quaternion<T>& operator=(Quaternion<T>&& other) = default;

	/*!
	 * \brief Destructor
	 */
	~Quaternion() = default;

	/*!
	 * \brief Access a quaternion element by index
	 * \param[in] idx Index of element
	 * \return Accessed element
	 */
	T operator[](const std::size_t idx) const;

	/*!
	 * \brief Access and modify a quaternion element by index
	 * \param[in] idx Location of element
	 * \return Modified element
	 */
	T& operator[](const std::size_t idx);

	/*!
	 * \brief Negate a quaternion
	 * \return Quaternion negated
	 */
	Quaternion<T> operator-() const;

	/*!
	 * \brief Component-wise addition operator with assignment
	 * \param[in] h Quaternion to add
	 * \return Reference to self
	 */
	Quaternion<T>& operator+=(const Quaternion<T>& h);

	/*!
	 * \brief Component-wise addition operator
	 * \param[in] lhs Quaternion to add to
	 * \param[in] rhs Quaternion to add
	 * \return Component-wise sum
	 */
	friend Quaternion<T> operator+(Quaternion<T> lhs, const Quaternion<T>& rhs) {
		lhs += rhs;
		return lhs;
	}

	/*!
	 * \brief Component-wise subtraction operator with assignment
	 * \param[in] h Quaternion to subtract
	 * \return Reference to self
	 */
	Quaternion<T>& operator-=(const Quaternion<T>& h);

	/*!
	 * \brief Component-wise subtraction operator
	 * \param[in] lhs Quaternion to subtract from
	 * \param[in] rhs Quaternion to subtract
	 * \return Component-wise difference
	 */
	friend Quaternion<T> operator-(Quaternion<T> lhs, const Quaternion<T>& rhs) {
		lhs -= rhs;
		return lhs;
	}

	/*!
	 * \brief Quaternion multiplication assignment operator
	 * \param[in] h Quaternion to multiply by
	 * \return Reference to this
	 *
	 * Combines this Quaternion with another.
	 */
	Quaternion<T>& operator*=(const Quaternion<T>& h);

	/*!
	 * \brief Component-wise subtraction operator
	 * \param[in] lhs Quaternion to multiply
	 * \param[in] rhs Quaternion to multiply by
	 * \return Component-wise difference
	 */
	friend Quaternion<T> operator*(Quaternion<T> lhs, const Quaternion<T>& rhs) {
		lhs *= rhs;
		return lhs;
	}

	/*!
	 * \brief Quaternion Vector multiplication operator
	 * \param v Vector to rotate
	 * \return Rotated Vector
	 *
	 * Rotates a Vector by this quaternion.
	 */
	Vector<T, 3> operator*(const Vector<T, 3>& v) const;

	/*!
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self
	 */
	Quaternion<T>& operator*=(const T s);

	/*!
	 * \brief Scalar multiplication operator
	 * \param[in] h Quaternion to multiply
	 * \param[in] s Scalar to multiply by
	 * \return Quaternion-scalar product
	 */
	friend Quaternion<T> operator*(Quaternion<T> h, const T s) {
		h *= s;
		return h;
	}

	/*!
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self
	 */
	Quaternion<T>& operator/=(const T s);

	/*!
	 * \brief Scalar division operator
	 * \param[in] h Quaternion to divide
	 * \param[in] s Scalar to divide by
	 * \return Quaternion-scalar quotient
	 */
	friend Quaternion<T> operator/(Quaternion<T> h, const T s) {
		h /= s;
		return h;
	}

	/*!
	 * \brief Calculate the magnitude squared
	 * \return Magnitude squared
	 */
	T mag2() const;

	/*!
	 * \brief Calculate the magnitude
	 * \return Magnitude
	 */
	T mag() const;

	/*!
	 * \brief Calculate this quaternion normal
	 * \return Quaternion normal
	 */
	Quaternion<T> normal() const;

	/*!
	 * \brief Normalize this quaternion
	 * \return Reference to self
	 */
	Quaternion<T>& normalize();

	/*!
	 * \brief Calculate the inverse of this quaternion
	 * \return Quaternion inverse
	 */
	Quaternion<T> inverse() const;

	/*!
	 * \brief Invert this quaternion
	 * \return Reference to self
	 */
	Quaternion<T>& invert();

	/*!
	 * \brief Calculate euler x-axis value
	 * \return Euler x-axis value (pitch) in radians
	 */
	T pitch() const;

	/*!
	 * \brief Calculate euler y-axis value
	 * \return Euler y-axis value (yaw) in radians
	 */
	T yaw() const;

	/*!
	 * \brief Calculate euler z-axis value
	 * \return Euler z-axis value (roll) in radians
	 */
	T roll() const;

	/*!
	 * \brief Calculate the axis of rotation
	 * \return Axis of rotation
	 */
	Vector<T, 3> axis() const;

	/*!
	 * \brief Calculate the angle of rotation
	 * \return Angle of rotation in radians
	 */
	T angle() const;

	/*!
	 * \brief Calculate the rotation Matrix
	 * \return Rotation Matrix
	 */
	Matrix<T, 4, 4> to_matrix() const;

	/*!
	 * \brief Check quaternion equality operator
	 * \param[in] other Quaternion to check equality with
	 * \return True if they are equal, otherwise false
	 */
	bool equals(const Quaternion<T>& other) const;

	/*!
	 * \brief Check quaternion equality operator
	 * \param[in] other Quaternion to check equality with
	 * \param[in] ulp The desired floating point precision in ULPs
	 * \return True if they are equal, otherwise false
	 */
	template<typename U = T, typename = typename std::enable_if<std::is_floating_point<U>::value>::type>
	bool equals(const Quaternion<T>& other, const int ulp) const;

	/*!
	 * \brief Check quaternion equality operator
	 * \param[in] lhs Quaternion to check equality
	 * \param[in] rhs Quaternion to check equality with
	 * \return True if they are equal, otherwise false
	 */
	friend bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
		return lhs.equals(rhs);
	}

	/*!
	 * \brief Check quaternion inequality operator
	 * \param[in] lhs Quaternion to check inequality
	 * \param[in] rhs Quaternion to check inequality with
	 * \return False if they are equal, otherwise true
	 */
	friend bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
		return !lhs.equals(rhs);
	}

	/*!
	 * \brief Calculate the inner quaternion product (dot product)
	 * \param[in] h1 Quaternion to take dot product of
	 * \param[in] h2 Quaternion to take dot product of
	 * \return Quaternion dot product.
	 */
	static T dot(const Quaternion<T>& h1, const Quaternion<T>& h2);

	/*!
	 * \brief Linearly interpolate between two quaternions
	 * \param[in] start Start quaternion
	 * \param[in] end End quaternion
	 * \param[in] t Value to interpolate by
	 * \return Interpolated quaternion
	 */
	static Quaternion<T> lerp(const Quaternion<T>& start, const Quaternion<T>& end, const T t);

	/*!
	 * \brief Spherically interpolate between two quaternions
	 * \param[in] start Start quaternion
	 * \param[in] end End quaternion
	 * \param[in] t Value to interpolate by
	 * \param[in] shortest Take the shortest path there, default true
	 * \return Interpolated quaternion
	 */
	static Quaternion<T> slerp(const Quaternion<T>& start, const Quaternion<T>& end, const T t, const bool shortest = true);
};

}
}

#include <vmath/core/quaternion.inl>

#endif
