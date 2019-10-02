#include "application.h"

namespace dg { namespace app {

void Application::start()
{
	// init other systems (maybe not here)
	
	running = true;
	onInit();

	float last_frame_time = 0.0f;
	while (running)
	{	
		onUpdate(clock.getDeltaTime());

		// update other systems (e.g. physics system) (maybe not here)
		renderer.render();
	}

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }