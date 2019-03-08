#pragma once

#include <vector>

#include "../graphics/scene.h"

namespace dg { namespace app {
	
	class Application
	{
	public:
		bool running = false;

		graphics::Scene currentScene;
		std::vector<graphics::Scene> scenes;
		
		void start();

		virtual void onInit() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy() = 0;
	};

} }