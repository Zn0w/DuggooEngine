#pragma once

#include "string.h"

#include "../log/log.h"

#include "../graphics/window.h"

namespace Duggoo { namespace app {

	class Application
	{

	private:
		const char* title;
		
	public:
		graphics::Window window;

	protected:
		bool running;

	public:
		Application(const char*);
		~Application();

		virtual void update() = 0;

		bool isRunning();

		void setWindow(int x_pos, int y_pos, int w, int h, const char* t);
		graphics::Window getWindow() { return window; }

	};

} }