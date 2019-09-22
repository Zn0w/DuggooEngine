#include "application.h"

namespace dg { namespace app {

void Application::start()
{
	// init other systems (maybe not here)
	
	running = true;
	onInit();

	std::chrono::steady_clock::time_point start_time = std::chrono::high_resolution_clock::now();
	while (running)
	{	
		// update other systems (e.g. physics system) (maybe not here)
		renderer.render();

		onUpdate();

		std::chrono::steady_clock::time_point end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> delta_time = end_time - start_time;
		start_time = end_time;

		std::cout << delta_time.count() << std::endl;
	}

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }