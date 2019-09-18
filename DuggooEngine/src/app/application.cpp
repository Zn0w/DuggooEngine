#include "application.h"

namespace dg { namespace app {

void Application::start()
{
	// init other systems (maybe not here)
	
	running = true;
	onInit();

	while (running)
	{
		// update other systems (e.g. physics system) (maybe not here)
		renderer.render();

		onUpdate();
	}

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }