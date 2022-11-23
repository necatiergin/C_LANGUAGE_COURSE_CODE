int main(void)
{
	int x = 99;
	int* ptr = &x;

	*ptr++;
	*ptr++;  //ub
	//...
}
