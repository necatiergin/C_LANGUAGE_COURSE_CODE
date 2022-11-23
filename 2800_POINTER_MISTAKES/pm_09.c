#include <stdio.h>

#define  SIZE   100

int main(void)
{
	char s1[SIZE];
	char s2[SIZE];

	printf("enter 2 words : ");
	(void)scanf("%s%s", s1, s2);

	if (s1 == s2) {  //always true
		printf("same words\n");
	}
	else {
		printf("different words\n");
	}
}
