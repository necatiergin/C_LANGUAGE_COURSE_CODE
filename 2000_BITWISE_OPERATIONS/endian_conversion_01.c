#define encon32(x)	(((x) << 24) | ((x) >> 24) | ((x) >> 8 & 0x0000FF00) | ((x) << 8 & 0x00FF0000))

int main(void)
{
	unsigned int uval = 0xAB12CFD8;

	printf("%X  %X\n", uval, encon32(uval));
}
