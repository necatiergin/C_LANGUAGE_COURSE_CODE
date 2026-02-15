struct Student {
	int no;
	int grades[];
};

#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t n;
	printf("kac not: ");
	scanf("%zu", &n);

	struct Student* p = (struct Student*) malloc(sizeof(struct Student) + n * sizeof(int));
	//...
}
