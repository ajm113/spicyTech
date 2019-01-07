#include "system.hpp"


int main(int argc, char* argv[]) {
	// Create spicy engine.
	spiceSystem* spice = new spiceSystem();
	if(!spice->init()) {
		return 1;
	}

	spice->run();

	return 0;
}
