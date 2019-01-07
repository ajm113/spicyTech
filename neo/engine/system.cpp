#include "system.hpp"

bool spiceSystem::init() {
	glfwSetErrorCallback(spiceSystem::errorCallback);
	// Initalize logger first and setup enviroment.
	m_logger = new spiceLogger();

	if (!m_logger) {
		return false;
	}

	m_logger->Printf("Starting game.");

	// Setup GLFW init to render our window and context.
	if (!glfwInit()) {
		m_logger->Printf("Unable to initialize GLFW\n");
		return false;
	}

	// Set our context to tuse OpenGL 3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	m_window = glfwCreateWindow(1280, 720, GAME_TITLE, nullptr, nullptr);
	if (!m_window) {
		m_logger->Printf("Unable to create GLFW window!");
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);

	// Create our OpenGL context to render.
	if (!gladLoadGL()) {
		m_logger->Printf("Unable to initialize glad\n");
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	printGLDetails();

	return true;
}

bool spiceSystem::run() {
   // Set the clear color to a nice green
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   while (!glfwWindowShouldClose(m_window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(m_window);
      glfwPollEvents();
   }

   glfwDestroyWindow(m_window);
   m_window = nullptr;
   glfwTerminate();

   return true;
}

void spiceSystem::errorCallback(int error, const char* description) {
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

void spiceSystem::printGLDetails() {
	m_logger->Printf("GL_RENDERER: %s", glGetString(GL_RENDERER));
	m_logger->Printf("GL_EXTENSIONS: %s", glGetString(GL_EXTENSIONS));
}
