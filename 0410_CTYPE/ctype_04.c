#include <stdio.h>
#include <ctype.h>
#include <Windows.h>  //not standard
#include <stdlib.h>

int get_random_char(void)
{
	int c;

	while (!isprint(c = rand() % 128))
		;

	return c;
}


int main(void)
{
	for (;;) {
		putchar(get_random_char());
		putchar(' ');
		Sleep(50);  //not standard
	}
}
