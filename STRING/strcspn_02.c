#include <stdio.h>
#include <string.h>

#define    SIZE    100

int main(void)
{
	char str[SIZE];

	printf("enter a string: ");
	scanf("%s", str);

	size_t n = strcspn(str, "0123456789");

	printf("index = %zu (%s)\n", n, str + n);
}
