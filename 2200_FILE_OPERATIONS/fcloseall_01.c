// fcloseall is not a std. C function

#include <stdio.h>

int main(void)
{
	FILE* f1 = fopen("necati1.txt", "w");
	FILE* f2 = fopen("necati2.txt", "w");
	FILE* f3 = fopen("necati3.txt", "w");
	FILE* f4 = fopen("necati4.txt", "w");

	//...

	int n = fcloseall();

	printf("%d file(s) closed\n", n);
}
