#include <iostream>
#include <vector>
#include "math/types.hpp"

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string arg(argv[i]);
		if (arg.compare(std::string("-test")) == 0 || arg.compare(std::string("-t")) == 0) {
			// static_assert(sizeof(math::Vector2) == sizeof(float[2]), "sizeof(vector2) != sizeof(float[2])");
			// static_assert(sizeof(math::Vector3) == sizeof(float[3]), "sizeof(vector3) != sizeof(float[3])");
			// static_assert(sizeof(math::Vector4) == sizeof(float[4]), "sizeof(vector4) != sizeof(float[4])");
			// math::Vector2 V(1.0f, 2.0f);
			// std::cout << V << std::endl;
			// V.yx = math::Vector2(3.0f, 1.0f);
			// std::cout << V << std::endl;
			// V.xx = math::Vector2(0.0f, 0.0f); // compile error
		}
	}
	std::cout << "    Vector1: " << sizeof(math::core::Vector<float, 1>) << std::endl;
	std::cout << "   float[1]: " << sizeof(float[1]) << std::endl;
	std::cout << "    Vector2: " << sizeof(math::Vector2) << std::endl;
	std::cout << "   float[2]: " << sizeof(float[2]) << std::endl;
	std::cout << "    Vector3: " << sizeof(math::Vector3) << std::endl;
	std::cout << "   float[3]: " << sizeof(float[3]) << std::endl;
	std::cout << "    Vector4: " << sizeof(math::Vector4) << std::endl;
	std::cout << "   float[4]: " << sizeof(float[4]) << std::endl;
	std::cout << "    Vector5: " << sizeof(math::core::Vector<float, 5>) << std::endl;
	std::cout << "   float[5]: " << sizeof(float[5]) << std::endl;
	math::core::Vector<float, 2> v1(1.0f, 2.0f);
	math::core::Vector<float, 2> v2;
	std::cout << (v2 + v1) << std::endl;
	v1 == v2;
	float r1 = Vector<float, 2>::cross(v1, v2);
	math::core::Vector<float, 3> v3;
	math::core::Vector<float, 3> v4;
	math::core::Vector<float, 3> r2 = Vector<float, 3>::cross(v3, v4);

#if defined(WINDOWS)
	while(1) {}
#endif
	return 0;
}
