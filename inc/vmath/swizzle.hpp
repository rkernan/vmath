#ifndef VMATH_SWIZZLE_HPP
#define VMATH_SWIZZLE_HPP

#include <array>
#include <cstddef>
#include <vmath/vector.hpp>

#define VMATH_SWIZZLE_BINARY_OPERATOR(OP) \
	template<typename T, std::size_t N, std::size_t... Is> \
	Vector<T, sizeof...(Is)> operator OP (Vector<T, sizeof...(Is)> lhs, const Swizzle<T, N, Is...>& rhs) { \
		return lhs OP rhs(); \
	} \
	template<typename T, std::size_t N, std::size_t... Is> \
	Vector<T, sizeof...(Is)> operator OP (Swizzle<T, N, Is...> lhs, const Vector<T, sizeof...(Is)>& rhs) { \
		return lhs() OP rhs; \
	} \
	template<typename T, std::size_t N, std::size_t M, std::size_t... Is, std::size_t... Js> \
	typename std::enable_if<sizeof...(Is) == sizeof...(Js), Vector<T, sizeof...(Is)>>::type operator OP (Swizzle<T, N, Is...> lhs, const Swizzle<T, M, Js...> rhs) { \
		return lhs() OP rhs(); \
	}

#define VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN(OP)

#define VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR(OP) \
	template<typename T, std::size_t N, std::size_t... Is> \
	Vector<T, sizeof...(Is)> operator OP (Swizzle<T, N, Is...> lhs, const T& rhs) { \
		return lhs() OP rhs; \
	}

#define VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR_ASSIGN(OP) // TODO

#define VMATH_SWIZZLE_EQUALITY_OPERATOR(OP) \
	template<typename T, std::size_t N, std::size_t... Is> \
	bool operator OP (const Vector<T, sizeof...(Is)>& lhs, const Swizzle<T, N, Is...>& rhs) { \
		return lhs OP rhs(); \
	} \
	template<typename T, std::size_t N, std::size_t... Is> \
	bool operator OP (const Swizzle<T, N, Is...>& lhs, const Vector<T, sizeof...(Is)>& rhs) { \
		return lhs() OP rhs; \
	} \
	template<typename T, std::size_t N, std::size_t M, std::size_t... Is, std::size_t... Js> \
	typename std::enable_if<sizeof...(Is) == sizeof...(Js), bool>::type operator OP (const Swizzle<T, N, Is...>& lhs, const Swizzle<T, M, Js...>& rhs) { \
		return lhs() OP rhs(); \
	}

namespace vmath {

template<std::size_t...>
struct is_one_of;

template<std::size_t I>
struct is_one_of<I> {
	static constexpr bool value = false;
};

template<std::size_t I, std::size_t J, std::size_t... Is>
struct is_one_of<I, J, Is...> {
	static constexpr bool value = I == J || is_one_of<I, Is...>::value;
};

template<std::size_t...>
struct has_unique;

template<>
struct has_unique<> {
	static constexpr bool value = true;
};

template<std::size_t I, std::size_t... Is>
struct has_unique<I, Is...> {
	static constexpr bool value = has_unique<Is...>::value && !is_one_of<I, Is...>::value;
};

template<std::size_t N, std::size_t... Is>
struct is_assignable_swizzle {
	static constexpr bool value = has_unique<Is...>::value && sizeof...(Is) == N;
};

template<std::size_t... Is>
struct is_swizzle2 {
	static constexpr bool value = sizeof...(Is) == 2;
};

template<std::size_t... Is>
struct is_swizzle3 {
	static constexpr bool value = sizeof...(Is) == 3;
};

template<std::size_t... Is>
struct is_swizzle4 {
	static constexpr bool value = sizeof...(Is) == 4;
};

template<typename T, std::size_t N, std::size_t... Is>
class Swizzle {
private:
	std::array<T, N> data;
public:

	operator Vector<T, sizeof...(Is)>() {
		std::array<T, sizeof...(Is)> vdata;
		for (std::size_t i = 0; i < sizeof...(Is); i++) {
			vdata[i] = (*this)[i];
		}
		return Vector<T, sizeof...(Is)>(vdata);
	}

