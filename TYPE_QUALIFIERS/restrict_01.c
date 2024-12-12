int main()
{
	int y = 10;
	//restrict int x = 10;		//invalid, x is not a pointer
	//restrict int* py = &y;	// invalid - only top level restrict
	int* restrict ptr = &y;	    // valid
	//...
}
