
//C99

// more efficient compiler optimization
// better documentation
// not NULL expected
// compiler may issue diagnostic (warning)

void func(int p[static 10])
{
	//...
}

int main()
{
	int ar1[7] = { 0 };
	int ar2[20] = { 0 };

	func(ar1);
	func(ar2);
}
