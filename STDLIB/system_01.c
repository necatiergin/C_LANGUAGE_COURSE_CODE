#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	if (system(NULL)) {
		printf("komut yorumcu mevcut\n");
	}
	else {
		printf("komut yorumcu mevcut degil\n");
	}
}
