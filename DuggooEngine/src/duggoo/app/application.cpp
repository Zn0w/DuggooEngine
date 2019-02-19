#include "application.h"

#include <chrono>

#include <iostream>

namespace dg { namespace app {

	void Application::start()
	{
		running = true;

		onInit();

		auto startTime = std::chrono::steady_clock::now();
		auto startSec = std::chrono::steady_clock::now();

		int frames = 0;

		while (running)
		{
			// handle time
			auto endTime = std::chrono::steady_clock::now();
			auto endSec = std::chrono::steady_clock::now();
			std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
			std::chrono::duration<double, std::milli> elapsedTimeSec = endSec - startSec;
			//startTime = std::chrono::steady_clock::now();

			if (elapsedTimeSec.count() >= 1000.0)
			{
				frames = 0;
				startSec = std::chrono::steady_clock::now();
			}
			
			// 67 frames per second
			if (elapsedTime.count() < 15.0)
				continue;

			startTime = std::chrono::steady_clock::now();
			frames++;
			
			onUpdate();
			std::cout << frames << std::endl;
		}

		onDestroy();
	}

	void Application::onDestroy()
	{
		
	}

} }