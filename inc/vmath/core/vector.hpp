#ifndef VMATH_CORE_VECTOR_HPP
#define VMATH_CORE_VECTOR_HPP

#include <array>
#include <cstddef>
#include <type_traits>
#include <vmath/core/swizzle/swizzle2.hpp>
#include <vmath/core/swizzle/swizzle3.hpp>
#include <vmath/core/swizzle/swizzle4.hpp>
#include <vmath/core/swizzle/swizzle_gen.hpp>

namespace vmath {
namespace core {
namespace {

/*!
 * \brief Definition of the components available in a generic vector
 * \tparam T Storage type
 * \tparam N Number of vector elements
 */
template<typename T, std::size_t N>
class VectorComponents {
public:
	std::array<T, N> data;

	/*!
	 * \brief Construct a zero vector component
	 */
	VectorComponents() : data() {}

	/*!
	 * \brief Construct a vector componet from an array
	 * \param[in] data Array to convert to a vector component
	 */
	explicit VectorComponents(const std::array<T, N>& data) : data(data) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other Vector component object to copy
	 */
	VectorComponents(const VectorComponents<T, N>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other Vector component object to copy
	 * \return Reference to self
	 */
	VectorComponents<T, N>& operator=(const VectorComponents<T, N>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other Vector component object to move
	 */
	VectorComponents(VectorComponents<T, N>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other Vector component object to move
	 * \return Reference to self
	 */
	VectorComponents<T, N>& operator=(VectorComponents<T, N>&& other) = default;
};

/*!
 * \brief Vector component specialization for 2-dimensional vectors
 * \tparam T Storage type
 */
template<typename T>
class VectorComponents<T, 2> {
public:
	union {
		std::array<T, 2> data;
		// axis coords
		struct { T x, y; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, x, y)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, x, y)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, x, y)
		// texture coords
		struct { T s, t; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, s, t)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, s, t)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, s, t)
		// color values
		struct { T r, g; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, r, g)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, r, g)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, r, g)
	};

	/*!
	 * \brief Construct a zero 2-dimensional vector component
	 */
	VectorComponents() : x(), y() {}

	/*!
	 * \brief Construct a 2-dimensional vector component from an array
	 * \param[in] data Array to convert to a vector component
	 */
	explicit VectorComponents(const std::array<T, 2>& data) : data(data) {}

