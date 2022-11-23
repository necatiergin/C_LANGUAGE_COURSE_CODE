#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char str[] = "necati ergin";
	char* p = str;
	//...
	puts(p);
	free(p);
}
