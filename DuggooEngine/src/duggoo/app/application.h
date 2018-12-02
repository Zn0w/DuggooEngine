#pragma once

#include "string.h"

#include "../log/log.h"

namespace Duggoo { namespace app {

	class Application
	{

	private:
		const char* title;
		bool running;

	public:
		Application(const char*);
		~Application();

	};

} }