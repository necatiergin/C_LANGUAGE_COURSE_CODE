#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	//...
	size_t n = (rand() % 100 + 5) * 16;
	int* p = (int*)malloc(sizeof(int)); 
	//...
	if (!p) {
		printf("cannot allocate memory!");
		return 1;
	}
	//...
	int x = 20;
	p = &x; //memory leak
	//...
}
