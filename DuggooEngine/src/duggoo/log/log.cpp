#define _CRT_SECURE_NO_WARNINGS // To use strcat() from string.h with VS compiler

#include "log.h"

#include <iostream>
#include <string.h>

namespace Duggoo
{

	void log(LogLevel level, const char* message)
	{
		const char* lvl_str = "";

		switch (level)
		{
			case TRACE :
				lvl_str = "TRACE	";
				break;

			case INFO :
				lvl_str = "INFO		";
				break;

			case WARN :
				lvl_str = "WARN		";
				break;

			case ERROR :
				lvl_str = "ERROR	";
				break;

			case FATAL :
				lvl_str = "FATAL	";
				break;
		}

		std::cout << strcat((char*) lvl_str, (char*) message) << std::endl;
	}

}