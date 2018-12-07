#pragma once

#include "string.h"

#include "../log/log.h"

#include "../graphics/window.h"

namespace Duggoo { namespace app {

	class Application
	{

	private:
		const char* title;
		graphics::Window window;

	protected:
		bool running;

	public:
		Application(const char*);
		~Application();

		virtual void update() = 0;

		bool isRunning();

	};

} }