int main(void)
{
	int x;
	int* ptr = &x;
	int x = *ptr; //ub

	//...
}
