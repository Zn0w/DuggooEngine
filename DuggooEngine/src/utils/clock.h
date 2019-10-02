// For now the clock uses glfw, later provide multiple options (chrono, windows, ...)

#pragma once

#include <glfw/glfw3.h>

namespace dg { namespace clock {
	
	class Clock
	{
	private:
		float last_frame_time = 0.0f;

	public:
		float getDeltaTime()
		{
			float time = (float) glfwGetTime();
			float delta_time = time - last_frame_time;
			last_frame_time = time;

			return delta_time;
		}
	};

} }