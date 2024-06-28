#include <stdio.h>

int main(void)
{
    char* p = (char[]){ "Beyhan" };
    puts(p);
    //...
    *p = 'S'; //no problem
    puts(p);
}
