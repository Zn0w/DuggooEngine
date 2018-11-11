#pragma once

#include "../graphics/window.h"
#include "../graphics/renderer.h"

namespace Duggoo
{	namespace app {

	// I will probably make some kind of an abstact class instead of struct, virtual functions should be:
	//																								gameUpdate()
	//																								handleWindowEvents()
	//																								that's it for now
	struct Application
	{
		bool game_running;
		Duggoo::graphics::Window window;

		void draw()
		{
			Duggoo::graphics::prepareRender();
			Duggoo::graphics::render(window);
		}

		void update() // A user of the engine will be able to (and should) override this function
		{
			Duggoo::graphics::updateWindow(window);
		}
	};

} }