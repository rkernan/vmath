#ifndef MATH_CORE_VECTOR2_HPP
#define MATH_CORE_VECTOR2_HPP

#include <ostream>

namespace math {
namespace core {

template<typename T>
class vector2 {
public:
	vector2(void);
	vector2(const T&, const T&);
	vector2(const vector2<T>&) = default;
	vector2(vector2<T>&&) = default;
	~vector2(void) = default;

	vector2<T>& operator=(const vector2<T>&);
	vector2<T> operator-(void) const;
	vector2<T> operator+(const vector2<T>&) const;
	vector2<T>& operator+=(const vector2<T>&);
	vector2<T> operator-(const vector2<T>&) const;
	vector2<T>& operator-=(const vector2<T>&);
	vector2<T> operator*(const vector2<T>&) const;
	vector2<T>& operator*=(const vector2<T>&);
	vector2<T> operator/(const vector2<T>&) const;
	vector2<T>& operator/=(const vector2<T>&);
	T norm(void) const;
	T mag(void) const;
	vector2<T> normal(void) const;
	vector2<T>& normalize(void);

	bool operator==(const vector2<T>&) const;
	bool operator!=(const vector2<T>&) const;
	
	static T dot(const vector2<T>&, const vector2<T>&);
	static T cross(const vector2<T>&, const vector2<T>&);
	static vector2<T> reflect(const vector2<T>&, const vector2<T>&);
	static vector2<T> refract(const vector2<T>&, const vector2<T>&, const T&);
	static vector2<T> lerp(const vector2<T>&, const vector2<T>&, const T&);

	T x, y;
};

template<typename T>
vector2<T> operator*(const T&, const vector2<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const vector2<T>&);

}
}

#include "vector2.inl"

#endif
