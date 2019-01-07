#include "logger.hpp"

void spiceLogger::Printf(const char *fmt, ... ) {
	char msg[MAX_PRINT_MSG];
	va_list argptr;

	va_start(argptr, fmt);
	vsprintf (msg, fmt, argptr);
	fprintf(stdout, "%s\n", msg);
	va_end(argptr);
	fflush( stdout );
}

