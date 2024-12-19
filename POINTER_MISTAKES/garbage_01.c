int main(void)
{
	int x;
	int* ptr = &x;
	int y = *ptr; //ub

	//...
}
