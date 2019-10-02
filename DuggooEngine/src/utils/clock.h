// For now the clock uses glfw, later provide multiple options (chrono, windows, ...)

#pragma once

namespace dg {
	
	class Clock
	{
	public:
		// returns time in seconds
		float getTime()
		{
			return glfwGetTime();
		}

		// returns time in milliseconds
		float getTimeMs()
		{
			return glfwGetTime() * 1000.0f;
		}
	};

}