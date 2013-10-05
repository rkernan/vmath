#ifndef MATH_CORE_VECTOR_HPP
#define MATH_CORE_VECTOR_HPP

#include <cstddef>
#include <ostream>
#include <type_traits>

namespace math {
namespace core {

namespace {

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
#if !defined(WINDOWS)
	// FIXME Explicitly defaulted constructors are supported in VS2013.
	explicit VectorComponents(const VectorComponents<T, 2>&) = default;
	explicit VectorComponents(VectorComponents<T, 2>&&) = default;
#endif

	union {
		T values[2];
		// axis coords
		struct { T x, y; };
		// texture coords
		struct { T s, t; };
		// color values
		struct { T r, g; };
		// TODO swizzles
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
#if !defined(WINDOWS)
	// FIXME Explicitly defaulted constructors are supported in VS2013.
	explicit VectorComponents(const VectorComponents<T, 3>&) = default;
	explicit VectorComponents(VectorComponents<T, 3>&&) = default;
#endif

	union {
		T values[3];
		// axis coords
		struct { T x, y, z; };
		// texture coords
		struct { T s, t, p; };
		// color values
		struct { T r, g, b; };
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
#if !defined(WINDOWS)
	// FIXME Explicitly defaulted constructors are supported in VS2013.
	explicit VectorComponents(const VectorComponents<T, 4>&) = default;
	explicit VectorComponents(VectorComponents<T, 4>&&) = default;
#endif

	union {
		T values[4];
		// axis coords
		struct { T x, y, z, w; };
		// texture coords
		struct { T s, t, p, q; };
		// color values
		struct { T r, g, b, a; };
	};
};

}

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

#if !defined(WINDOWS)
	// FIXME Explicitly defaulted destructors are supported in VS2013.
	~Vector(void) = default;
#endif

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
