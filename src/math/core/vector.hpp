#ifndef MATH_CORE_VECTOR_HPP
#define MATH_CORE_VECTOR_HPP

#include <cstddef>
#include <ostream>
#include <type_traits>
#include "swizzle/swizzle2.hpp"
#include "swizzle/swizzle3.hpp"
#include "swizzle/swizzle4.hpp"
#include "swizzle/swizzle_gen.hpp"

namespace math {
namespace core {

/**
* @class VectorComponents
* @tparam T Storage type.
* @tparam N Number of vector elements.
* Definition of the components available in a generic vector.
*/
template<typename T, std::size_t N>
class VectorComponents {
public:
	T values[N];
};

/**
* @class VectorComponents
* @tparam T Storage type.
* Vector component specialization for 2-dimensional vectors.
*/
template<typename T>
class VectorComponents<T, 2> {
public:
	explicit VectorComponents(void) : x(), y() {}
	explicit VectorComponents(const T& x, const T& y) : x(x), y(y) {}
	explicit VectorComponents(const VectorComponents<T, 2>&) = default;
	explicit VectorComponents(VectorComponents<T, 2>&&) = default;

	union {
		T values[2];
		// axis coords
		struct { T x, y; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, x, y)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, x, y)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, x, y)
		// texture coords
		struct { T s, t; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, s, t)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, s, t)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, s, t)
		// color values
		struct { T r, g; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, r, g)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, r, g)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, r, g)
	};
};

/**
* @class VectorComponents
* @tparam T Storage type.
* Vector component specialization for 3-dimensional vectors.
*/
template<typename T>
class VectorComponents<T, 3> {
public:
	explicit VectorComponents(void) : x(), y(), z() {}
	explicit VectorComponents(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
	explicit VectorComponents(const VectorComponents<T, 2>& V, const T& z) : x(V.x), y(V.y), z(z) {}
	explicit VectorComponents(const VectorComponents<T, 3>&) = default;
	explicit VectorComponents(VectorComponents<T, 3>&&) = default;

	union {
		T values[3];
		// axis coords
		struct { T x, y, z; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, x, y, z)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, x, y, z)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, x, y, z)
		// texture coords
		struct { T s, t, p; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, s, t, p)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, s, t, p)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, s, t, p)
		// color values
		struct { T r, g, b; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, r, g, b)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, r, g, b)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, r, g, b)
	};
};

/**
* @class VectorComponents
* @tparam T Storage type.
* Vector component specialization for 4-dimensional vectors.
*/
template<typename T>
class VectorComponents<T, 4> {
public:
	explicit VectorComponents(void) : x(), y(), z(), w() {}
	explicit VectorComponents(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	explicit VectorComponents(const VectorComponents<T, 2>& V, const T& z, const T& w) : x(V.x), y(V.y), z(z), w(w) {}
	explicit VectorComponents(const VectorComponents<T, 3>& V, const T& w) : x(V.x), y(V.y), z(V.z), w(w) {}
	explicit VectorComponents(const VectorComponents<T, 4>&) = default;
	explicit VectorComponents(VectorComponents<T, 4>&&) = default;

	union {
		T values[4];
		// axis coords
		struct { T x, y, z, w; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, x, y, z, w)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, x, y, z, w)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, x, y, z, w)
		// texture coords
		struct { T s, t, p, q; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, s, t, p, q)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, s, t, p, q)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, s, t, p, q)
		// color values
		struct { T r, g, b, a; };
		MATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, r, g, b, a)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, r, g, b, a)
		MATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, r, g, b, a)
	};
};

/**
 * @class Vector
 * @tparam T Storage type.
 * @tparam N Number of vector elements.
 */
template<typename T, std::size_t N>
class Vector : public VectorComponents<T, N> {
public:
	// using VectorComponents<T, N>::VectorComponents; // not supported in VS2012/2013 or clang < 3.3
	// FIXME This is just temporary until VS supports constructor inheritance (above)
	Vector(const T& x, const T& y) : VectorComponents<T, N>(x, y) {}
	Vector(const T& x, const T& y, const T& z) : VectorComponents<T, N>(x, y, z) {}
	Vector(const T& x, const T& y, const T& z, const T& w) : VectorComponents<T, N>(x, y, z, w) {}

	Vector(void);
	Vector(const T values[N]);

	~Vector(void) = default;

	T operator[](const std::size_t) const;
	T& operator[](const std::size_t);

	Vector<T, N>& operator=(const Vector<T, N>&);
	Vector<T, N> operator-(void) const;
	Vector<T, N> operator+(const Vector<T, N>&) const;
	Vector<T, N>& operator+=(const Vector<T, N>&);
	Vector<T, N> operator-(const Vector<T, N>&) const;
	Vector<T, N>& operator-=(const Vector<T, N>&);
	Vector<T, N> operator*(const Vector<T, N>&) const;
	Vector<T, N>& operator*=(const Vector<T, N>&);
	Vector<T, N> operator/(const Vector<T, N>&) const;
	Vector<T, N>& operator/=(const Vector<T, N>&);

	T mag(void) const;
	T mag2(void) const;
	Vector<T, N> normal(void) const;
	Vector<T, N>& normalize(void);

	bool operator==(const Vector<T, N>&) const;
	bool operator!=(const Vector<T, N>&) const;

	static T dot(const Vector<T, N>&, const Vector<T, N>&);
	static Vector<T, N> reflect(const Vector<T, N>&, const Vector<T, N>&);
	static Vector<T, N> refract(const Vector<T, N>&, const Vector<T, N>&, const T&);
	static Vector<T, N> lerp(const Vector<T, N>&, const Vector<T, N>&, const T&);

	template<typename = typename std::enable_if<N == 2>::type>
	static T cross(const Vector<T, N>& V1, const Vector<T, N>& V2);

	template<typename = typename std::enable_if<N == 3>::type>
	static Vector<T, N> cross(const Vector<T, N>& V1, const Vector<T, N>& V2);
};

template<typename T, std::size_t N>
Vector<T, N> operator*(const T&, const Vector<T, N>&);

template<typename T, std::size_t N>
Vector<T, N> operator/(const Vector<T, N>&, const T&);

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream&, const Vector<T, N>&);

}
}

#include "vector.inl"

#endif
