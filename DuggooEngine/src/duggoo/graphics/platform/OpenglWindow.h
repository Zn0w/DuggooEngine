#pragma once

#include "../window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace dg { namespace graphics {

	struct OpenglWindow
	{

		WindowData windowData;
		GLFWwindow* windowHandle;

	};

	bool initOpenglWindow(OpenglWindow* window)
	{
		if (!glfwInit())
			return false;

		window->windowHandle = glfwCreateWindow(
												window->windowData.width, 
												window->windowData.height,
												window->windowData.title, 
												NULL, NULL				// NOTE: the last 2 arguments NULL for now
												);
		if (!window->windowHandle)
		{
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window->windowHandle);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);		// NOTE: In order to be able to use opengl functions

		return true;
	}

} }