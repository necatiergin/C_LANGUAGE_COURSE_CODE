#include <stdio.h>
#include <time.h>

#define BUFFER_SIZE		256

int main(void)
{
	char str[BUFFER_SIZE];

	struct tm* p = localtime(&(time_t) { time(NULL) });

	strftime(str, BUFFER_SIZE, "%a %b %d %H:%M:%S %Y", p);
	printf("%s\n", str);
	printf("%s", asctime(p));
}
