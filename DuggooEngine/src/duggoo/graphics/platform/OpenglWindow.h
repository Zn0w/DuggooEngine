#pragma once

#include "../window.h"

#include "../../event/key_event.h"
#include "../../event/mouse_event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace dg { namespace graphics { namespace opengl {

	struct OpenglWindow
	{
		WindowData windowData;
		GLFWwindow* windowHandle;
	};

	static OpenglWindow window;		// NOTE: static global variable is automatically initialized to zero

	static void(*onEvent) (event::Event event);

	void setOnEvent(void(*onEventImpl) (event::Event event))
	{
		onEvent = onEventImpl;
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (onEvent != NULL)
		{
			if (action == GLFW_PRESS)
			{
				event::KeyEvent keyEvent(event::KEY_PRESS, key);
				onEvent(keyEvent);
			}
			else if (action == GLFW_RELEASE)
			{
				event::KeyEvent keyEvent(event::KEY_RELEASE, key);
				onEvent(keyEvent);
			}
			else if (action == GLFW_REPEAT)
			{
				event::KeyEvent keyEvent(event::KEY_TYPE, key);
				onEvent(keyEvent);
			}
		}
	}

	void mouseCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		if (onEvent != NULL)
		{
			event::MouseMoveEvent mouseEvent(event::MOUSE_MOVE, xpos, ypos, 0, 0);
			onEvent(mouseEvent);
		}
	}

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (onEvent != NULL)
		{
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);

			if (action == GLFW_PRESS)
			{
				event::MouseButtonEvent mouseEvent(event::MOUSE_PRESS, xpos, ypos, button);
				onEvent(mouseEvent);
			}
			else if (action == GLFW_RELEASE)
			{
				event::MouseButtonEvent mouseEvent(event::MOUSE_RELEASE, xpos, ypos, button);
				onEvent(mouseEvent);
			}
		}
	}

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

		glfwSetKeyCallback(window.windowHandle, keyCallback);
		glfwSetCursorPosCallback(window.windowHandle, mouseCursorPosCallback);
		glfwSetMouseButtonCallback(window.windowHandle, mouseButtonCallback);

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