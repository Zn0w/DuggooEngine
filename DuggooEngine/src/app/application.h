#pragma once

#include <stdio.h>

#include "../graphics/window/window.h"
#include "../graphics/render/renderer.h"
#include "../utils/clock.h"
#include "../input/input.h"


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
		graphics::Renderer renderer;
		clock::Clock clock;
		graphics::Window window;
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