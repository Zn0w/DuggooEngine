#include "test.h"

#include <iostream>

#include <GLFW/glfw3.h>

namespace Duggoo
{

	bool game_running;
	GLFWwindow* window;
	
	void start()
	{
		std::cout << "Hello from Duggoo Engine!" << std::endl;

		game_running = true;
		int count = 0;

		/* Initialize the library */
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW." << std::endl;
			return;
		}

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			std::cout << "Failed to create a GLFW window." << std::endl;
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		std::cout << "Game init" << std::endl;

		/* Loop until the user closes the window or the game stops*/
		while (game_running && !glfwWindowShouldClose(window))
		{
			count++;
			game_running = count < 1000;

			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();

			std::cout << "Game refresh" << std::endl;
		}

		std::cout << "Game destroy" << std::endl;

		glfwTerminate();
	}

}