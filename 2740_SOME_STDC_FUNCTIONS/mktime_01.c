#include <stdio.h>
#include <time.h>

int main(void)
{
	int n;

	printf("How many days before today?: ");
	(void)scanf("%d", &n);

	struct tm tm = *localtime(&(time_t) {time(NULL) });

	printf("today is %s", asctime(&tm));
	tm.tm_mday -= n;
	mktime(&tm);
	printf("%d days ago was %s", n, asctime(&tm));
}
