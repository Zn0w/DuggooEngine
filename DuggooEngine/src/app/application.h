#pragma once

#include <stdio.h>

#include "../graphics/window/window.h"
#include "../graphics/render/renderer.h"

#include "../utils/clock.h"

#include "../input/input.h"
#include "../input/keycodes.h"

#include "../gui/debug_gui.h"

namespace dg { namespace app {
	
	enum RenderType
	{
		OPENGL_2D,
		OPENGL_3D,
		CUSTOM
	};

	class Application
	{
	public:
		bool running = false;
	private:
		graphics::OrthographicCamera camera;
		clock::Clock clock;
		graphics::Window window;
		gui::DebugGui debug_info;
	protected:
		input::Input input;

	public:
		Application(graphics::WindowProperties, RenderType);
		~Application();
		
		void start();
		void stop();

		// Game-specific
		virtual void onInit() = 0;
		virtual void onUpdate(float delta_time) = 0;
		virtual void onDestroy() = 0;
	};

} }