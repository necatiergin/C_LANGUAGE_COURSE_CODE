//quotation from Wikipedia

#include <stdio.h>

# define MYLOG(FormatLiteral, ...)  fprintf (stderr, "%s(%u): " FormatLiteral "\n", __FILE__, __LINE__, __VA_ARGS__)


int main(void)
{
	MYLOG("Too many balloons %u", 42);
	//fprintf(stderr, "%s(%u): " "Too many balloons %u" "\n", __FILE__, __LINE__, 42);
	//fprintf (stderr, "%s(%u): Too many balloons %u\n", __FILE__, __LINE__, 42);
	//MYLOG("Attention!");
	//fprintf (stderr, "%s(%u): " "Attention!" "\n", __FILE__, __LINE__, );
}
