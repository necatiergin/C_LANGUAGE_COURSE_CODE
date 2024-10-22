#include <stdio.h>

int main(void)
{
	char str[100] = "sevcan";

	strcpy(str + 3, str); //ub
}
