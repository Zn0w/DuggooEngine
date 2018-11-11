#define _CRT_SECURE_NO_WARNINGS // To use strcat() from string.h with VS compiler

#include "log.h"

#include <iostream>
#include <string.h>

namespace Duggoo
{

	void log(LogLevel level, const char* message)
	{
		char lvl_str[220];

		switch (level)
		{
			case TRACE :
				strcpy((char*) lvl_str, "TRACE    ");
				break;

			case INFO :
				strcpy((char*)lvl_str, "INFO     ");
				break;

			case WARN :
				strcpy((char*)lvl_str, "WARN     ");
				break;

			case ERROR :
				strcpy((char*)lvl_str, "ERROR    ");
				break;

			case FATAL :
				strcpy((char*)lvl_str, "FATAL    ");
				break;
		}

		std::cout << strcat((char*) lvl_str, (char*) message) << std::endl;
	}

}