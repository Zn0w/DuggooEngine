#pragma once

#include "string.h"

#include "../log/log.h"

namespace Duggoo { namespace app {

	class Application
	{

	private:
		const char* title;

	protected:
		bool running;

	public:
		Application(const char*);
		~Application();

		virtual void update() = 0;

		bool isRunning();

	};

} }