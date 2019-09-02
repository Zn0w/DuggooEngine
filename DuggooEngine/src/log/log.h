#pragma once

namespace dg {

	enum LogLevel
	{
		TRACE,
		INFO,
		WARN,
		ERR,
		FATAL
	};
	
	void log(LogLevel level, const char* message);

}

#ifdef DG_DEBUG
	#define LOG_TRACE(x) dg::log(dg::TRACE, x)
	#define LOG_INFO(x) dg::log(dg::INFO, x)
	#define LOG_WARN(x) dg::log(dg::WARN, x)
	#define LOG_ERROR(x) dg::log(dg::ERR, x)
	#define LOG_FATAL(x) dg::log(dg::FATAL, x)
#else
	#define LOG_TRACE(x)
	#define LOG_INFO(x)
	#define LOG_WARN(x)
	#define LOG_ERROR(x)
	#define LOG_FATAL(x)
#endif