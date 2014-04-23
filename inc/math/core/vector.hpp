#ifndef MATH_CORE_VECTOR_HPP
#define MATH_CORE_VECTOR_HPP

#include <array>
#include <cstddef>
#include <ostream>
#include <type_traits>

#include "swizzle/swizzle2.hpp"
#include "swizzle/swizzle3.hpp"
#include "swizzle/swizzle4.hpp"
#include "swizzle/swizzle_gen.hpp"

namespace math {
namespace core {
namespace {

/**
* Definition of the components available in a generic vector.
* @class vector_components
* @tparam T Storage type.
* @tparam N Number of vector elements.
*/
template<typename T, std::size_t N>
class vector_components {
public:
	explicit vector_components(void) : data() {}
	explicit vector_components(const std::array<T, N>& data) : data(data) {}

	std::array<T, N> data;
};

/**
* Vector component specialization for 2-dimensional vectors.
* @class vector_components
* @tparam T Storage type.
*/
template<typename T>
class vector_components<T, 2> {
public:
	explicit vector_components(void) : x(), y() {}
	explicit vector_components(const std::array<T, 2>& data) : data(data) {}
	explicit vector_components(const T& x, const T& y) : x(x), y(y) {}
	explicit vector_components(const vector_components<T, 2>&) = default;
	explicit vector_components(vector_components<T, 2>&&) = default;

	union {
		std::array<T, 2> data;
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
* Vector component specialization for 3-dimensional vectors.
* @class vector_components
* @tparam T Storage type.
*/
template<typename T>
class vector_components<T, 3> {
public:
	explicit vector_components(void) : x(), y(), z() {}
	explicit vector_components(const std::array<T, 3>& data) : data(data) {}
	explicit vector_components(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
	explicit vector_components(const vector_components<T, 2>& V, const T& z) : x(V.x), y(V.y), z(z) {}
	explicit vector_components(const vector_components<T, 3>&) = default;
	explicit vector_components(vector_components<T, 3>&&) = default;

	union {
		std::array<T, 3> data;
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
* Vector component specialization for 4-dimensional vectors.
* @class vector_components
* @tparam T Storage type.
*/
template<typename T>
class vector_components<T, 4> {
public:
	explicit vector_components(void) : x(), y(), z(), w() {}
	explicit vector_components(const std::array<T, 4>& data) : data(data) {}
	explicit vector_components(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	explicit vector_components(const vector_components<T, 2>& V, const T& z, const T& w) : x(V.x), y(V.y), z(z), w(w) {}
	explicit vector_components(const vector_components<T, 3>& V, const T& w) : x(V.x), y(V.y), z(V.z), w(w) {}
	explicit vector_components(const vector_components<T, 4>&) = default;
	explicit vector_components(vector_components<T, 4>&&) = default;

	union {
		std::array<T, 4> data;
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

}

/**
 * A vector with generic size and type.
 * @class vector
 * @tparam T Storage type.
 * @tparam N Number of vector elements.
 */
template<typename T, std::size_t N>
class vector : public vector_components<T, N> {
public:
	using vector_components<T, N>::vector_components;

	~vector(void) = default;

	vector<T, N>& operator=(const vector<T, N>&);

	T operator[](const std::size_t) const;
	T& operator[](const std::size_t);

	vector<T, N> operator-(void) const;
	vector<T, N> operator+(const vector<T, N>&) const;
	vector<T, N>& operator+=(const vector<T, N>&);
	vector<T, N> operator-(const vector<T, N>&) const;
	vector<T, N>& operator-=(const vector<T, N>&);
	vector<T, N> operator*(const vector<T, N>&) const;
	vector<T, N>& operator*=(const vector<T, N>&);
	vector<T, N> operator/(const vector<T, N>&) const;
	vector<T, N>& operator/=(const vector<T, N>&);

	vector<T, N> operator*(const T&) const;
	vector<T, N>& operator*=(const T&);
	vector<T, N> operator/(const T&) const;
	vector<T, N>& operator/=(const T&);

	T mag(void) const;
	T mag2(void) const;
	vector<T, N> normal(void) const;
	vector<T, N>& normalize(void);

	bool operator==(const vector<T, N>&) const;
	bool operator!=(const vector<T, N>&) const;

	static T dot(const vector<T, N>&, const vector<T, N>&);
	static vector<T, N> reflect(const vector<T, N>&, const vector<T, N>&);
	static vector<T, N> refract(const vector<T, N>&, const vector<T, N>&, const T&);
	static vector<T, N> lerp(const vector<T, N>&, const vector<T, N>&, const T&);

	template<typename U = T, typename = typename std::enable_if<N == 2, U>::type>
	static T cross(const vector<T, N>&, const vector<T, N>&);

	template<typename U = T, typename = typename std::enable_if<N == 3, U>::type>
	static vector<T, N> cross(const vector<T, N>&, const vector<T, N>&);
};

}
}

#include "vector.inl"

#endif
