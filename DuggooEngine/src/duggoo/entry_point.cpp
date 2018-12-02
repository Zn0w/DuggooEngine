#include "entry_point.h"

#include "../duggoo.h"

__declspec(dllexport) void start()
{
	Duggoo::log(Duggoo::INFO, "Hello World! :)");

	Duggoo::app::Application game("Sandbox");
}