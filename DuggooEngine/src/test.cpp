#include "test.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void openWindow()
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

	while (!glfwWindowShouldClose(window))
	{
		//glClearColor(1, 1, 1, 1);
		//glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}

	glfwTerminate();
}