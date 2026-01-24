#include <stdio.h>

int main()
{
    // Convert to lowercase
    printf("'k' => '%c'\n", ('k' | ' '));
    printf("'K' => '%c'\n", ('K' | ' '));

    // Convert to uppercase
    printf("'k' => '%c'\n", ('k' & '_'));
    printf("'K' => '%c'\n", ('k' & '_'));
}
