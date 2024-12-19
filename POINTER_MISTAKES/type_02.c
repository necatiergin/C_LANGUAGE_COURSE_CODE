#define	IPTR		int*

int main(void)
{
	int x = 13;
	IPTR p1, p2;
	p1 = &x;
	p2 = p1; //!!!  p2 is int
	//...
}
