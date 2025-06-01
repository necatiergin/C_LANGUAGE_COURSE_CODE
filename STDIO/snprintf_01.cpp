#include <stdio.h>

int main(void) 
{
    char buffer[20];
    int x = 42;

    int n = snprintf(buffer, sizeof(buffer), "Value is: %d", x);

    printf("Output: %s\n", buffer);
    printf("Characters needed: %d\n", n); 
}