	Vector<T, sizeof...(Is)> operator()() const {
		std::array<T, sizeof...(Is)> vdata;
		for (std::size_t i = 0; i < sizeof...(Is); i++) {
			vdata[i] = (*this)[i];
		}
		return Vector<T, sizeof...(Is)>(vdata);
	}

/* 	typename std::enable_if<is_swizzle2<Is...>::value, Vector<T, 2>>::type operator()() const { */
/* 		return Vector<T, 2>((*this)[0], (*this)[1]); */
/* 	} */

/* 	typename std::enable_if<is_swizzle3<Is...>::value, Vector<T, 3>>::type operator()() const { */
/* 		return Vector<T, 3>((*this)[0], (*this)[1], (*this)[2]); */
/* 	} */

/* 	typename std::enable_if<is_swizzle4<Is...>::value, Vector<T, 4>>::type operator()() const { */
/* 		return Vector<T, 4>((*this)[0], (*this)[1], (*this)[2], (*this)[3]); */
/* 	} */

	T operator[](const std::size_t i) const {
		return this->data.at(this->get_index_array().at(i));
	}

	T mag() const {
		return (*this)().mag();
	}

	T mag2() const {
		return (*this)().mag2();
	}

	// FIXME We should know the index array at compile time!
	std::array<std::size_t, sizeof...(Is)> get_index_array() const {
		auto index_array = std::array<std::size_t, sizeof...(Is)> { Is... };
		return index_array;
	}

	VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN(-=)
	VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN(*=)
	VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN(/=)

	VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
};

VMATH_SWIZZLE_BINARY_OPERATOR(+)
VMATH_SWIZZLE_BINARY_OPERATOR(-)
VMATH_SWIZZLE_BINARY_OPERATOR(*)
VMATH_SWIZZLE_BINARY_OPERATOR(/)

VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR(*)
VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR(/)

VMATH_SWIZZLE_EQUALITY_OPERATOR(==)
VMATH_SWIZZLE_EQUALITY_OPERATOR(!=)

}

#undef VMATH_SWIZZLE_BINARY_OPERATOR
#undef VMATH_SWIZZLE_BINARY_OPERATOR_ASSIGN
#undef VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR
#undef VMATH_SWIZZLE_BINARY_SCALAR_OPERATOR_ASSIGN
#undef VMATH_SWIZZLE_EQUALITY_OPERATOR

// Macros for defining vector swizzle members:

