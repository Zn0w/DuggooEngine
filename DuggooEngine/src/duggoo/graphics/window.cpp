#include "window.h"

namespace Duggoo
{	namespace graphics {

	Window createWindow(int x, int y, int width, int height, const char* title)
	{
		Window w;
		w.title = title;
		w.x = x;
		w.y = y;
		w.width = width;
		w.height = height;

		/* Initialize the library */
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW." << std::endl;
			return w; // Need to be changed
		}

		/* Create a windowed mode window and its OpenGL context */
		w.glfw_window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
		if (!w.glfw_window)
		{
			glfwTerminate();
			std::cout << "Failed to create a GLFW window." << std::endl;
			return w; // Need to be changed
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(w.glfw_window);

		return w;
	}

	bool isOpen(Window w)
	{
		return !glfwWindowShouldClose(w.glfw_window);
	}

	void updateWindow(Window w) // This function will be renamed and will return invoked events of the window
	{
		/* Poll for and process events */
		glfwPollEvents();
	}

	void close()
	{
		glfwTerminate();
	}

} }