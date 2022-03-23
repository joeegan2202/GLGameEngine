#include "setup.hpp"
#include "../engine/engine.hpp"

extern GLFWwindow* window;

void error_callback(int error, const char* description);

bool initializeGL()
{
	glewExperimental = GL_TRUE; 

	if(!glfwInit())
	{
		std::cout << "Could not initialize GLFW!\n";
		return false;
	}

	glfwSetErrorCallback(error_callback);

	window = glfwCreateWindow(640, 480, "Test Window", NULL, NULL);

	if(!window)
	{
		std::cout << "Failed to create window!!!\n";
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	glewInit();

  return true;
}

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}