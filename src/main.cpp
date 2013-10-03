#include <iostream>
#include "math/types.hpp"

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string arg(argv[i]);
		if (arg.compare(std::string("-test")) == 0 || arg.compare(std::string("-t")) == 0) {
			static_assert(sizeof(math::Vector2) == sizeof(float[2]), "sizeof(vector2) != sizeof(float[2])");
			static_assert(sizeof(math::Vector3) == sizeof(float[3]), "sizeof(vector3) != sizeof(float[3])");
			static_assert(sizeof(math::Vector4) == sizeof(float[4]), "sizeof(vector4) != sizeof(float[4])");
			math::Vector2 v1(1.0f, 1.0f);
			math::Vector2 v2(0.0f, 3.0f);
			std::cout << (v1 + v2.xy) << std::endl;
			std::cout << (v1 + v2.yx) << std::endl;
		}
	}
	return 0;
}