	/*!
	 * \brief Construct a 2-dimensional vector component by value
	 * \param[in] x X coordinate value
	 * \param[in] y Y coordinate value
	 */
	VectorComponents(const T x, const T y) : x(x), y(y) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 2-dimensional vector component to copy
	 */
	VectorComponents(const VectorComponents<T, 2>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 2-dimensional vector component to copy
	 * \return Reference to self
	 */
	VectorComponents<T, 2>& operator=(const VectorComponents<T, 2>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 2-dimensional vector component to move
	 */
	VectorComponents(VectorComponents<T, 2>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 2-dimensional vector component to move
	 * \return Reference to self
	 */
	VectorComponents<T, 2>& operator=(VectorComponents<T, 2>&& other) = default;
};

/*!
 * \brief Vector component specialization for 3-dimensional vectors
 * \tparam T Storage type
 */
template<typename T>
class VectorComponents<T, 3> {
public:
	union {
		std::array<T, 3> data;
		// axis coords
		struct { T x, y, z; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, x, y, z)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, x, y, z)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, x, y, z)
		// texture coords
		struct { T s, t, p; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, s, t, p)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, s, t, p)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, s, t, p)
		// color values
		struct { T r, g, b; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, r, g, b)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, r, g, b)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, r, g, b)
	};
	
	/*!
	 * \brief Construct a zero 3-dimensional vector component
	 */
	VectorComponents() : x(), y(), z() {}

	/*!
	 * \brief Construct a 3-dimensional vector component from an array
	 */
	explicit VectorComponents(const std::array<T, 3>& data) : data(data) {}

	/*!
	 * \brief Construct a 3-dimensional vector component by value
	 * \param[in] x X coordinate value
	 * \param[in] y Y coordinate value
	 * \param[in] z Z coordinate value
	 */
	VectorComponents(const T x, const T y, const T z) : x(x), y(y), z(z) {}

	/*!
	 * \brief Constructor a 3-dimensional vector component by extending a
	 *        2-dimensional one
	 * \param[in] vec 2-dimensional vector component
	 * \param[in] z Z coordinate value
	 */
	VectorComponents(const VectorComponents<T, 2>& vec, const T z) : x(vec.x), y(vec.y), z(z) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 3-dimensional vector component to copy
	 */
	VectorComponents(const VectorComponents<T, 3>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 3-dimensional vector component to copy
	 * \return Reference to self
	 */
	VectorComponents<T, 3>& operator=(const VectorComponents<T, 3>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 3-dimensional vector component to move
	 */
	VectorComponents(VectorComponents<T, 3>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 3-dimensional vector component to move
	 * \return Reference to self
	 */
	VectorComponents<T, 3>& operator=(VectorComponents<T, 3>&& other) = default;
};

/*!
 * \brief Vector component specialization for 4-dimensional vectors
 * \tparam T Storage type
 */
template<typename T>
class VectorComponents<T, 4> {
public:
	union {
		std::array<T, 4> data;
		// axis coords
		struct { T x, y, z, w; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, x, y, z, w)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, x, y, z, w)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, x, y, z, w)
		// texture coords
		struct { T s, t, p, q; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, s, t, p, q)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, s, t, p, q)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, s, t, p, q)
		// color values
		struct { T r, g, b, a; };
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, r, g, b, a)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, r, g, b, a)
		VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, r, g, b, a)
	};

	/*!
	 * \brief Construct a zero 4-dimensional vector component
	 */
	VectorComponents() : x(), y(), z(), w() {}

	/*!
	 * \brief Construct a 4-dimensional vector component from an array
	 * \param[in] data Array to convert to a vector component
	 */
	explicit VectorComponents(const std::array<T, 4>& data) : data(data) {}

	/*!
	 * \brief Construct a 4-dimensional vector component by value
	 * \param[in] x X coordinate value
	 * \param[in] y Y coordinate value
	 * \param[in] z Z coordinate value
	 * \param[in] w W coordinate value
	 */
	VectorComponents(const T x, const T y, const T z, const T w) : x(x), y(y), z(z), w(w) {}

	/*!
	 * \brief Construct a 4-dimensional vector component by extending a
	 *        2-dimensional one
	 * \param[in] vec 2-dimensional vector component
	 * \param[in] z Z coordinate value
	 * \param[in] w W coordinate value
	 */
	VectorComponents(const VectorComponents<T, 2>& vec, const T z, const T w) : x(vec.x), y(vec.y), z(z), w(w) {}

	/*!
	 * \brief Construct a 4-dimensional vector component by extending a
	 *        3-dimensional one
	 * \param[in] vec 3-dimensional vector component
	 * \param[in] w W coordinate value
	 */
	VectorComponents(const VectorComponents<T, 3>& vec, const T w) : x(vec.x), y(vec.y), z(vec.z), w(w) {}

	/*!
	 * \brief Copy constructor
	 * \param[in] other 4-dimensional vector component to copy
	 */
	VectorComponents(const VectorComponents<T, 4>& other) = default;

	/*!
	 * \brief Copy assignment operator
	 * \param[in] other 4-dimensional vector component to copy
	 * \return Reference to self
	 */
	VectorComponents<T, 4>& operator=(const VectorComponents<T, 4>& other) = default;

	/*!
	 * \brief Move constructor
	 * \param[in] other 4-dimensional vector component to move
	 */
	VectorComponents(VectorComponents<T, 4>&& other) = default;

	/*!
	 * \brief Move assignment operator
	 * \param[in] other 4-dimensional vector component to move
	 * \return Reference to self
	 */
	VectorComponents<T, 4>& operator=(VectorComponents<T, 4>&& other) = default;
};

}

