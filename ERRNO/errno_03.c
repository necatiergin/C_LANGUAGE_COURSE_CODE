// from cppreference.com

#include <stdio.h>

int main(void)
{
    FILE* f = fopen("non_existent", "r");
    if (f == NULL) {
        perror("fopen() failed");
    }
    else {
        fclose(f);
    }
}
