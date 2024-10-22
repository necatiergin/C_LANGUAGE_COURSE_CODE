#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char* mp_address;
	int m_id;
}Person;

int main()
{
	const char* pa1 = "Degirmen sok. No 17 Besiktas - Istanbul";
	//const char* pa2 = "sadegul sok. No 25 Kavaklidere - Ankara";
	Person per1;

	per1.mp_address = (char*)malloc(strlen(pa1) + 1);
	strcpy(per1.mp_address, pa1);
	per1.m_id = 43254;

	Person per2 = per1;
	free(per1.mp_address);

	puts(per2.mp_address); //ub
	free(per2.mp_address); //ub
}
