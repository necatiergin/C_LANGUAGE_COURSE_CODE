#include <stdio.h>

void func(int n)
{
	int a[n];

	printf("size = %zu\n", sizeof(a) / sizeof(*a));
	//...
}

int main()
{
	for (int i = 5; i < 10; ++i) 
		func(i);
	
}
