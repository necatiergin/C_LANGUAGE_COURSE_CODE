int main(void)
{
	int x = 99;
	int* ptr = &x;

	int a = *ptr++;
	int b = *ptr++;  //ub
	//...
}
