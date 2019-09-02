#include "entry_point.h"

#include "duggoo/graphics/window/window.h"
#include "duggoo/graphics/window/platform/OpenglWindow.h"

#include "duggoo.h"

#include <iostream>

#include "duggoo/math/matrix.h"

// Testing a 2D Opengl renderer
#include "duggoo/graphics/renderer/opengl/gl_simple_2d_renderer.h"
dg::graphics::SimpleRenderer2D renderer;

class SandboxApp : public dg::app::Application
{
public:
	void onInit()
	{
		// Testing a 2D Opengl renderer
		renderer.submit(new dg::graphics::Renderable2D(
			dg::math::Vector3(200, 200, 0),
			dg::math::Vector2(100, 100),
			dg::math::Vector4(0, 255, 0, 255)
		));
		
		if (!dg::graphics::opengl::initWindow(1280, 720, "This is a test!"))
			running = false;
	}

	void onUpdate()
	{
		// NOTE: maybe carry out basic graphics operations in the application class
		if (!dg::graphics::opengl::windowClosed())
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.8f, 0.4f, 0.0f);

			// Testing a 2D Opengl renderer
			renderer.flush();

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