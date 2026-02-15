#include <stdio.h>

struct Student {
	int no;
	int grades[];
};

int main()
{
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(struct Student) = %zu\n", sizeof(struct Student));
}
