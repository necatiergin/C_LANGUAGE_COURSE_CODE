#include <stdio.h>

int main()
{
	int x;

	printf("your entry please: ");
	int retval = scanf("%*s%d", &x);  //necati 234 enter

	printf("retval = %d\n", retval); //retval = 1
	printf("x = %d\n", x); //x 0 234

}
