#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm tm = {
		.tm_year	= 1999 - 1900,
		.tm_mon		= 7,
		.tm_mday	= 17,
		.tm_hour	= 3,
		.tm_min		= 2,
		.tm_sec		= 0,
		.tm_isdst	= -1
	};

	time_t now = time(NULL);
	time_t earthquake = mktime(&tm);
	time_t result = now - earthquake;

	struct tm* ptm = localtime(&result);

	printf("duration since the earthquake : "
	"%d years, %d months, %d days, %d hours, %d minutes, %d seconds\n", 
	ptm->tm_year - 70, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}
