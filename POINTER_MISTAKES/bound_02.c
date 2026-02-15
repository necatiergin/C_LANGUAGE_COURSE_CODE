int main(void)
{
	int ar[5] = { 0 };
	int* ptr = ar + 4;

	int x = *ptr++;
	int y = *ptr++;  //ub
	//...
}
