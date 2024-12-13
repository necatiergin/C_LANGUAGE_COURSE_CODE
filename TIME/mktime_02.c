#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
	
const char* const days[] = { "Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi" };

int main(void)
{
	struct tm tm = {
		.tm_year	= 2011 - 1900,
		.tm_mon		= 0,
		.tm_mday	= 1,
		.tm_isdst	= -1	
	};
	
	time_t sec = mktime(&tm);
	struct tm* ptm = localtime(&sec);
	
	printf("%02d-%02d-%04d %02d:%02d:%02d - %s\n", 
		ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, days[ptm->tm_wday]);
}
