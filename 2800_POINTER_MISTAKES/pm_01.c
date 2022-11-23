int main()
{
	int* ptr; //uninitialized pointer - wild pointer

	*ptr = 190; //ub
	//...
}
