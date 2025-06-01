#include <stdio.h>

int main(void) 
{
    const char* input = "123abc";
    int number, chars_read;

    sscanf(input, "%d%n", &number, &chars_read);
    printf("Number: %d\nCharacters consumed: %d\n", number, chars_read);
}
