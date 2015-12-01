#ifndef VMATH_CORE_SWIZZLE_SWIZZLE_GEN_HPP
#define VMATH_CORE_SWIZZLE_SWIZZLE_GEN_HPP

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR2(T, E1, E2) \
		swizzle2<T, 2, 0, 0> E1 ## E1; \
		swizzle2<T, 2, 0, 1> E1 ## E2; \
		swizzle2<T, 2, 1, 0> E2 ## E1; \
		swizzle2<T, 2, 1, 1> E2 ## E2;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR2(T, E1, E2) \
		swizzle3<T, 2, 0, 0, 0> E1 ## E1 ## E1; \
		swizzle3<T, 2, 0, 0, 1> E1 ## E1 ## E2; \
		swizzle3<T, 2, 0, 1, 0> E1 ## E2 ## E1; \
		swizzle3<T, 2, 0, 1, 1> E1 ## E2 ## E2; \
		swizzle3<T, 2, 1, 0, 0> E2 ## E1 ## E1; \
		swizzle3<T, 2, 1, 0, 1> E2 ## E1 ## E2; \
		swizzle3<T, 2, 1, 1, 0> E2 ## E2 ## E1; \
		swizzle3<T, 2, 1, 1, 1> E2 ## E2 ## E2;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR2(T, E1, E2) \
		swizzle4<T, 2, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; \
		swizzle4<T, 2, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; \
		swizzle4<T, 2, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; \
		swizzle4<T, 2, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; \
		swizzle4<T, 2, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; \
		swizzle4<T, 2, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; \
		swizzle4<T, 2, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; \
		swizzle4<T, 2, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; \
		swizzle4<T, 2, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; \
		swizzle4<T, 2, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; \
		swizzle4<T, 2, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; \
		swizzle4<T, 2, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; \
		swizzle4<T, 2, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; \
		swizzle4<T, 2, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; \
		swizzle4<T, 2, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; \
		swizzle4<T, 2, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR3(T, E1, E2, E3) \
		swizzle2<T, 3, 0, 0> E1 ## E1; \
		swizzle2<T, 3, 0, 1> E1 ## E2; \
		swizzle2<T, 3, 0, 2> E1 ## E3; \
		swizzle2<T, 3, 1, 0> E2 ## E1; \
		swizzle2<T, 3, 1, 1> E2 ## E2; \
		swizzle2<T, 3, 1, 2> E2 ## E3; \
		swizzle2<T, 3, 2, 0> E3 ## E1; \
		swizzle2<T, 3, 2, 1> E3 ## E2; \
		swizzle2<T, 3, 2, 2> E3 ## E3;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR3(T, E1, E2, E3) \
		swizzle3<T, 3, 0, 0, 0> E1 ## E1 ## E1; \
		swizzle3<T, 3, 0, 0, 1> E1 ## E1 ## E2; \
		swizzle3<T, 3, 0, 0, 2> E1 ## E1 ## E3; \
		swizzle3<T, 3, 0, 1, 0> E1 ## E2 ## E1; \
		swizzle3<T, 3, 0, 1, 1> E1 ## E2 ## E2; \
		swizzle3<T, 3, 0, 1, 2> E1 ## E2 ## E3; \
		swizzle3<T, 3, 0, 2, 0> E1 ## E3 ## E1; \
		swizzle3<T, 3, 0, 2, 1> E1 ## E3 ## E2; \
		swizzle3<T, 3, 0, 2, 2> E1 ## E3 ## E3; \
		swizzle3<T, 3, 1, 0, 0> E2 ## E1 ## E1; \
		swizzle3<T, 3, 1, 0, 1> E2 ## E1 ## E2; \
		swizzle3<T, 3, 1, 0, 2> E2 ## E1 ## E3; \
		swizzle3<T, 3, 1, 1, 0> E2 ## E2 ## E1; \
		swizzle3<T, 3, 1, 1, 1> E2 ## E2 ## E2; \
		swizzle3<T, 3, 1, 1, 2> E2 ## E2 ## E3; \
		swizzle3<T, 3, 1, 2, 0> E2 ## E3 ## E1; \
		swizzle3<T, 3, 1, 2, 1> E2 ## E3 ## E2; \
		swizzle3<T, 3, 1, 2, 2> E2 ## E3 ## E3; \
		swizzle3<T, 3, 2, 0, 0> E3 ## E1 ## E1; \
		swizzle3<T, 3, 2, 0, 1> E3 ## E1 ## E2; \
		swizzle3<T, 3, 2, 0, 2> E3 ## E1 ## E3; \
		swizzle3<T, 3, 2, 1, 0> E3 ## E2 ## E1; \
		swizzle3<T, 3, 2, 1, 1> E3 ## E2 ## E2; \
		swizzle3<T, 3, 2, 1, 2> E3 ## E2 ## E3; \
		swizzle3<T, 3, 2, 2, 0> E3 ## E3 ## E1; \
		swizzle3<T, 3, 2, 2, 1> E3 ## E3 ## E2; \
		swizzle3<T, 3, 2, 2, 2> E3 ## E3 ## E3;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR3(T, E1, E2, E3) \
		swizzle4<T, 3, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; \
		swizzle4<T, 3, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; \
		swizzle4<T, 3, 0, 0, 0, 2> E1 ## E1 ## E1 ## E3; \
		swizzle4<T, 3, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; \
		swizzle4<T, 3, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; \
		swizzle4<T, 3, 0, 0, 1, 2> E1 ## E1 ## E2 ## E3; \
		swizzle4<T, 3, 0, 0, 2, 0> E1 ## E1 ## E3 ## E1; \
		swizzle4<T, 3, 0, 0, 2, 1> E1 ## E1 ## E3 ## E2; \
		swizzle4<T, 3, 0, 0, 2, 2> E1 ## E1 ## E3 ## E3; \
		swizzle4<T, 3, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; \
		swizzle4<T, 3, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; \
		swizzle4<T, 3, 0, 1, 0, 2> E1 ## E2 ## E1 ## E3; \
		swizzle4<T, 3, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; \
		swizzle4<T, 3, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; \
		swizzle4<T, 3, 0, 1, 1, 2> E1 ## E2 ## E2 ## E3; \
		swizzle4<T, 3, 0, 1, 2, 0> E1 ## E2 ## E3 ## E1; \
		swizzle4<T, 3, 0, 1, 2, 1> E1 ## E2 ## E3 ## E2; \
		swizzle4<T, 3, 0, 1, 2, 2> E1 ## E2 ## E3 ## E3; \
		swizzle4<T, 3, 0, 2, 0, 0> E1 ## E3 ## E1 ## E1; \
		swizzle4<T, 3, 0, 2, 0, 1> E1 ## E3 ## E1 ## E2; \
		swizzle4<T, 3, 0, 2, 0, 2> E1 ## E3 ## E1 ## E3; \
		swizzle4<T, 3, 0, 2, 1, 0> E1 ## E3 ## E2 ## E1; \
		swizzle4<T, 3, 0, 2, 1, 1> E1 ## E3 ## E2 ## E2; \
		swizzle4<T, 3, 0, 2, 1, 2> E1 ## E3 ## E2 ## E3; \
		swizzle4<T, 3, 0, 2, 2, 0> E1 ## E3 ## E3 ## E1; \
		swizzle4<T, 3, 0, 2, 2, 1> E1 ## E3 ## E3 ## E2; \
		swizzle4<T, 3, 0, 2, 2, 2> E1 ## E3 ## E3 ## E3; \
		swizzle4<T, 3, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; \
		swizzle4<T, 3, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; \
		swizzle4<T, 3, 1, 0, 0, 2> E2 ## E1 ## E1 ## E3; \
		swizzle4<T, 3, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; \
		swizzle4<T, 3, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; \
		swizzle4<T, 3, 1, 0, 1, 2> E2 ## E1 ## E2 ## E3; \
		swizzle4<T, 3, 1, 0, 2, 0> E2 ## E1 ## E3 ## E1; \
		swizzle4<T, 3, 1, 0, 2, 1> E2 ## E1 ## E3 ## E2; \
		swizzle4<T, 3, 1, 0, 2, 2> E2 ## E1 ## E3 ## E3; \
		swizzle4<T, 3, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; \
		swizzle4<T, 3, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; \
		swizzle4<T, 3, 1, 1, 0, 2> E2 ## E2 ## E1 ## E3; \
		swizzle4<T, 3, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; \
		swizzle4<T, 3, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2; \
		swizzle4<T, 3, 1, 1, 1, 2> E2 ## E2 ## E2 ## E3; \
		swizzle4<T, 3, 1, 1, 2, 0> E2 ## E2 ## E3 ## E1; \
		swizzle4<T, 3, 1, 1, 2, 1> E2 ## E2 ## E3 ## E2; \
		swizzle4<T, 3, 1, 1, 2, 2> E2 ## E2 ## E3 ## E3; \
		swizzle4<T, 3, 1, 2, 0, 0> E2 ## E3 ## E1 ## E1; \
		swizzle4<T, 3, 1, 2, 0, 1> E2 ## E3 ## E1 ## E2; \
		swizzle4<T, 3, 1, 2, 0, 2> E2 ## E3 ## E1 ## E3; \
		swizzle4<T, 3, 1, 2, 1, 0> E2 ## E3 ## E2 ## E1; \
		swizzle4<T, 3, 1, 2, 1, 1> E2 ## E3 ## E2 ## E2; \
		swizzle4<T, 3, 1, 2, 1, 2> E2 ## E3 ## E2 ## E3; \
		swizzle4<T, 3, 1, 2, 2, 0> E2 ## E3 ## E3 ## E1; \
		swizzle4<T, 3, 1, 2, 2, 1> E2 ## E3 ## E3 ## E2; \
		swizzle4<T, 3, 1, 2, 2, 2> E2 ## E3 ## E3 ## E3; \
		swizzle4<T, 3, 2, 0, 0, 0> E3 ## E1 ## E1 ## E1; \
		swizzle4<T, 3, 2, 0, 0, 1> E3 ## E1 ## E1 ## E2; \
		swizzle4<T, 3, 2, 0, 0, 2> E3 ## E1 ## E1 ## E3; \
		swizzle4<T, 3, 2, 0, 1, 0> E3 ## E1 ## E2 ## E1; \
		swizzle4<T, 3, 2, 0, 1, 1> E3 ## E1 ## E2 ## E2; \
		swizzle4<T, 3, 2, 0, 1, 2> E3 ## E1 ## E2 ## E3; \
		swizzle4<T, 3, 2, 0, 2, 0> E3 ## E1 ## E3 ## E1; \
		swizzle4<T, 3, 2, 0, 2, 1> E3 ## E1 ## E3 ## E2; \
		swizzle4<T, 3, 2, 0, 2, 2> E3 ## E1 ## E3 ## E3; \
		swizzle4<T, 3, 2, 1, 0, 0> E3 ## E2 ## E1 ## E1; \
		swizzle4<T, 3, 2, 1, 0, 1> E3 ## E2 ## E1 ## E2; \
		swizzle4<T, 3, 2, 1, 0, 2> E3 ## E2 ## E1 ## E3; \
		swizzle4<T, 3, 2, 1, 1, 0> E3 ## E2 ## E2 ## E1; \
		swizzle4<T, 3, 2, 1, 1, 1> E3 ## E2 ## E2 ## E2; \
		swizzle4<T, 3, 2, 1, 1, 2> E3 ## E2 ## E2 ## E3; \
		swizzle4<T, 3, 2, 1, 2, 0> E3 ## E2 ## E3 ## E1; \
		swizzle4<T, 3, 2, 1, 2, 1> E3 ## E2 ## E3 ## E2; \
		swizzle4<T, 3, 2, 1, 2, 2> E3 ## E2 ## E3 ## E3; \
		swizzle4<T, 3, 2, 2, 0, 0> E3 ## E3 ## E1 ## E1; \
		swizzle4<T, 3, 2, 2, 0, 1> E3 ## E3 ## E1 ## E2; \
		swizzle4<T, 3, 2, 2, 0, 2> E3 ## E3 ## E1 ## E3; \
		swizzle4<T, 3, 2, 2, 1, 0> E3 ## E3 ## E2 ## E1; \
		swizzle4<T, 3, 2, 2, 1, 1> E3 ## E3 ## E2 ## E2; \
		swizzle4<T, 3, 2, 2, 1, 2> E3 ## E3 ## E2 ## E3; \
		swizzle4<T, 3, 2, 2, 2, 0> E3 ## E3 ## E3 ## E1; \
		swizzle4<T, 3, 2, 2, 2, 1> E3 ## E3 ## E3 ## E2; \
		swizzle4<T, 3, 2, 2, 2, 2> E3 ## E3 ## E3 ## E3;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE2_FOR_VECTOR4(T, E1, E2, E3, E4) \
		swizzle2<T, 4, 0, 0> E1 ## E1; \
		swizzle2<T, 4, 0, 1> E1 ## E2; \
		swizzle2<T, 4, 0, 2> E1 ## E3; \
		swizzle2<T, 4, 0, 3> E1 ## E4; \
		swizzle2<T, 4, 1, 0> E2 ## E1; \
		swizzle2<T, 4, 1, 1> E2 ## E2; \
		swizzle2<T, 4, 1, 2> E2 ## E3; \
		swizzle2<T, 4, 1, 3> E2 ## E4; \
		swizzle2<T, 4, 2, 0> E3 ## E1; \
		swizzle2<T, 4, 2, 1> E3 ## E2; \
		swizzle2<T, 4, 2, 2> E3 ## E3; \
		swizzle2<T, 4, 2, 3> E3 ## E4; \
		swizzle2<T, 4, 3, 0> E4 ## E1; \
		swizzle2<T, 4, 3, 1> E4 ## E2; \
		swizzle2<T, 4, 3, 2> E4 ## E3; \
		swizzle2<T, 4, 3, 3> E4 ## E4;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE3_FOR_VECTOR4(T, E1, E2, E3, E4) \
		swizzle3<T, 4, 0, 0, 0> E1 ## E1 ## E1; \
		swizzle3<T, 4, 0, 0, 1> E1 ## E1 ## E2; \
		swizzle3<T, 4, 0, 0, 2> E1 ## E1 ## E3; \
		swizzle3<T, 4, 0, 0, 3> E1 ## E1 ## E4; \
		swizzle3<T, 4, 0, 1, 0> E1 ## E2 ## E1; \
		swizzle3<T, 4, 0, 1, 1> E1 ## E2 ## E2; \
		swizzle3<T, 4, 0, 1, 2> E1 ## E2 ## E3; \
		swizzle3<T, 4, 0, 1, 3> E1 ## E2 ## E4; \
		swizzle3<T, 4, 0, 2, 0> E1 ## E3 ## E1; \
		swizzle3<T, 4, 0, 2, 1> E1 ## E3 ## E2; \
		swizzle3<T, 4, 0, 2, 2> E1 ## E3 ## E3; \
		swizzle3<T, 4, 0, 2, 3> E1 ## E3 ## E4; \
		swizzle3<T, 4, 0, 3, 0> E1 ## E4 ## E1; \
		swizzle3<T, 4, 0, 3, 1> E1 ## E4 ## E2; \
		swizzle3<T, 4, 0, 3, 2> E1 ## E4 ## E3; \
		swizzle3<T, 4, 0, 3, 3> E1 ## E4 ## E4; \
		swizzle3<T, 4, 1, 0, 0> E2 ## E1 ## E1; \
		swizzle3<T, 4, 1, 0, 1> E2 ## E1 ## E2; \
		swizzle3<T, 4, 1, 0, 2> E2 ## E1 ## E3; \
		swizzle3<T, 4, 1, 0, 3> E2 ## E1 ## E4; \
		swizzle3<T, 4, 1, 1, 0> E2 ## E2 ## E1; \
		swizzle3<T, 4, 1, 1, 1> E2 ## E2 ## E2; \
		swizzle3<T, 4, 1, 1, 2> E2 ## E2 ## E3; \
		swizzle3<T, 4, 1, 1, 3> E2 ## E2 ## E4; \
		swizzle3<T, 4, 1, 2, 0> E2 ## E3 ## E1; \
		swizzle3<T, 4, 1, 2, 1> E2 ## E3 ## E2; \
		swizzle3<T, 4, 1, 2, 2> E2 ## E3 ## E3; \
		swizzle3<T, 4, 1, 2, 3> E2 ## E3 ## E4; \
		swizzle3<T, 4, 1, 3, 0> E2 ## E4 ## E1; \
		swizzle3<T, 4, 1, 3, 1> E2 ## E4 ## E2; \
		swizzle3<T, 4, 1, 3, 2> E2 ## E4 ## E3; \
		swizzle3<T, 4, 1, 3, 3> E2 ## E4 ## E4; \
		swizzle3<T, 4, 2, 0, 0> E3 ## E1 ## E1; \
		swizzle3<T, 4, 2, 0, 1> E3 ## E1 ## E2; \
		swizzle3<T, 4, 2, 0, 2> E3 ## E1 ## E3; \
		swizzle3<T, 4, 2, 0, 3> E3 ## E1 ## E4; \
		swizzle3<T, 4, 2, 1, 0> E3 ## E2 ## E1; \
		swizzle3<T, 4, 2, 1, 1> E3 ## E2 ## E2; \
		swizzle3<T, 4, 2, 1, 2> E3 ## E2 ## E3; \
		swizzle3<T, 4, 2, 1, 3> E3 ## E2 ## E4; \
		swizzle3<T, 4, 2, 2, 0> E3 ## E3 ## E1; \
		swizzle3<T, 4, 2, 2, 1> E3 ## E3 ## E2; \
		swizzle3<T, 4, 2, 2, 2> E3 ## E3 ## E3; \
		swizzle3<T, 4, 2, 2, 3> E3 ## E3 ## E4; \
		swizzle3<T, 4, 2, 3, 0> E3 ## E4 ## E1; \
		swizzle3<T, 4, 2, 3, 1> E3 ## E4 ## E2; \
		swizzle3<T, 4, 2, 3, 2> E3 ## E4 ## E3; \
		swizzle3<T, 4, 2, 3, 3> E3 ## E4 ## E4; \
		swizzle3<T, 4, 3, 0, 0> E4 ## E1 ## E1; \
		swizzle3<T, 4, 3, 0, 1> E4 ## E1 ## E2; \
		swizzle3<T, 4, 3, 0, 2> E4 ## E1 ## E3; \
		swizzle3<T, 4, 3, 0, 3> E4 ## E1 ## E4; \
		swizzle3<T, 4, 3, 1, 0> E4 ## E2 ## E1; \
		swizzle3<T, 4, 3, 1, 1> E4 ## E2 ## E2; \
		swizzle3<T, 4, 3, 1, 2> E4 ## E2 ## E3; \
		swizzle3<T, 4, 3, 1, 3> E4 ## E2 ## E4; \
		swizzle3<T, 4, 3, 2, 0> E4 ## E3 ## E1; \
		swizzle3<T, 4, 3, 2, 1> E4 ## E3 ## E2; \
		swizzle3<T, 4, 3, 2, 2> E4 ## E3 ## E3; \
		swizzle3<T, 4, 3, 2, 3> E4 ## E3 ## E4; \
		swizzle3<T, 4, 3, 3, 0> E4 ## E4 ## E1; \
		swizzle3<T, 4, 3, 3, 1> E4 ## E4 ## E2; \
		swizzle3<T, 4, 3, 3, 2> E4 ## E4 ## E3; \
		swizzle3<T, 4, 3, 3, 3> E4 ## E4 ## E4;

