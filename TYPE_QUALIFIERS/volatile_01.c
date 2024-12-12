int x = 10;

int main()
{
	int* volatile p1 = &x; // volatile pointer to int
	volatile int* p2 = &x; // pointer to volatile int
	int volatile* p3 = &x; // pointer to volatile int
	volatile int* volatile p4 = &x; // volatile pointer to volatile int
}
