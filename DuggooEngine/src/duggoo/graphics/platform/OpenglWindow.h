#pragma once

#include "../window.h"

#include "../../event/key_event.h"
#include "../../event/mouse_event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace dg { namespace graphics { namespace opengl {

	struct OpenglWindow
	{
		WindowData windowData;
		GLFWwindow* windowHandle;
	};

	static OpenglWindow window;		// NOTE: static global variable is automatically initialized to zero

	bool initWindow(int width, int height, const char* title)
	{
		window.windowData.width = width;
		window.windowData.height = height;
		window.windowData.title = title;
		
		if (!glfwInit())
			return false;

		window.windowHandle = glfwCreateWindow(
												window.windowData.width,
												window.windowData.height,
												window.windowData.title,
												NULL, NULL				// NOTE: the last 2 arguments NULL for now
											  );
		if (!window.windowHandle)
		{
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window.windowHandle);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);		// NOTE: In order to be able to use opengl functions

		return true;
	}

	bool windowClosed()
	{
		return glfwWindowShouldClose(window.windowHandle);
	}

	void windowRefresh()
	{
		glfwSwapBuffers(window.windowHandle);

		glfwPollEvents();
	}

	void windowDestroy()
	{
		glfwTerminate();
	}

} } }