#define VMATH_CORE_SWIZZLE_GEN_SWIZZLE4_FOR_VECTOR4(T, E1, E2, E3, E4) \
		swizzle4<T, 4, 0, 0, 0, 0> E1 ## E1 ## E1 ## E1; \
		swizzle4<T, 4, 0, 0, 0, 1> E1 ## E1 ## E1 ## E2; \
		swizzle4<T, 4, 0, 0, 0, 2> E1 ## E1 ## E1 ## E3; \
		swizzle4<T, 4, 0, 0, 0, 3> E1 ## E1 ## E1 ## E4; \
		swizzle4<T, 4, 0, 0, 1, 0> E1 ## E1 ## E2 ## E1; \
		swizzle4<T, 4, 0, 0, 1, 1> E1 ## E1 ## E2 ## E2; \
		swizzle4<T, 4, 0, 0, 1, 2> E1 ## E1 ## E2 ## E3; \
		swizzle4<T, 4, 0, 0, 1, 3> E1 ## E1 ## E2 ## E4; \
		swizzle4<T, 4, 0, 0, 2, 0> E1 ## E1 ## E3 ## E1; \
		swizzle4<T, 4, 0, 0, 2, 1> E1 ## E1 ## E3 ## E2; \
		swizzle4<T, 4, 0, 0, 2, 2> E1 ## E1 ## E3 ## E3; \
		swizzle4<T, 4, 0, 0, 2, 3> E1 ## E1 ## E3 ## E4; \
		swizzle4<T, 4, 0, 0, 3, 0> E1 ## E1 ## E4 ## E1; \
		swizzle4<T, 4, 0, 0, 3, 1> E1 ## E1 ## E4 ## E2; \
		swizzle4<T, 4, 0, 0, 3, 2> E1 ## E1 ## E4 ## E3; \
		swizzle4<T, 4, 0, 0, 3, 3> E1 ## E1 ## E4 ## E4; \
		swizzle4<T, 4, 0, 1, 0, 0> E1 ## E2 ## E1 ## E1; \
		swizzle4<T, 4, 0, 1, 0, 1> E1 ## E2 ## E1 ## E2; \
		swizzle4<T, 4, 0, 1, 0, 2> E1 ## E2 ## E1 ## E3; \
		swizzle4<T, 4, 0, 1, 0, 3> E1 ## E2 ## E1 ## E4; \
		swizzle4<T, 4, 0, 1, 1, 0> E1 ## E2 ## E2 ## E1; \
		swizzle4<T, 4, 0, 1, 1, 1> E1 ## E2 ## E2 ## E2; \
		swizzle4<T, 4, 0, 1, 1, 2> E1 ## E2 ## E2 ## E3; \
		swizzle4<T, 4, 0, 1, 1, 3> E1 ## E2 ## E2 ## E4; \
		swizzle4<T, 4, 0, 1, 2, 0> E1 ## E2 ## E3 ## E1; \
		swizzle4<T, 4, 0, 1, 2, 1> E1 ## E2 ## E3 ## E2; \
		swizzle4<T, 4, 0, 1, 2, 2> E1 ## E2 ## E3 ## E3; \
		swizzle4<T, 4, 0, 1, 2, 3> E1 ## E2 ## E3 ## E4; \
		swizzle4<T, 4, 0, 1, 3, 0> E1 ## E2 ## E4 ## E1; \
		swizzle4<T, 4, 0, 1, 3, 1> E1 ## E2 ## E4 ## E2; \
		swizzle4<T, 4, 0, 1, 3, 2> E1 ## E2 ## E4 ## E3; \
		swizzle4<T, 4, 0, 1, 3, 3> E1 ## E2 ## E4 ## E4; \
		swizzle4<T, 4, 0, 2, 0, 0> E1 ## E3 ## E1 ## E1; \
		swizzle4<T, 4, 0, 2, 0, 1> E1 ## E3 ## E1 ## E2; \
		swizzle4<T, 4, 0, 2, 0, 2> E1 ## E3 ## E1 ## E3; \
		swizzle4<T, 4, 0, 2, 0, 3> E1 ## E3 ## E1 ## E4; \
		swizzle4<T, 4, 0, 2, 1, 0> E1 ## E3 ## E2 ## E1; \
		swizzle4<T, 4, 0, 2, 1, 1> E1 ## E3 ## E2 ## E2; \
		swizzle4<T, 4, 0, 2, 1, 2> E1 ## E3 ## E2 ## E3; \
		swizzle4<T, 4, 0, 2, 1, 3> E1 ## E3 ## E2 ## E4; \
		swizzle4<T, 4, 0, 2, 2, 0> E1 ## E3 ## E3 ## E1; \
		swizzle4<T, 4, 0, 2, 2, 1> E1 ## E3 ## E3 ## E2; \
		swizzle4<T, 4, 0, 2, 2, 2> E1 ## E3 ## E3 ## E3; \
		swizzle4<T, 4, 0, 2, 2, 3> E1 ## E3 ## E3 ## E4; \
		swizzle4<T, 4, 0, 2, 3, 0> E1 ## E3 ## E4 ## E1; \
		swizzle4<T, 4, 0, 2, 3, 1> E1 ## E3 ## E4 ## E2; \
		swizzle4<T, 4, 0, 2, 3, 2> E1 ## E3 ## E4 ## E3; \
		swizzle4<T, 4, 0, 2, 3, 3> E1 ## E3 ## E4 ## E4; \
		swizzle4<T, 4, 0, 3, 0, 0> E1 ## E4 ## E1 ## E1; \
		swizzle4<T, 4, 0, 3, 0, 1> E1 ## E4 ## E1 ## E2; \
		swizzle4<T, 4, 0, 3, 0, 2> E1 ## E4 ## E1 ## E3; \
		swizzle4<T, 4, 0, 3, 0, 3> E1 ## E4 ## E1 ## E4; \
		swizzle4<T, 4, 0, 3, 1, 0> E1 ## E4 ## E2 ## E1; \
		swizzle4<T, 4, 0, 3, 1, 1> E1 ## E4 ## E2 ## E2; \
		swizzle4<T, 4, 0, 3, 1, 2> E1 ## E4 ## E2 ## E3; \
		swizzle4<T, 4, 0, 3, 1, 3> E1 ## E4 ## E2 ## E4; \
		swizzle4<T, 4, 0, 3, 2, 0> E1 ## E4 ## E3 ## E1; \
		swizzle4<T, 4, 0, 3, 2, 1> E1 ## E4 ## E3 ## E2; \
		swizzle4<T, 4, 0, 3, 2, 2> E1 ## E4 ## E3 ## E3; \
		swizzle4<T, 4, 0, 3, 2, 3> E1 ## E4 ## E3 ## E4; \
		swizzle4<T, 4, 0, 3, 3, 0> E1 ## E4 ## E4 ## E1; \
		swizzle4<T, 4, 0, 3, 3, 1> E1 ## E4 ## E4 ## E2; \
		swizzle4<T, 4, 0, 3, 3, 2> E1 ## E4 ## E4 ## E3; \
		swizzle4<T, 4, 0, 3, 3, 3> E1 ## E4 ## E4 ## E4; \
		swizzle4<T, 4, 1, 0, 0, 0> E2 ## E1 ## E1 ## E1; \
		swizzle4<T, 4, 1, 0, 0, 1> E2 ## E1 ## E1 ## E2; \
		swizzle4<T, 4, 1, 0, 0, 2> E2 ## E1 ## E1 ## E3; \
		swizzle4<T, 4, 1, 0, 0, 3> E2 ## E1 ## E1 ## E4; \
		swizzle4<T, 4, 1, 0, 1, 0> E2 ## E1 ## E2 ## E1; \
		swizzle4<T, 4, 1, 0, 1, 1> E2 ## E1 ## E2 ## E2; \
		swizzle4<T, 4, 1, 0, 1, 2> E2 ## E1 ## E2 ## E3; \
		swizzle4<T, 4, 1, 0, 1, 3> E2 ## E1 ## E2 ## E4; \
		swizzle4<T, 4, 1, 0, 2, 0> E2 ## E1 ## E3 ## E1; \
		swizzle4<T, 4, 1, 0, 2, 1> E2 ## E1 ## E3 ## E2; \
		swizzle4<T, 4, 1, 0, 2, 2> E2 ## E1 ## E3 ## E3; \
		swizzle4<T, 4, 1, 0, 2, 3> E2 ## E1 ## E3 ## E4; \
		swizzle4<T, 4, 1, 0, 3, 0> E2 ## E1 ## E4 ## E1; \
		swizzle4<T, 4, 1, 0, 3, 1> E2 ## E1 ## E4 ## E2; \
		swizzle4<T, 4, 1, 0, 3, 2> E2 ## E1 ## E4 ## E3; \
		swizzle4<T, 4, 1, 0, 3, 3> E2 ## E1 ## E4 ## E4; \
		swizzle4<T, 4, 1, 1, 0, 0> E2 ## E2 ## E1 ## E1; \
		swizzle4<T, 4, 1, 1, 0, 1> E2 ## E2 ## E1 ## E2; \
		swizzle4<T, 4, 1, 1, 0, 2> E2 ## E2 ## E1 ## E3; \
		swizzle4<T, 4, 1, 1, 0, 3> E2 ## E2 ## E1 ## E4; \
		swizzle4<T, 4, 1, 1, 1, 0> E2 ## E2 ## E2 ## E1; \
		swizzle4<T, 4, 1, 1, 1, 1> E2 ## E2 ## E2 ## E2; \
		swizzle4<T, 4, 1, 1, 1, 2> E2 ## E2 ## E2 ## E3; \
		swizzle4<T, 4, 1, 1, 1, 3> E2 ## E2 ## E2 ## E4; \
		swizzle4<T, 4, 1, 1, 2, 0> E2 ## E2 ## E3 ## E1; \
		swizzle4<T, 4, 1, 1, 2, 1> E2 ## E2 ## E3 ## E2; \
		swizzle4<T, 4, 1, 1, 2, 2> E2 ## E2 ## E3 ## E3; \
		swizzle4<T, 4, 1, 1, 2, 3> E2 ## E2 ## E3 ## E4; \
		swizzle4<T, 4, 1, 1, 3, 0> E2 ## E2 ## E4 ## E1; \
		swizzle4<T, 4, 1, 1, 3, 1> E2 ## E2 ## E4 ## E2; \
		swizzle4<T, 4, 1, 1, 3, 2> E2 ## E2 ## E4 ## E3; \
		swizzle4<T, 4, 1, 1, 3, 3> E2 ## E2 ## E4 ## E4; \
		swizzle4<T, 4, 1, 2, 0, 0> E2 ## E3 ## E1 ## E1; \
		swizzle4<T, 4, 1, 2, 0, 1> E2 ## E3 ## E1 ## E2; \
		swizzle4<T, 4, 1, 2, 0, 2> E2 ## E3 ## E1 ## E3; \
		swizzle4<T, 4, 1, 2, 0, 3> E2 ## E3 ## E1 ## E4; \
		swizzle4<T, 4, 1, 2, 1, 0> E2 ## E3 ## E2 ## E1; \
		swizzle4<T, 4, 1, 2, 1, 1> E2 ## E3 ## E2 ## E2; \
		swizzle4<T, 4, 1, 2, 1, 2> E2 ## E3 ## E2 ## E3; \
		swizzle4<T, 4, 1, 2, 1, 3> E2 ## E3 ## E2 ## E4; \
		swizzle4<T, 4, 1, 2, 2, 0> E2 ## E3 ## E3 ## E1; \
		swizzle4<T, 4, 1, 2, 2, 1> E2 ## E3 ## E3 ## E2; \
		swizzle4<T, 4, 1, 2, 2, 2> E2 ## E3 ## E3 ## E3; \
		swizzle4<T, 4, 1, 2, 2, 3> E2 ## E3 ## E3 ## E4; \
		swizzle4<T, 4, 1, 2, 3, 0> E2 ## E3 ## E4 ## E1; \
		swizzle4<T, 4, 1, 2, 3, 1> E2 ## E3 ## E4 ## E2; \
		swizzle4<T, 4, 1, 2, 3, 2> E2 ## E3 ## E4 ## E3; \
		swizzle4<T, 4, 1, 2, 3, 3> E2 ## E3 ## E4 ## E4; \
		swizzle4<T, 4, 1, 3, 0, 0> E2 ## E4 ## E1 ## E1; \
		swizzle4<T, 4, 1, 3, 0, 1> E2 ## E4 ## E1 ## E2; \
		swizzle4<T, 4, 1, 3, 0, 2> E2 ## E4 ## E1 ## E3; \
		swizzle4<T, 4, 1, 3, 0, 3> E2 ## E4 ## E1 ## E4; \
		swizzle4<T, 4, 1, 3, 1, 0> E2 ## E4 ## E2 ## E1; \
		swizzle4<T, 4, 1, 3, 1, 1> E2 ## E4 ## E2 ## E2; \
		swizzle4<T, 4, 1, 3, 1, 2> E2 ## E4 ## E2 ## E3; \
		swizzle4<T, 4, 1, 3, 1, 3> E2 ## E4 ## E2 ## E4; \
		swizzle4<T, 4, 1, 3, 2, 0> E2 ## E4 ## E3 ## E1; \
		swizzle4<T, 4, 1, 3, 2, 1> E2 ## E4 ## E3 ## E2; \
		swizzle4<T, 4, 1, 3, 2, 2> E2 ## E4 ## E3 ## E3; \
		swizzle4<T, 4, 1, 3, 2, 3> E2 ## E4 ## E3 ## E4; \
		swizzle4<T, 4, 1, 3, 3, 0> E2 ## E4 ## E4 ## E1; \
		swizzle4<T, 4, 1, 3, 3, 1> E2 ## E4 ## E4 ## E2; \
		swizzle4<T, 4, 1, 3, 3, 2> E2 ## E4 ## E4 ## E3; \
		swizzle4<T, 4, 1, 3, 3, 3> E2 ## E4 ## E4 ## E4; \
		swizzle4<T, 4, 2, 0, 0, 0> E3 ## E1 ## E1 ## E1; \
		swizzle4<T, 4, 2, 0, 0, 1> E3 ## E1 ## E1 ## E2; \
		swizzle4<T, 4, 2, 0, 0, 2> E3 ## E1 ## E1 ## E3; \
		swizzle4<T, 4, 2, 0, 0, 3> E3 ## E1 ## E1 ## E4; \
		swizzle4<T, 4, 2, 0, 1, 0> E3 ## E1 ## E2 ## E1; \
		swizzle4<T, 4, 2, 0, 1, 1> E3 ## E1 ## E2 ## E2; \
		swizzle4<T, 4, 2, 0, 1, 2> E3 ## E1 ## E2 ## E3; \
		swizzle4<T, 4, 2, 0, 1, 3> E3 ## E1 ## E2 ## E4; \
		swizzle4<T, 4, 2, 0, 2, 0> E3 ## E1 ## E3 ## E1; \
		swizzle4<T, 4, 2, 0, 2, 1> E3 ## E1 ## E3 ## E2; \
		swizzle4<T, 4, 2, 0, 2, 2> E3 ## E1 ## E3 ## E3; \
		swizzle4<T, 4, 2, 0, 2, 3> E3 ## E1 ## E3 ## E4; \
		swizzle4<T, 4, 2, 0, 3, 0> E3 ## E1 ## E4 ## E1; \
		swizzle4<T, 4, 2, 0, 3, 1> E3 ## E1 ## E4 ## E2; \
		swizzle4<T, 4, 2, 0, 3, 2> E3 ## E1 ## E4 ## E3; \
		swizzle4<T, 4, 2, 0, 3, 3> E3 ## E1 ## E4 ## E4; \
		swizzle4<T, 4, 2, 1, 0, 0> E3 ## E2 ## E1 ## E1; \
		swizzle4<T, 4, 2, 1, 0, 1> E3 ## E2 ## E1 ## E2; \
		swizzle4<T, 4, 2, 1, 0, 2> E3 ## E2 ## E1 ## E3; \
		swizzle4<T, 4, 2, 1, 0, 3> E3 ## E2 ## E1 ## E4; \
		swizzle4<T, 4, 2, 1, 1, 0> E3 ## E2 ## E2 ## E1; \
		swizzle4<T, 4, 2, 1, 1, 1> E3 ## E2 ## E2 ## E2; \
		swizzle4<T, 4, 2, 1, 1, 2> E3 ## E2 ## E2 ## E3; \
		swizzle4<T, 4, 2, 1, 1, 3> E3 ## E2 ## E2 ## E4; \
		swizzle4<T, 4, 2, 1, 2, 0> E3 ## E2 ## E3 ## E1; \
		swizzle4<T, 4, 2, 1, 2, 1> E3 ## E2 ## E3 ## E2; \
		swizzle4<T, 4, 2, 1, 2, 2> E3 ## E2 ## E3 ## E3; \
		swizzle4<T, 4, 2, 1, 2, 3> E3 ## E2 ## E3 ## E4; \
		swizzle4<T, 4, 2, 1, 3, 0> E3 ## E2 ## E4 ## E1; \
		swizzle4<T, 4, 2, 1, 3, 1> E3 ## E2 ## E4 ## E2; \
		swizzle4<T, 4, 2, 1, 3, 2> E3 ## E2 ## E4 ## E3; \
		swizzle4<T, 4, 2, 1, 3, 3> E3 ## E2 ## E4 ## E4; \
		swizzle4<T, 4, 2, 2, 0, 0> E3 ## E3 ## E1 ## E1; \
		swizzle4<T, 4, 2, 2, 0, 1> E3 ## E3 ## E1 ## E2; \
		swizzle4<T, 4, 2, 2, 0, 2> E3 ## E3 ## E1 ## E3; \
		swizzle4<T, 4, 2, 2, 0, 3> E3 ## E3 ## E1 ## E4; \
		swizzle4<T, 4, 2, 2, 1, 0> E3 ## E3 ## E2 ## E1; \
		swizzle4<T, 4, 2, 2, 1, 1> E3 ## E3 ## E2 ## E2; \
		swizzle4<T, 4, 2, 2, 1, 2> E3 ## E3 ## E2 ## E3; \
		swizzle4<T, 4, 2, 2, 1, 3> E3 ## E3 ## E2 ## E4; \
		swizzle4<T, 4, 2, 2, 2, 0> E3 ## E3 ## E3 ## E1; \
		swizzle4<T, 4, 2, 2, 2, 1> E3 ## E3 ## E3 ## E2; \
		swizzle4<T, 4, 2, 2, 2, 2> E3 ## E3 ## E3 ## E3; \
		swizzle4<T, 4, 2, 2, 2, 3> E3 ## E3 ## E3 ## E4; \
		swizzle4<T, 4, 2, 2, 3, 0> E3 ## E3 ## E4 ## E1; \
		swizzle4<T, 4, 2, 2, 3, 1> E3 ## E3 ## E4 ## E2; \
		swizzle4<T, 4, 2, 2, 3, 2> E3 ## E3 ## E4 ## E3; \
		swizzle4<T, 4, 2, 2, 3, 3> E3 ## E3 ## E4 ## E4; \
		swizzle4<T, 4, 2, 3, 0, 0> E3 ## E4 ## E1 ## E1; \
		swizzle4<T, 4, 2, 3, 0, 1> E3 ## E4 ## E1 ## E2; \
		swizzle4<T, 4, 2, 3, 0, 2> E3 ## E4 ## E1 ## E3; \
		swizzle4<T, 4, 2, 3, 0, 3> E3 ## E4 ## E1 ## E4; \
		swizzle4<T, 4, 2, 3, 1, 0> E3 ## E4 ## E2 ## E1; \
		swizzle4<T, 4, 2, 3, 1, 1> E3 ## E4 ## E2 ## E2; \
		swizzle4<T, 4, 2, 3, 1, 2> E3 ## E4 ## E2 ## E3; \
		swizzle4<T, 4, 2, 3, 1, 3> E3 ## E4 ## E2 ## E4; \
		swizzle4<T, 4, 2, 3, 2, 0> E3 ## E4 ## E3 ## E1; \
		swizzle4<T, 4, 2, 3, 2, 1> E3 ## E4 ## E3 ## E2; \
		swizzle4<T, 4, 2, 3, 2, 2> E3 ## E4 ## E3 ## E3; \
		swizzle4<T, 4, 2, 3, 2, 3> E3 ## E4 ## E3 ## E4; \
		swizzle4<T, 4, 2, 3, 3, 0> E3 ## E4 ## E4 ## E1; \
		swizzle4<T, 4, 2, 3, 3, 1> E3 ## E4 ## E4 ## E2; \
		swizzle4<T, 4, 2, 3, 3, 2> E3 ## E4 ## E4 ## E3; \
		swizzle4<T, 4, 2, 3, 3, 3> E3 ## E4 ## E4 ## E4; \
		swizzle4<T, 4, 3, 0, 0, 0> E4 ## E1 ## E1 ## E1; \
		swizzle4<T, 4, 3, 0, 0, 1> E4 ## E1 ## E1 ## E2; \
		swizzle4<T, 4, 3, 0, 0, 2> E4 ## E1 ## E1 ## E3; \
		swizzle4<T, 4, 3, 0, 0, 3> E4 ## E1 ## E1 ## E4; \
		swizzle4<T, 4, 3, 0, 1, 0> E4 ## E1 ## E2 ## E1; \
		swizzle4<T, 4, 3, 0, 1, 1> E4 ## E1 ## E2 ## E2; \
		swizzle4<T, 4, 3, 0, 1, 2> E4 ## E1 ## E2 ## E3; \
		swizzle4<T, 4, 3, 0, 1, 3> E4 ## E1 ## E2 ## E4; \
		swizzle4<T, 4, 3, 0, 2, 0> E4 ## E1 ## E3 ## E1; \
		swizzle4<T, 4, 3, 0, 2, 1> E4 ## E1 ## E3 ## E2; \
		swizzle4<T, 4, 3, 0, 2, 2> E4 ## E1 ## E3 ## E3; \
		swizzle4<T, 4, 3, 0, 2, 3> E4 ## E1 ## E3 ## E4; \
		swizzle4<T, 4, 3, 0, 3, 0> E4 ## E1 ## E4 ## E1; \
		swizzle4<T, 4, 3, 0, 3, 1> E4 ## E1 ## E4 ## E2; \
		swizzle4<T, 4, 3, 0, 3, 2> E4 ## E1 ## E4 ## E3; \
		swizzle4<T, 4, 3, 0, 3, 3> E4 ## E1 ## E4 ## E4; \
		swizzle4<T, 4, 3, 1, 0, 0> E4 ## E2 ## E1 ## E1; \
		swizzle4<T, 4, 3, 1, 0, 1> E4 ## E2 ## E1 ## E2; \
		swizzle4<T, 4, 3, 1, 0, 2> E4 ## E2 ## E1 ## E3; \
		swizzle4<T, 4, 3, 1, 0, 3> E4 ## E2 ## E1 ## E4; \
		swizzle4<T, 4, 3, 1, 1, 0> E4 ## E2 ## E2 ## E1; \
		swizzle4<T, 4, 3, 1, 1, 1> E4 ## E2 ## E2 ## E2; \
		swizzle4<T, 4, 3, 1, 1, 2> E4 ## E2 ## E2 ## E3; \
		swizzle4<T, 4, 3, 1, 1, 3> E4 ## E2 ## E2 ## E4; \
		swizzle4<T, 4, 3, 1, 2, 0> E4 ## E2 ## E3 ## E1; \
		swizzle4<T, 4, 3, 1, 2, 1> E4 ## E2 ## E3 ## E2; \
		swizzle4<T, 4, 3, 1, 2, 2> E4 ## E2 ## E3 ## E3; \
		swizzle4<T, 4, 3, 1, 2, 3> E4 ## E2 ## E3 ## E4; \
		swizzle4<T, 4, 3, 1, 3, 0> E4 ## E2 ## E4 ## E1; \
		swizzle4<T, 4, 3, 1, 3, 1> E4 ## E2 ## E4 ## E2; \
		swizzle4<T, 4, 3, 1, 3, 2> E4 ## E2 ## E4 ## E3; \
		swizzle4<T, 4, 3, 1, 3, 3> E4 ## E2 ## E4 ## E4; \
		swizzle4<T, 4, 3, 2, 0, 0> E4 ## E3 ## E1 ## E1; \
		swizzle4<T, 4, 3, 2, 0, 1> E4 ## E3 ## E1 ## E2; \
		swizzle4<T, 4, 3, 2, 0, 2> E4 ## E3 ## E1 ## E3; \
		swizzle4<T, 4, 3, 2, 0, 3> E4 ## E3 ## E1 ## E4; \
		swizzle4<T, 4, 3, 2, 1, 0> E4 ## E3 ## E2 ## E1; \
		swizzle4<T, 4, 3, 2, 1, 1> E4 ## E3 ## E2 ## E2; \
		swizzle4<T, 4, 3, 2, 1, 2> E4 ## E3 ## E2 ## E3; \
		swizzle4<T, 4, 3, 2, 1, 3> E4 ## E3 ## E2 ## E4; \
		swizzle4<T, 4, 3, 2, 2, 0> E4 ## E3 ## E3 ## E1; \
		swizzle4<T, 4, 3, 2, 2, 1> E4 ## E3 ## E3 ## E2; \
		swizzle4<T, 4, 3, 2, 2, 2> E4 ## E3 ## E3 ## E3; \
		swizzle4<T, 4, 3, 2, 2, 3> E4 ## E3 ## E3 ## E4; \
		swizzle4<T, 4, 3, 2, 3, 0> E4 ## E3 ## E4 ## E1; \
		swizzle4<T, 4, 3, 2, 3, 1> E4 ## E3 ## E4 ## E2; \
		swizzle4<T, 4, 3, 2, 3, 2> E4 ## E3 ## E4 ## E3; \
		swizzle4<T, 4, 3, 2, 3, 3> E4 ## E3 ## E4 ## E4; \
		swizzle4<T, 4, 3, 3, 0, 0> E4 ## E4 ## E1 ## E1; \
		swizzle4<T, 4, 3, 3, 0, 1> E4 ## E4 ## E1 ## E2; \
		swizzle4<T, 4, 3, 3, 0, 2> E4 ## E4 ## E1 ## E3; \
		swizzle4<T, 4, 3, 3, 0, 3> E4 ## E4 ## E1 ## E4; \
		swizzle4<T, 4, 3, 3, 1, 0> E4 ## E4 ## E2 ## E1; \
		swizzle4<T, 4, 3, 3, 1, 1> E4 ## E4 ## E2 ## E2; \
		swizzle4<T, 4, 3, 3, 1, 2> E4 ## E4 ## E2 ## E3; \
		swizzle4<T, 4, 3, 3, 1, 3> E4 ## E4 ## E2 ## E4; \
		swizzle4<T, 4, 3, 3, 2, 0> E4 ## E4 ## E3 ## E1; \
		swizzle4<T, 4, 3, 3, 2, 1> E4 ## E4 ## E3 ## E2; \
		swizzle4<T, 4, 3, 3, 2, 2> E4 ## E4 ## E3 ## E3; \
		swizzle4<T, 4, 3, 3, 2, 3> E4 ## E4 ## E3 ## E4; \
		swizzle4<T, 4, 3, 3, 3, 0> E4 ## E4 ## E4 ## E1; \
		swizzle4<T, 4, 3, 3, 3, 1> E4 ## E4 ## E4 ## E2; \
		swizzle4<T, 4, 3, 3, 3, 2> E4 ## E4 ## E4 ## E3; \
		swizzle4<T, 4, 3, 3, 3, 3> E4 ## E4 ## E4 ## E4;

#endif
