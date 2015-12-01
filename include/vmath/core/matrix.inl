#ifndef VMATH_CORE_MATRIX_INL
#define VMATH_CORE_MATRIX_INL

#include <vmath/core/matrix.hpp>

namespace vmath {
namespace core {

/**
 * Access a matrix element using an index.
 * @param idx Location of element to access.
 * @return Accessed element.
 */
template<typename T, std::size_t M, std::size_t N>
vector<T, M> matrix<T, M, N>::operator[](const std::size_t idx) const {
	return this->data.at(idx);
}

/**
 * Add and modify a vector element by index.
 * @param idx Location of element to access.
 * @return Modified element.
 */
template<typename T, std::size_t M, std::size_t N>
vector<T, M>& matrix<T, M, N>::operator[](const std::size_t idx) {
	return this->data.at(idx);
}

/**
 * Negate a matrix.
 * @return The matrix negated.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N> matrix<T, M, N>::operator-(void) const {
	matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = -this->data[i];
	}
	return R;
}

/**
 * matrix addition.
 * @param W matrix to add.
 * @return The matrix sum.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N> matrix<T, M, N>::operator+(const matrix<T, M, N>& W) const {
	matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] + W.data[i];
	}
	return R;
}

/**
 * matrix addition. Copy the result into this matrix.
 * @param W matrix to add.
 * @return The modified matrix (matrix sum).
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N>& matrix<T, M, N>::operator+=(const matrix<T, M, N>& W) {
	return *this = *this + W;
}

/**
 * matrix subtraction.
 * @param W matrix to subtract.
 * @return The matrix difference.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N> matrix<T, M, N>::operator-(const matrix<T, M, N>& W) const {
	matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] - W.data[i];
	}
	return R;
}

/**
 * matrix subtraction. Copy the result into this matrix.
 * @param W matrix to subtract.
 * @return The modified matrix (matrix difference).
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N>& matrix<T, M, N>::operator-=(const matrix<T, M, N>& W) {
	return *this = *this - W;
}

/**
 * matrix multiplication.
 * @param W matrix to multiply by.
 * @return matrix product.
 */
template<typename T, std::size_t M, std::size_t N>
template<std::size_t P>
matrix<T, M, P> matrix<T, M, N>::operator*(const matrix<T, N, P>& W) const {
	matrix<T, M, P> R;
	for (std::size_t m = 0; m < M; m++) {
		for (std::size_t p = 0; p < P; p++) {
			for (std::size_t n = 0; n < N; n++) {
				R[p][m] += this->data[n][m] * W[p][n];
			}
		}
	}
	return R;
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @return matrix-scalar product.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N> matrix<T, M, N>::operator*(const T& s) const {
	matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] * s;
	}
	return R;
}

/**
 * Scalar multiplication. Copy the result into this matrix.
 * @param s Scalar to multiply by.
 * @return The modified matrix (matrix-scalar product).
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N>& matrix<T, M, N>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Scalar division.
 * @param s Scalar to divide by.
 * @return matrix-scalar quotient.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N> matrix<T, M, N>::operator/(const T& s) const {
	matrix<T, M, N> R;
	for (std::size_t i = 0; i < N; i++) {
		R.data[i] = this->data[i] / s;
	}
	return R;
}

/**
 * Scalar division. Copy the result into this matrix.
 * @param s Scalar to divide by.
 * @return The modified matrix (matrix-scalar quotient).
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, M, N>& matrix<T, M, N>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Traspose this matrix.
 * @return matrix transpose.
 */
template<typename T, std::size_t M, std::size_t N>
matrix<T, N, M> matrix<T, M, N>::transpose(void) const {
	matrix<T, N, M> R;
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = 0; j < M; j++) {
			R.data[j][i] = this->data[i][j];
		}
	}
	return R;
}

/**
 * Check matrix equality.
 * @param other matrix to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t M, std::size_t N>
bool matrix<T, M, N>::operator==(const matrix<T, M, N>& other) const {
	bool equal = true;
	for (std::size_t i = 0; i < N; i++) {
		equal = equal && this->data[i] == other.data[i];
	}
	return equal;
}

/**
 * Check matrix inequality.
 * @param other matrix to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t M, std::size_t N>
bool matrix<T, M, N>::operator!=(const matrix<T, M, N>& other) const {
	return !(*this == other);
}

/**
 * Calculate the matrix minor.
 * @param row Row of element to calculate minor for.
 * @param col Column of element to calculate minor for.
 * @return matrix minor of the element at the given position.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
T matrix<T, M, N>::minor(const std::size_t row, const std::size_t col) const {
	matrix<T, M - 1, N - 1> minor_mat;
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
 * Determinant helper. Allows for partial specialization of the determinant.
 * @param mat matrix to calculate the determinant of.
 * @return matrix determinant.
 */
