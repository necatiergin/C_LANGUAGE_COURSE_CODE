
int main()
{
	volatile int x = 42; 
	int* ptr = (int*)&x;
	int ival = *ptr; // undefined behavior
	//...
}
