#include <stdio.h>

int main(void)
{
	char s1[] = "deniz";
	char s2[] = "deniz";

	if (s1 == s2)	// always false
		printf("equal\n");
	else
		printf("not equal\n");
}
