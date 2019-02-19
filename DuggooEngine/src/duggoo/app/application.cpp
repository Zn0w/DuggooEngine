#include "application.h"

namespace dg { namespace app {

	void Application::start()
	{
		running = true;

		onInit();

		while (running)
		{
			// handle time
			
			onUpdate();
		}

		onDestroy();
	}

	void Application::onDestroy()
	{
		
	}

} }