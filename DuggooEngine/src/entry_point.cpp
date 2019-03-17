#include "entry_point.h"

#include "duggoo/graphics/window.h"
#include "duggoo/graphics/platform/OpenglWindow.h"

#include "duggoo.h"

#include <iostream>

#include "duggoo/math/matrix.h"

class SandboxApp : public dg::app::Application
{
public:
	void onInit()
	{
		if (!dg::graphics::opengl::initWindow(1280, 720, "This is a test!"))
			running = false;

		// Matrix4 test
		
		dg::math::Matrix4 m1, m2;

		for (int i = 0; i < 16; i++)
		{
			m1.elements[i] = i;
			m2.elements[i] = i;
		}
		
		dg::math::Matrix4 m = dg::math::multiply(m1, m2);
		
		std::cout << dg::math::equals(m1, m2) << std::endl;

		std::cout << dg::math::equals(m, m2) << std::endl;

		std::cout << m.elements[0] << "  " << m.elements[1] << "  " << m.elements[2] << "  " << m.elements[3] << std::endl;
		std::cout << m.elements[4] << "  " << m.elements[5] << "  " << m.elements[6] << "  " << m.elements[7] << std::endl;
		std::cout << m.elements[8] << "  " << m.elements[9] << "  " << m.elements[10] << "  " << m.elements[11] << std::endl;
		std::cout << m.elements[12] << "  " << m.elements[13] << "  " << m.elements[14] << "  " << m.elements[15] << std::endl;
	}

	void onUpdate()
	{
		// NOTE: maybe carry out basic graphics operations in the application class
		if (!dg::graphics::opengl::windowClosed())
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.8f, 0.4f, 0.0f);

			if (dg::input::isKeyPressed(DG_KEY_F))
				LOG_INFO("An F key is pressed!");
			
			if (dg::input::isMouseButtonPressed(DG_MOUSE_BUTTON_LEFT))
			{
				LOG_INFO("Left mouse button is pressed!");
				
				int x, y;
				dg::input::getMousePosition(&x, &y);
				std::cout << "Mouse coordinates: " << x << "    " << y << std::endl;
			}

			dg::graphics::opengl::windowRefresh();
		}
		else
			running = false;
	}

	void onDestroy()
	{
		dg::graphics::opengl::windowDestroy();
	}
};

void start()
{
	// Testing logger
	LOG_TRACE("trace message");
	LOG_INFO("info message");
	LOG_WARN("warning message");
	LOG_ERROR("error message");
	LOG_FATAL("fatal message");

	SandboxApp game;
	game.start();
}