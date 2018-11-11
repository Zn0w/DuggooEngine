#pragma once

namespace Duggoo
{

	enum LogLevel
	{
		TRACE,
		INFO,
		WARN,
		ERROR,
		FATAL
	};
	
	void log(LogLevel level, const char* message);

}