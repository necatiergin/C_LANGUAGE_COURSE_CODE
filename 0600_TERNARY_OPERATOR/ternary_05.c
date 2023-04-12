int foo(int val)
{
	//
	return val == 10 ? 1 :
		val == 20 ? 3 :
		val == 40 ? 7 :
		0;
}


int bar(int val)
{
	//
	if (val == 10)
		return 1;

	if (val == 20)
		return 3;

	if (val == 40)
		return 7;

	return 0;
}
