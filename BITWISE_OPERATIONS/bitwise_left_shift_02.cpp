//left shifting of negative signed integers is undefined behavior

int main(void)
{
	int x = -1;

	x <<= 3; //ub
}
