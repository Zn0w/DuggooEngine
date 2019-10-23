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

	window.properties = properties;
}

Application::~Application()
{
	
}

void Application::start()
{
	// init other systems (maybe not here)
	
	if (!window.init())
	{
		printf("GLFW failed\n");
		return;
	}

	input.setWindow(window.windowHandle);

	debug_info.init(window.windowHandle);

	running = true;
	onInit();

	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	printf("GPU vendor: %s\n", glGetString(GL_VENDOR));
	printf("GPU model: %s\n", glGetString(GL_RENDERER));


	while (running && !window.isClosed())
	{	
		onUpdate(clock.getDeltaTime());
		

		// engine-specific input handling (e.g. press F3 to enter engine debug mode)
		if (input.isKeyTyped(DG_KEY_F3))
		{
			if (debug_info.debug_mode)
				debug_info.debug_mode = false;
			else
				debug_info.debug_mode = true;
		}

		debug_info.render();

		window.refresh();
	}

	debug_info.destroy();

	window.destroy();

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }