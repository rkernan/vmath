#include <iostream>
#include "math/types.hpp"

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string arg(argv[i]);
		if (arg == std::string("-test") || arg == std::string("-t")) {
			static_assert(sizeof(math::vector2) == sizeof(float[2]), "sizeof(vector2) != sizeof(float[2])");
			static_assert(sizeof(math::vector3) == sizeof(float[3]), "sizeof(vector3) != sizeof(float[3])");
			static_assert(sizeof(math::vector4) == sizeof(float[4]), "sizeof(vector4) != sizeof(float[4])");
		}
	}
	return 0;
}