template<typename T, std::size_t M, std::size_t N>
static inline T det_helper(const matrix<T, M, N>& mat) {
	T det = T();
	T mod = static_cast<T>(1);
	for (std::size_t i = 0; i < N; i++) {
		det += mod * mat.data[0][i] * mat.minor(i, 0);
		mod = -mod;
	}
	return det;
}
/**
 * Determinant helper. Allows for partial specialization of the determinant.
 * 1x1 matrix specialization.
 * @param mat matrix to calculate the determinant of.
 * @return matrix determinant.
 */
template<typename T>
static inline T det_helper(const matrix<T, 1>& mat) {
	return mat.data[0][0];
}

/**
 * Determinant helper. Allows for partial specialization of the determinant.
 * 2x2 matrix specialization.
 * @param mat matrix to calculate the determinant of.
 * @return matrix determinant.
 */
template<typename T>
static inline T det_helper(const matrix<T, 2>& mat) {
	return (mat.data[0][0] * mat.data[1][1]) - (mat.data[1][0] * mat.data[0][1]);
}

/**
 * Calculate this matrix determinant.
 * @return matrix determinant.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
T matrix<T, M, N>::det(void) const {
	return det_helper(*this);
}

/**
 * Calculate the matrix of minors.
 * @return matrix of minors.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::minors(void) const {
	matrix<T, M, N> minor;
	for (std::size_t i = 0; i < M; i++) {
		for (std::size_t j = 0; j < N; j++) {
			minor[j][i] = this->minor(i, j);
		}
	}
	return minor;
}

/**
 * Calculate the cofactor matrix.
 * @return Cofactor matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::cofactor(void) const {
	matrix<T, M, N> cofactor(this->minors());
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

/**
 * Calculate the matrix adjugate.
 * @return matrix adjugate.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::adjugate(void) const {
	return this->cofactor().transpose();
}

/**
 * Calculate the matrix inverse.
 * @return matrix inverse.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::inverse(void) const {
	return this->adjugate() / this->det();
}

/**
 * Create an affine translation matrix.
 * @param disp Vector displacement.
 * @return Translation matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::translation(const vector<T, 3>& disp) {
	matrix<T, M, N> transform;
	transform[0][0] = static_cast<T>(1.0);
	transform[1][1] = static_cast<T>(1.0);
	transform[2][2] = static_cast<T>(1.0);
	transform[3][0] = disp.x;
	transform[3][1] = disp.y;
	transform[3][2] = disp.z;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

/**
 * Create an affine rotation matrix.
 * @param out Outwards direction.
 * @param up Upwards direction.
 * @return Rotation matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::rotation(const vector<T, 3>& out, const vector<T, 3>& up) {
	matrix<T, M, N> transform;
	vector<T, 3> right(vector<T, 3>::cross(out, up).normal());
	vector<T, 3> local_up(vector<T, 3>::cross(right, out));
	transform[0].xyz = right;
	transform[1].xyz = local_up;
	transform[2].xyz = -out;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

/**
 * Create an affine scale scale matrix.
 * @param x_scale Scale in the x-direction.
 * @param y_scale Scale in the y-direction.
 * @param z_scale Scale in the z-direction.
 * @return Scale matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::scale(const T& x_scale, const T& y_scale, const T& z_scale) {
	matrix<T, M, N> transform;
	transform[0][0] = x_scale;
	transform[1][1] = y_scale;
	transform[2][2] = z_scale;
	transform[3][3] = static_cast<T>(1.0);
	return transform;
}

/**
 * Create an otrhographic projection matrix.
 * @param left
 * @param right
 * @param bottom
 * @param top
 * @param near The near clipping plane.
 * @param far The far clipping plane.
 * @return Projection matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::orthographic(const T& left, const T& right,
		const T& bottom, const T& top, const T& near, const T& far) {
	matrix<T, M, N> proj;
	proj[0][0] = static_cast<T>(2.0) / (right - left);
	proj[1][1] = static_cast<T>(2.0) / (top - bottom);
	proj[2][2] = static_cast<T>(-2.0) / (far - near);
	proj[3][0] = -((right + left) / (right - left));
	proj[3][1] = -((top + bottom) / (top - bottom));
	proj[3][2] = -((far + near) / (far - near));
	proj[3][3] = static_cast<T>(1.0);
	return proj;
}

/**
 * Create a perspective projection matrix.
 * @param fov The field of view.
 * @param aspect The screen's aspect ratio.
 * @param near The near clipping plane.
 * @param far The far clipping plane.
 * @return Projection matrix.
 */
template<typename T, std::size_t M, std::size_t N>
template<typename U, typename>
matrix<T, M, N> matrix<T, M, N>::perspective(const T& fov, const T& aspect,
		const T&  near, const T& far) {
	matrix<T, M, N> proj;
	T y_scale = static_cast<T>(1.0) / vmath::tan(fov / static_cast<T>(2.0));
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
