#include "entry_point.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void start()
{
	GLFWwindow* window;

	if (!glfwInit())
		return;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);		// In ordred to be able to use opengl functions

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.8f, 0.4f, 0.0f);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
}