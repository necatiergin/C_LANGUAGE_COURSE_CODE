#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[] = "9871michael";

	printf("%zu\n", strspn(str, "0123456789"));
}
