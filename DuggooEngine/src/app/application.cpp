#include "application.h"


namespace dg { namespace app {

Application::Application(graphics::WindowProperties properties, RenderType render_type)
{
	switch (render_type)
	{
	case OPENGL_2D :
		// renderer = new Renderer2D;
		break;

	case OPENGL_3D :
		// renderer = new Renderer3D;
		break;
	}

	graphics::window.properties = properties;
}

Application::~Application()
{
	
}

void Application::start()
{
	// init other systems (maybe not here)
	
	if (!dg::graphics::initWindow())
	{
		printf("GLFW failed\n");
		return;
	}

	running = true;
	onInit();

	float last_frame_time = 0.0f;
	while (running && !dg::graphics::windowClosed())
	{	
		onUpdate(clock.getDeltaTime());

		// update other systems (e.g. physics system) (maybe not here)
		renderer.render();

		dg::graphics::windowRefresh();
	}

	graphics::windowDestroy();

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }