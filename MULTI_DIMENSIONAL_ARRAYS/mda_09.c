int main(void)
{
	int a[5][10];

	int* p1 = a; //wrong - implicit conversion
	int(*p2)[10] = a; //correct
	int* p3 = a[0]; //correct - array to pointer conversion
	int* p4 = &a[0][0]; //correct 
}
