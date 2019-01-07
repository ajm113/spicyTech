#include "system.hpp"


int main(int argc, char* argv[]) {
	// Create spicy engine.
	spiceSystem* spice = new spiceSystem();
	if(!spice->Init()) {
		return 1;
	}

	spice->Run();

	return 0;
}
