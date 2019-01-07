#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "logger.hpp"
#include "license.hpp"

class spiceSystem {
public:
	bool init();
	bool run();

	static void errorCallback(int error, const char* description);
protected:
	GLFWwindow* m_window;
	spiceLogger* m_logger;
private:

	void printGLDetails();
};


#endif
