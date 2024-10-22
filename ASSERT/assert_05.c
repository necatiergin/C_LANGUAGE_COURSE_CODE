#include <assert.h>

void foo(int n)
{
	assert(n > 0 && n < 10); //no problem
}

void bar(const int* p, int size)
{
	assert(p != NULL && size > 2);  //not good
	//...
}