#define VMATH_SWIZZLE2_FOR_VECTOR2(T, E1, E2) \
	struct { vmath::Swizzle<T, 2, 0, 0> E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 1> E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 0> E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 1> E2 ## E2; };

#define VMATH_SWIZZLE3_FOR_VECTOR2(T, E1, E2) \
	struct { vmath::Swizzle<T, 2, 0, 0, 0> E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 0, 1> E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 0> E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 1> E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 0> E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 1> E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 0> E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 1> E2 ## E2 ## E2; };

#define VMATH_SWIZZLE4_FOR_VECTOR2(T, E1, E2) \
	struct { vmath::Swizzle<T, 2, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 2, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2; };

#define VMATH_SWIZZLE2_FOR_VECTOR3(T, E1, E2, E3) \
	struct { vmath::Swizzle<T, 3, 0, 0> E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 1> E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 2> E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 0> E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 1> E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 2> E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 0> E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 1> E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 2> E3 ## E3; };

#define VMATH_SWIZZLE3_FOR_VECTOR3(T, E1, E2, E3) \
	struct { vmath::Swizzle<T, 3, 0, 0, 0> E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 1> E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 2> E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 0> E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 1> E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 2> E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 0> E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 1> E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 2> E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 0> E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 1> E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 2> E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 0> E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 1> E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 2> E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 0> E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 1> E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 2> E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 0> E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 1> E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 2> E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 0> E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 1> E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 2> E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 0> E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 1> E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 2> E3 ## E3 ## E3; };

#define VMATH_SWIZZLE4_FOR_VECTOR3(T, E1, E2, E3) \
	struct { vmath::Swizzle<T, 3, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 0, 2> E1 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 1, 2> E1 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 2, 0> E1 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 2, 1> E1 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 0, 2, 2> E1 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 0, 2> E1 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 1, 2> E1 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 2, 0> E1 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 2, 1> E1 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 1, 2, 2> E1 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 0, 0> E1 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 0, 1> E1 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 0, 2> E1 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 1, 0> E1 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 1, 1> E1 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 1, 2> E1 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 2, 0> E1 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 2, 1> E1 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 0, 2, 2, 2> E1 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 0, 2> E2 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 1, 2> E2 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 2, 0> E2 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 2, 1> E2 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 0, 2, 2> E2 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 0, 2> E2 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 1, 2> E2 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 2, 0> E2 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 2, 1> E2 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 1, 2, 2> E2 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 0, 0> E2 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 0, 1> E2 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 0, 2> E2 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 1, 0> E2 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 1, 1> E2 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 1, 2> E2 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 2, 0> E2 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 2, 1> E2 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 1, 2, 2, 2> E2 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 0, 0> E3 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 0, 1> E3 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 0, 2> E3 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 1, 0> E3 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 1, 1> E3 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 1, 2> E3 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 2, 0> E3 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 2, 1> E3 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 0, 2, 2> E3 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 0, 0> E3 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 0, 1> E3 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 0, 2> E3 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 1, 0> E3 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 1, 1> E3 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 1, 2> E3 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 2, 0> E3 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 2, 1> E3 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 1, 2, 2> E3 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 0, 0> E3 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 0, 1> E3 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 0, 2> E3 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 1, 0> E3 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 1, 1> E3 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 1, 2> E3 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 2, 0> E3 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 2, 1> E3 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 3, 2, 2, 2, 2> E3 ## E3 ## E3 ## E3; };

#define VMATH_SWIZZLE2_FOR_VECTOR4(T, E1, E2, E3, E4) \
	struct { vmath::Swizzle<T, 4, 0, 0> E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1> E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2> E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3> E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0> E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1> E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2> E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3> E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0> E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1> E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2> E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3> E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0> E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1> E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2> E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3> E4 ## E4; };

#define VMATH_SWIZZLE3_FOR_VECTOR4(T, E1, E2, E3, E4) \
	struct { vmath::Swizzle<T, 4, 0, 0, 0> E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 1> E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 2> E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 3> E1 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 0> E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 1> E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 2> E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 3> E1 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 0> E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 1> E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 2> E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 3> E1 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 0> E1 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 1> E1 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 2> E1 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 3> E1 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 0> E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 1> E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 2> E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 3> E2 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 0> E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 1> E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 2> E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 3> E2 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 0> E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 1> E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 2> E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 3> E2 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 0> E2 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 1> E2 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 2> E2 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 3> E2 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 0> E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 1> E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 2> E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 3> E3 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 0> E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 1> E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 2> E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 3> E3 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 0> E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 1> E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 2> E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 3> E3 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 0> E3 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 1> E3 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 2> E3 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 3> E3 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 0> E4 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 1> E4 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 2> E4 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 3> E4 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 0> E4 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 1> E4 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 2> E4 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 3> E4 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 0> E4 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 1> E4 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 2> E4 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 3> E4 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 0> E4 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 1> E4 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 2> E4 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 3> E4 ## E4 ## E4; };

#define VMATH_SWIZZLE4_FOR_VECTOR4(T, E1, E2, E3, E4) \
	struct { vmath::Swizzle<T, 4, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 0, 2> E1 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 0, 3> E1 ## E1 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 1, 2> E1 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 1, 3> E1 ## E1 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 2, 0> E1 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 2, 1> E1 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 2, 2> E1 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 2, 3> E1 ## E1 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 3, 0> E1 ## E1 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 3, 1> E1 ## E1 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 3, 2> E1 ## E1 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 0, 3, 3> E1 ## E1 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 0, 2> E1 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 0, 3> E1 ## E2 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 1, 2> E1 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 1, 3> E1 ## E2 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 2, 0> E1 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 2, 1> E1 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 2, 2> E1 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 2, 3> E1 ## E2 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 3, 0> E1 ## E2 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 3, 1> E1 ## E2 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 3, 2> E1 ## E2 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 1, 3, 3> E1 ## E2 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 0, 0> E1 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 0, 1> E1 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 0, 2> E1 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 0, 3> E1 ## E3 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 1, 0> E1 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 1, 1> E1 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 1, 2> E1 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 1, 3> E1 ## E3 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 2, 0> E1 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 2, 1> E1 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 2, 2> E1 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 2, 3> E1 ## E3 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 3, 0> E1 ## E3 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 3, 1> E1 ## E3 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 3, 2> E1 ## E3 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 2, 3, 3> E1 ## E3 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 0, 0> E1 ## E4 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 0, 1> E1 ## E4 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 0, 2> E1 ## E4 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 0, 3> E1 ## E4 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 1, 0> E1 ## E4 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 1, 1> E1 ## E4 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 1, 2> E1 ## E4 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 1, 3> E1 ## E4 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 2, 0> E1 ## E4 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 2, 1> E1 ## E4 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 2, 2> E1 ## E4 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 2, 3> E1 ## E4 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 3, 0> E1 ## E4 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 3, 1> E1 ## E4 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 3, 2> E1 ## E4 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 0, 3, 3, 3> E1 ## E4 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 0, 2> E2 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 0, 3> E2 ## E1 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 1, 2> E2 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 1, 3> E2 ## E1 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 2, 0> E2 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 2, 1> E2 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 2, 2> E2 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 2, 3> E2 ## E1 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 3, 0> E2 ## E1 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 3, 1> E2 ## E1 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 3, 2> E2 ## E1 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 0, 3, 3> E2 ## E1 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 0, 2> E2 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 0, 3> E2 ## E2 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 1, 2> E2 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 1, 3> E2 ## E2 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 2, 0> E2 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 2, 1> E2 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 2, 2> E2 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 2, 3> E2 ## E2 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 3, 0> E2 ## E2 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 3, 1> E2 ## E2 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 3, 2> E2 ## E2 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 1, 3, 3> E2 ## E2 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 0, 0> E2 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 0, 1> E2 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 0, 2> E2 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 0, 3> E2 ## E3 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 1, 0> E2 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 1, 1> E2 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 1, 2> E2 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 1, 3> E2 ## E3 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 2, 0> E2 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 2, 1> E2 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 2, 2> E2 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 2, 3> E2 ## E3 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 3, 0> E2 ## E3 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 3, 1> E2 ## E3 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 3, 2> E2 ## E3 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 2, 3, 3> E2 ## E3 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 0, 0> E2 ## E4 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 0, 1> E2 ## E4 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 0, 2> E2 ## E4 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 0, 3> E2 ## E4 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 1, 0> E2 ## E4 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 1, 1> E2 ## E4 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 1, 2> E2 ## E4 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 1, 3> E2 ## E4 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 2, 0> E2 ## E4 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 2, 1> E2 ## E4 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 2, 2> E2 ## E4 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 2, 3> E2 ## E4 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 3, 0> E2 ## E4 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 3, 1> E2 ## E4 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 3, 2> E2 ## E4 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 1, 3, 3, 3> E2 ## E4 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 0, 0> E3 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 0, 1> E3 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 0, 2> E3 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 0, 3> E3 ## E1 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 1, 0> E3 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 1, 1> E3 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 1, 2> E3 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 1, 3> E3 ## E1 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 2, 0> E3 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 2, 1> E3 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 2, 2> E3 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 2, 3> E3 ## E1 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 3, 0> E3 ## E1 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 3, 1> E3 ## E1 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 3, 2> E3 ## E1 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 0, 3, 3> E3 ## E1 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 0, 0> E3 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 0, 1> E3 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 0, 2> E3 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 0, 3> E3 ## E2 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 1, 0> E3 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 1, 1> E3 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 1, 2> E3 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 1, 3> E3 ## E2 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 2, 0> E3 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 2, 1> E3 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 2, 2> E3 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 2, 3> E3 ## E2 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 3, 0> E3 ## E2 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 3, 1> E3 ## E2 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 3, 2> E3 ## E2 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 1, 3, 3> E3 ## E2 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 0, 0> E3 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 0, 1> E3 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 0, 2> E3 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 0, 3> E3 ## E3 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 1, 0> E3 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 1, 1> E3 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 1, 2> E3 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 1, 3> E3 ## E3 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 2, 0> E3 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 2, 1> E3 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 2, 2> E3 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 2, 3> E3 ## E3 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 3, 0> E3 ## E3 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 3, 1> E3 ## E3 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 3, 2> E3 ## E3 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 2, 3, 3> E3 ## E3 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 0, 0> E3 ## E4 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 0, 1> E3 ## E4 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 0, 2> E3 ## E4 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 0, 3> E3 ## E4 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 1, 0> E3 ## E4 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 1, 1> E3 ## E4 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 1, 2> E3 ## E4 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 1, 3> E3 ## E4 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 2, 0> E3 ## E4 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 2, 1> E3 ## E4 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 2, 2> E3 ## E4 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 2, 3> E3 ## E4 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 3, 0> E3 ## E4 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 3, 1> E3 ## E4 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 3, 2> E3 ## E4 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 2, 3, 3, 3> E3 ## E4 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 0, 0> E4 ## E1 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 0, 1> E4 ## E1 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 0, 2> E4 ## E1 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 0, 3> E4 ## E1 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 1, 0> E4 ## E1 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 1, 1> E4 ## E1 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 1, 2> E4 ## E1 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 1, 3> E4 ## E1 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 2, 0> E4 ## E1 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 2, 1> E4 ## E1 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 2, 2> E4 ## E1 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 2, 3> E4 ## E1 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 3, 0> E4 ## E1 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 3, 1> E4 ## E1 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 3, 2> E4 ## E1 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 0, 3, 3> E4 ## E1 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 0, 0> E4 ## E2 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 0, 1> E4 ## E2 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 0, 2> E4 ## E2 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 0, 3> E4 ## E2 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 1, 0> E4 ## E2 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 1, 1> E4 ## E2 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 1, 2> E4 ## E2 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 1, 3> E4 ## E2 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 2, 0> E4 ## E2 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 2, 1> E4 ## E2 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 2, 2> E4 ## E2 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 2, 3> E4 ## E2 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 3, 0> E4 ## E2 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 3, 1> E4 ## E2 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 3, 2> E4 ## E2 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 1, 3, 3> E4 ## E2 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 0, 0> E4 ## E3 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 0, 1> E4 ## E3 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 0, 2> E4 ## E3 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 0, 3> E4 ## E3 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 1, 0> E4 ## E3 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 1, 1> E4 ## E3 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 1, 2> E4 ## E3 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 1, 3> E4 ## E3 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 2, 0> E4 ## E3 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 2, 1> E4 ## E3 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 2, 2> E4 ## E3 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 2, 3> E4 ## E3 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 3, 0> E4 ## E3 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 3, 1> E4 ## E3 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 3, 2> E4 ## E3 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 2, 3, 3> E4 ## E3 ## E4 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 0, 0> E4 ## E4 ## E1 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 0, 1> E4 ## E4 ## E1 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 0, 2> E4 ## E4 ## E1 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 0, 3> E4 ## E4 ## E1 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 1, 0> E4 ## E4 ## E2 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 1, 1> E4 ## E4 ## E2 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 1, 2> E4 ## E4 ## E2 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 1, 3> E4 ## E4 ## E2 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 2, 0> E4 ## E4 ## E3 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 2, 1> E4 ## E4 ## E3 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 2, 2> E4 ## E4 ## E3 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 2, 3> E4 ## E4 ## E3 ## E4; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 3, 0> E4 ## E4 ## E4 ## E1; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 3, 1> E4 ## E4 ## E4 ## E2; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 3, 2> E4 ## E4 ## E4 ## E3; }; \
	struct { vmath::Swizzle<T, 4, 3, 3, 3, 3> E4 ## E4 ## E4 ## E4; };

#endif