/*!
 * \brief A vector with generic size and type
 * \tparam T Storage type
 * \tparam N Number of vector elements
 */
template<typename T, std::size_t N>
class Vector : public VectorComponents<T, N> {
public:
	using VectorComponents<T, N>::VectorComponents;

	/*!
	 * \brief Destructor
	 */
	~Vector() = default;

	/*!
	 * \brief Access a vector element using an index
	 * \param[in] idx Location of element to access
	 * \return Accessed element
	 */
	T operator[](const std::size_t) const;

	/*!
	 * \brief Access and modify a vector element by index
	 * \param[in] idx Location of element to access
	 * \return Modified element
	 */
	T& operator[](const std::size_t);

	/*!
	 * \brief Vector negation operator
	 * \return The vector negated
	 */
	Vector<T, N> operator-() const;

	/*!
	 * \brief Component-wise addition assignment operator
	 * \param[in] v Vector to add
	 * \return Reference to self
	 */
	Vector<T, N>& operator+=(const Vector<T, N>& v);

	/*!
	 * \brief Component-wise addition operator
	 * \param[in] lhs Vector to add to
	 * \param[in] rhs Vector to add
	 * \return The component-wise sum
	 */
	friend Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs) {
		return lhs += rhs;
	}

	/*!
	 * \brief Component-wise subtraction assignment operator
	 * \param[in] v Vector to subtract
	 * \return Reference to self
	 */
	Vector<T, N>& operator-=(const Vector<T, N>& v);

	/*!
	 * \brief Component-wise subtraction operator
	 * \param[in] lhs Vector to subtract from
	 * \param[in] rhs Vector to subtract
	 * \return The component-wise difference
	 */
	friend Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs) {
		return lhs -= rhs;
	}
	
	/*!
	 * \brief Component-wise multiplication assignment operator
	 * \param[in] v Vector to multiply
	 * \return Reference to self
	 */
	Vector<T, N>& operator*=(const Vector<T, N>& v);

	/*!
	 * \brief Component-wise multiplication operator
	 * \param[in] lhs Vector to multiply
	 * \param[in] rhs Vector to multiply by
	 * \return The component-wise product
	 */
	friend Vector<T, N> operator*(Vector<T, N> lhs, const Vector<T, N>& rhs) {
		return lhs *= rhs;
	}

	/*!
	 * \brief Component-wise division assignment operator
	 * \param[in] v Vector to divide by
	 * \return Reference to self
	 */
	Vector<T, N>& operator/=(const Vector<T, N>& v);

	/*!
	 * \brief Component-wise division operator
	 * \param[in] lhs Vector to divide
	 * \param[in] rhs Vector to divide by
	 * \return The component-wise quotient
	 */
	friend Vector<T, N> operator/(Vector<T, N> lhs, const Vector<T, N>& rhs) {
		return lhs /= rhs;
	}

	/*!
	 * \brief Scalar multiplication assignment operator
	 * \param[in] s Scalar to multiply by
	 * \return Reference to self
	 */
	Vector<T, N>& operator*=(const T s);

	/*!
	 * \brief Scalar multiplication operator
	 * \param[in] v Vector to multiply
	 * \param[in] s Scalar to multiply by
	 * \return Vector-scalar product
	 */
	friend Vector<T, N> operator*(Vector<T, N> v, const T s) {
		return v *= s;
	}

	/*!
	 * \brief Scalar division assignment operator
	 * \param[in] s Scalar to divide by
	 * \return Reference to self
	 */
	Vector<T, N>& operator/=(const T s);

	/*!
	 * \brief Scalar division operator
	 * \param[in] v Vector to divide
	 * \param[in] s Scalar to divide by
	 * \return Vector-scalar quotient
	 */
	friend Vector<T, N> operator/(Vector<T, N> v, const T s) {
		return v /= s;
	}

	/*!
	 * \brief Calculate the vector magnitude
	 * \return Vector magnitude
	 */
	T mag() const;

	/*!
	 * \brief Calculate the vector magnitude squared
	 * \return Vector magnitude squared
	 */
	T mag2() const;

	/*!
	 * \brief Calculate the vector normal
	 * \return The vector normal
	 */
	Vector<T, N> normal() const;

	/*!
	 * \brief Normalize the vector
	 * \return Reference to self
	 */
	Vector<T, N>& normalize();

	/*!
	 * \brief Check vector equality
	 * \param[in] other Vector to check equality with
	 * \return True if equal, else false
	 */
	bool equals(const Vector<T, N>& other) const;

	/*!
	 * \brief Check vector equality
	 * \param[in] other Vector to check equality with
	 * \param[in] ulp The desired floating point precision in ULPs
	 * \return True if equal, else false
	 */
	template<typename U = T, typename = typename std::enable_if<std::is_floating_point<U>::value>::type>
	bool equals(const Vector<T, N>& other, const int ulp) const;

	/*!
	 * \brief Equality operator
	 * \param[in] lhs Vector to check equality
	 * \param[in] rhs Vector to check equality with
	 * \return True if equal, else false
	 */
	friend bool operator==(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
		return lhs.equals(rhs);
	}

	/*!
	 * \brief Inequality operator
	 * \param[in] lhs Vector to check inequality
	 * \param[in] rhs Vector to check inequality with
	 * \return False if equal, else true
	 */
	friend bool operator!=(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
		return !(lhs.equals(rhs));
	}

	/*!
	 * \brief Calculate the inner vector product (dot product)
	 * \param[in] v1 Vector to take dot product of
	 * \param[in] v2 Vector to take dot product of
	 * \return Vector dot product
	 */
	static T dot(const Vector<T, N>& v1, const Vector<T, N>& v2);

	/*!
	 * \brief Calculate the reflection direction
	 * \param[in] incident Incident vector
	 * \param[in] surface_normal Surface normal vector
	 * \return Reflection of incident over the normal
	 */
	static Vector<T, N> reflect(const Vector<T, N>& incident, const Vector<T, N>& surface_normal);

	/*!
	 * \brief Calculate the refraction direction
	 * \param[in] incident Incident vector
	 * \param[in] surface_normal Surface normal vector
	 * \param[in] eta Ratio of refraction
	 * \return Refraction of the indedent over the normal
	 */
	static Vector<T, N> refract(const Vector<T, N>& incident, const Vector<T, N>& surface_normal, const T eta);

	/*!
	 * \brief Linearly interpolate between two vectors
	 * \param[in] start Start vector
	 * \param[in] end End vector
	 * \param[in] t Value to interpolate by
	 * \return Interpolated vector
	 */
	static Vector<T, N> lerp(const Vector<T, N>& start, const Vector<T, N>& end, const T t);

	/*!
	 * \brief Calculate the outer vector product (cross product) of a
	 *        2-dimensional vector
	 * \tparam U Used to determine if this is a 2-dimensional vector
	 * \param[in] v1 Vector to take outer product of
	 * \param[in] v2 Vector to take outer product of
	 * \return 2-dimensional vector cross product
	 */
	template<typename U = T, typename = typename std::enable_if<N == 2, U>::type>
	static T cross(const Vector<T, N>& v1, const Vector<T, N>& v2);

	/*!
	 * \brief Calculate the outer vector product (cross product) of a
	 *        3-dimensional vector
	 * \tparam U Used to determine if this is a 3-dimensional vector
	 * \param[in] v1 Vector to take outer product of
	 * \param[in] v2 Vector to take outer product of
	 * \return 3-dimensional vector cross product
	 */
	template<typename U = T, typename = typename std::enable_if<N == 3, U>::type>
	static Vector<T, N> cross(const Vector<T, N>& v1, const Vector<T, N>& v2);
};

}
}

#include <vmath/core/vector.inl>

#endif
