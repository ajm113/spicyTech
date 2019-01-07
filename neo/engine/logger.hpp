#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdio.h>
#include <stdarg.h>

#define MAX_PRINT_MSG 4096

class spiceLogger {
	public:
	void Printf(const char *fmt, ... );
	protected:
	static int vsnPrintf(char *dest, int size, const char *fmt, va_list argptr );
};

#endif
