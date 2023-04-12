#define   asize(x)    (sizeof(x) / sizeof(x[0]))

int main(void)
{
	int a[] = { 2, 5, 7, 8, 2, 1, 9, 5, 76, 10, 20, 30, 40, 2, 4, 3 };
	double da[2 * asize(a)];
  //...
}
