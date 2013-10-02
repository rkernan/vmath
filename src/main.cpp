#include <iostream>
#include "math/types.hpp"

int main(int argc, const char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		std::string arg(argv[i]);
		if (arg == std::string("-test") || arg == std::string("-t")) {
			std::cout << sizeof(math::vector2) << std::endl;
			std::cout << sizeof(float[2]) << std::endl;
			math::vector2 v1;
			std::cout << v1 << std::endl;
			math::vector2 v2(1.0f, 2.0f);
			std::cout << v1 + v2 << std::endl;
		}
	}
	return 0;
}
