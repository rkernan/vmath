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

/**
* Definition of the components available in a generic vector.
* @class vector_components
* @tparam T Storage type.
* @tparam N Number of vector elements.
*/
template<typename T, std::size_t N>
class vector_components {
public:
	vector_components(void) : data() {}
	explicit vector_components(const std::array<T, N>& data) : data(data) {}
	vector_components(const vector_components<T, N>&) = default;
	vector_components<T, N>& operator=(const vector_components<T, N>&) = default;
	vector_components(vector_components<T, N>&&) = default;
	vector_components<T, N>& operator=(vector_components<T, N>&&) = default;

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
	vector_components(void) : x(), y() {}
	explicit vector_components(const std::array<T, 2>& data) : data(data) {}
	vector_components(const T& x, const T& y) : x(x), y(y) {}
	vector_components(const vector_components<T, 2>&) = default;
	vector_components<T, 2>& operator=(const vector_components<T, 2>&) = default;
	vector_components(vector_components<T, 2>&&) = default;
	vector_components<T, 2>& operator=(vector_components<T, 2>&&) = default;

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
};

/**
* Vector component specialization for 3-dimensional vectors.
* @class vector_components
* @tparam T Storage type.
*/
template<typename T>
class vector_components<T, 3> {
public:
	vector_components(void) : x(), y(), z() {}
	explicit vector_components(const std::array<T, 3>& data) : data(data) {}
	vector_components(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
	vector_components(const vector_components<T, 2>& V, const T& z) : x(V.x), y(V.y), z(z) {}
	vector_components(const vector_components<T, 3>&) = default;
	vector_components<T, 3>& operator=(const vector_components<T, 3>&) = default;
	vector_components(vector_components<T, 3>&&) = default;
	vector_components<T, 3>& operator=(vector_components<T, 3>&&) = default;

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
};

/**
* Vector component specialization for 4-dimensional vectors.
* @class vector_components
* @tparam T Storage type.
*/
template<typename T>
class vector_components<T, 4> {
public:
	vector_components(void) : x(), y(), z(), w() {}
	explicit vector_components(const std::array<T, 4>& data) : data(data) {}
	vector_components(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
	vector_components(const vector_components<T, 2>& V, const T& z, const T& w) : x(V.x), y(V.y), z(z), w(w) {}
	vector_components(const vector_components<T, 3>& V, const T& w) : x(V.x), y(V.y), z(V.z), w(w) {}
	vector_components(const vector_components<T, 4>&) = default;
	vector_components<T, 4>& operator=(const vector_components<T, 4>&) = default;
	vector_components(vector_components<T, 4>&&) = default;
	vector_components<T, 4>& operator=(vector_components<T, 4>&&) = default;

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

#include <vmath/core/vector.inl>

#endif
