#include "window.h"


namespace dg { namespace graphics {

bool Window::init()
{
	if (!glfwInit())
		return false;

	if (properties.fullscreen)
		windowHandle = glfwCreateWindow(properties.width, properties.height, properties.title, glfwGetPrimaryMonitor(), NULL);
	else
		windowHandle = glfwCreateWindow(properties.width, properties.height, properties.title, NULL, NULL);

	if (!windowHandle)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(windowHandle);

	if (properties.vsync)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return false;
	}

	return true;
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(windowHandle);
}

void Window::refresh()
{
	glfwSwapBuffers(windowHandle);

	glfwPollEvents();
}

void Window::destroy()
{
	glfwDestroyWindow(windowHandle);
	glfwTerminate();
}

} }