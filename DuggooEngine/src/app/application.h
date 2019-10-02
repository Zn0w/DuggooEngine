#pragma once

#include <chrono>
#include <iostream>

#include "../graphics/render/renderer.h"
#include "../utils/clock.h"

namespace dg { namespace app {
	
	// NOTE: may be renamed after other components of the engine are introduced
	class Application
	{
	private:
		graphics::Renderer renderer;
		Clock clock;

	public:
		bool running = false;
		
		Application() {}
		~Application() {}
		
		void start();
		void stop();

		// Game-specific
		virtual void onInit() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy() = 0;
	};

} }