#include "test.h"

#include <iostream>

#include <GLFW/glfw3.h>

namespace Duggoo
{

	//bool game_running;
	
	void start()
	{
		/*std::cout << "Hello from Duggoo Engine!" << std::endl;

		game_running = true;
		int count = 0;

		std::cout << "Game init" << std::endl;

		while (game_running)
		{
			count++;
			game_running = count < 1000;

			std::cout << "Game refresh" << std::endl;
		}

		std::cout << "Game destroy" << std::endl;
		
		system("pause");*/

		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
	}

}