#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[] = "necati765413";

	printf("%zu\n", strcspn(str, "0123456789"));
}
