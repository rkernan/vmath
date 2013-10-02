#ifndef MATH_CORE_SWIZZLE_INL
#define MATH_CORE_SWIZZLE_INL

#include "swizzle.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

using namespace math::core;

/**
 *
 */
template<typename T, int N, int E1, int E2>
Swizzle2<T, N, E1, E2>::operator vector2<T>() {
	return vector2<T>(this->values[E1], this->values[E2]);
}

/**
 *
 */
template<typename T, int N, int E1, int E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator=(const vector2<T>& V) {
	// TODO possible if: N == 2 && E1 != E2
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	return *(vector2<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator+=(const vector2<T>& V) {
	// TODO possible if: N == 2 && E1 != E2
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	return *(vector2<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator-=(const vector2<T>& V) {
	// TODO possible if: N == 2 && E1 != E2
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	return *(vector2<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator*=(const vector2<T>& V) {
	// TODO possible if: N == 2 && E1 != E2
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	return *(vector2<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2>
vector2<T>& Swizzle2<T, N, E1, E2>::operator/=(const vector2<T>& V) {
	// TODO possible if: N == 2 && E1 != E2
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	return *(vector2<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
Swizzle3<T, N, E1, E2, E3>::operator vector3<T>() {
	return vector3<T>(this->values[E1], this->values[E2], this->values[E3]);
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator=(const vector3<T>& V) {
	// TODO possible if: N == 3 && E1 != E2 != E3
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator+=(const vector3<T>& V) {
	// TODO possible if: N == 3 && E1 != E2 != E3
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->valeus[E3] += V.z;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator-=(const vector3<T>& V) {
	// TODO possible if: N == 3 && E1 != E2 != E3
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator*=(const vector3<T>& V) {
	// TODO possible if: N == 3 && E1 != E2 != E3
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3>
vector3<T>& Swizzle3<T, N, E1, E2, E3>::operator/=(const vector3<T>& V) {
	// TODO possible if: N == 3 && E1 != E2 != E3
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
Swizzle4<T, N, E1, E2, E3, E4>::operator vector4<T>() {
	return vector4<T>(this->values[E1], this->values[E2], this->values[E3], this->values[E4]);
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator=(const vector4<T>& V) {
	// TODO possible if: N == 4 && E1 != E2 != E3 != E4
	this->values[E1] = V.x;
	this->values[E2] = V.y;
	this->values[E3] = V.z;
	this->values[E4] = V.w;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator+=(const vector4<T>& V) {
	// TODO possible if: N == 4 && E1 != E2 != E3 != E4
	this->values[E1] += V.x;
	this->values[E2] += V.y;
	this->values[E3] += V.z;
	this->values[E4] += V.w;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator-=(const vector4<T>& V) {
	// TODO possible if: N == 4 && E1 != E2 != E3 != E4
	this->values[E1] -= V.x;
	this->values[E2] -= V.y;
	this->values[E3] -= V.z;
	this->values[E4] -= V.w;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator*=(const vector4<T>& V) {
	// TODO possible if: N == 4 && E1 != E2 != E3 != E4
	this->values[E1] *= V.x;
	this->values[E2] *= V.y;
	this->values[E3] *= V.z;
	this->values[E4] *= V.w;
	return *(vector3<T>*)this;
}

/**
 *
 */
template<typename T, int N, int E1, int E2, int E3, int E4>
vector4<T>& Swizzle4<T, N, E1, E2, E3, E4>::operator/=(const vector4<T>& V) {
	// TODO possible if: N == 4 && E1 != E2 != E3 != E4
	this->values[E1] /= V.x;
	this->values[E2] /= V.y;
	this->values[E3] /= V.z;
	this->values[E4] /= V.w;
	return *(vector3<T>*)this;
}

#endif
