#include "system.hpp"

bool spiceSystem::Init() {
	glfwSetErrorCallback(spiceSystem::ErrorCallback);
	// Initalize logger first and setup enviroment.
	m_logger = new spiceLogger();

	if (!m_logger) {
		return false;
	}

	m_logger->Printf("Starting %s (%s)...", GAME_TITLE, ENGINE_VERSION);

	// Setup GLFW init to render our window and context.
	if (!glfwInit()) {
		m_logger->Printf("Unable to initialize GLFW");
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
		m_logger->Printf("Unable to initialize glad");
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	PrintGLDetails();

	return true;
}

bool spiceSystem::Run() {
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

void spiceSystem::ErrorCallback(int error, const char* description) {
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

void spiceSystem::PrintGLDetails() {
	m_logger->Printf("GL_RENDERER: %s", glGetString(GL_RENDERER));
	m_logger->Printf("GL_EXTENSIONS: %s", glGetString(GL_EXTENSIONS));
}
