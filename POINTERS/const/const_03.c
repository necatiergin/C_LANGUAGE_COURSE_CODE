#include <stdio.h>

int main(void)
{
	int x = 10;
	int y = 20;

	int* const p = &x;
	*p = 33; //valid
	p = &y; //invalid
}
