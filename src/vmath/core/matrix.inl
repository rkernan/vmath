#ifndef VMATH_CORE_MATRIX_INL
#define VMATH_CORE_MATRIX_INL

#include <vmath/core/matrix.hpp>

#include <cmath>

namespace vmath {
namespace core {

template<typename T, std::size_t M, std::size_t N>
Vector<T, M> Matrix<T, M, N>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

template<typename T, std::size_t M, std::size_t N>
Vector<T, M>& Matrix<T, M, N>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator-() const {
	Matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = -this->data[i];
	}
	return R;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator+=(const Matrix<T, M, N>& w) {
	for (std::size_t i = 0; i < N; i++) {
		this->data[i] = this->data[i] + w.data[i];
	}
	return *this;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator-=(const Matrix<T, M, N>& w) {
	for (std::size_t i = 0; i < N; i++) {
		this->data[i] = this->data[i] - w.data[i];
	}
	return *this;
}

template<typename T, std::size_t M, std::size_t N>
template<std::size_t P>
Matrix<T, M, P> Matrix<T, M, N>::operator*(const Matrix<T, N, P>& w) const {
	Matrix<T, M, P> res;
	for (std::size_t m = 0; m < M; m++) {
		for (std::size_t p = 0; p < P; p++) {
			for (std::size_t n = 0; n < N; n++) {
				res[p][m] += this->data[n][m] * w[p][n];
			}
		}
	}
	return res;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator*=(const T s) {
	for (std::size_t i = 0; i < N; i++) {
		this->data[i] = this->data[i] * s;
	}
	return *this;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, M, N>& Matrix<T, M, N>::operator/=(const T s) {
	for (std::size_t i = 0; i < N; i++) {
		this->data[i] = this->data[i] / s;
	}
	return *this;
}

template<typename T, std::size_t M, std::size_t N>
Matrix<T, N, M> Matrix<T, M, N>::transpose() const {
	Matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = 0; j < M; j++) {
			R.data[j][i] = this->data[i][j];
		}
	}
	return R;
}

template<typename T, std::size_t M, std::size_t N>
bool Matrix<T, M, N>::equals(const Matrix<T, M, N>& other) const {
	bool equal = true;
	for (std::size_t i = 0; i < N; i++) {
		equal = equal && this->data[i] == other.data[i];
	}
	return equal;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
T Matrix<T, M, N>::minor(const std::size_t row, const std::size_t col) const {
	Matrix<T, M - 1, N - 1> minor_mat;
	std::size_t i = (col == 0) ? 1 : 0;
	std::size_t i_minor = 0;
	while (i_minor < N - 1) {
		std::size_t j_minor = 0;
		std::size_t j = (row == 0) ? 1 : 0;
		while (j_minor < M - 1) {
			minor_mat[i_minor][j_minor] = this->data[i][j];
			j_minor++;
			j = (j + 1 == row) ? (j + 2) : (j + 1);
		}
		i_minor++;
		i = (i + 1 == col) ? (i + 2) : (i + 1);
	}
	return minor_mat.det();
}

/**
 * \brief Calculate the Matrix determinant of a generic size Matrix
 * \param[in] mat Matrix to calculate the determinant of
 * \return Matrix determinant
 */
template<typename T, std::size_t M, std::size_t N>
static inline T det_helper(const Matrix<T, M, N>& mat) {
	T det = T();
	T mod = static_cast<T>(1);
	for (std::size_t i = 0; i < N; i++) {
		det += mod * mat.data[0][i] * mat.minor(i, 0);
		mod = -mod;
	}
	return det;
}
/**
 * \brief Calculate the Matrix determinant of a 1x1 Matrix
 * \param[in] mat Matrix to calculate the determinant of
 * \return Matrix determinant
 */
template<typename T>
static inline T det_helper(const Matrix<T, 1>& mat) {
	return mat.data[0][0];
}

/**
 * \brief Calculate the Matrix determinant of a 2x2 Matrix
 * \param[in] mat Matrix to calculate the determinant of
 * \return Matrix determinant
 */
template<typename T>
static inline T det_helper(const Matrix<T, 2>& mat) {
	return (mat.data[0][0] * mat.data[1][1]) - (mat.data[1][0] * mat.data[0][1]);
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
T Matrix<T, M, N>::det() const {
	return det_helper(*this);
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::minors() const {
	Matrix<T, M, N> minor;
	for (std::size_t i = 0; i < M; i++) {
		for (std::size_t j = 0; j < N; j++) {
			minor[j][i] = this->minor(i, j);
		}
	}
	return minor;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::cofactor() const {
	Matrix<T, M, N> cofactor(this->minors());
	T mod_row = -static_cast<T>(1);
	for (std::size_t i = 0; i < M; i++) {
		mod_row = -mod_row;
		T mod_col = mod_row;
		for (std::size_t j = 0; j < N; j++) {
			cofactor[j][i] *= mod_col;
			mod_col = -mod_col;
		}
	}
	return cofactor;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::adjugate() const {
	return this->cofactor().transpose();
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::inverse() const {
	return this->adjugate() / this->det();
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::translation(const Vector<T, 3>& disp) {
	Matrix<T, M, N> transform;
	transform[0][0] = static_cast<T>(1.0);
	transform[1][1] = static_cast<T>(1.0);
	transform[2][2] = static_cast<T>(1.0);
	transform[3][0] = disp.x;
	transform[3][1] = disp.y;
	transform[3][2] = disp.z;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::rotation(const Vector<T, 3>& out, const Vector<T, 3>& up) {
	Matrix<T, M, N> transform;
	Vector<T, 3> right(Vector<T, 3>::cross(out, up).normal());
	Vector<T, 3> local_up(Vector<T, 3>::cross(right, out));
	transform[0].xyz = right;
	transform[1].xyz = local_up;
	transform[2].xyz = -out;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::scale(const T x_scale, const T y_scale, const T z_scale) {
	Matrix<T, M, N> transform;
	transform[0][0] = x_scale;
	transform[1][1] = y_scale;
	transform[2][2] = z_scale;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::orthographic(const T left, const T right, const T bottom, const T top, const T near, const T far) {
	Matrix<T, M, N> proj;
	proj[0][0] = static_cast<T>(2.0) / (right - left);
	proj[1][1] = static_cast<T>(2.0) / (top - bottom);
	proj[2][2] = static_cast<T>(-2.0) / (far - near);
	proj[3][0] = -((right + left) / (right - left));
	proj[3][1] = -((top + bottom) / (top - bottom));
	proj[3][2] = -((far + near) / (far - near));
	proj[3][3] = static_cast<T>(1.0);
	return proj;
}

template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
Matrix<T, M, N> Matrix<T, M, N>::perspective(const T fov, const T aspect, const T  near, const T far) {
	Matrix<T, M, N> proj;
	T y_scale = static_cast<T>(1.0) / std::tan(fov / static_cast<T>(2.0));
	T x_scale = y_scale / aspect;
	proj[0][0] = x_scale;
	proj[1][1] = y_scale;
	proj[2][2] = (far + near) / (near - far);
	proj[3][2] = (static_cast<T>(2.0) * far * near) / (near - far);
	return proj;
}

}
}

#endif
