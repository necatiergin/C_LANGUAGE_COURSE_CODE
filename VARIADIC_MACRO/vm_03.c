#include <stdio.h>

#define showlist(...) puts(#__VA_ARGS__)

int main(void)
{
	showlist();            
	showlist(1, "x", int); 
	showlist(ali, veli, naz); 
	showlist("ali", "veli", "naz");
}
