int x = 10;

int main()
{
	volatile int* pv = &x;
	//int* ptr = pv;	 // error
	int* ptr = (int *)pv;	 // valid

	int y = 10;
	ptr = &y;
	pv = ptr;	   //valid
}
