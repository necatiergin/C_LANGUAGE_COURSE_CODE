#include <ctype.h>
#include <stdio.h>
#include "Windows.h"  //not standard
#include <stdlib.h>

int main(void)
{
	while (1) {
		int c = rand() % 128;
		if (isalnum(c)) {
			putchar(c);
			Sleep(50); //not standard
		}
	}
}
