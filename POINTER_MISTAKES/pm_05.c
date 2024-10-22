int main(void)
{
	int ival = 654;
	int* ptr = ival; //!!
	//...
	int x = *ptr; //ub
}
