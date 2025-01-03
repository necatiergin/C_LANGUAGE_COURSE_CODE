#include <stdio.h>

int main(void)
{
	int n = 12;

	const char* mystr = "This string is definitely longer than what we want to print.";
	printf("Here are first %d chars only: [%.*s]\n", n, n, mystr);
}
