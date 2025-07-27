#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(void) 
{
    const char* str = "a99999999999999999999999";
    char* endptr;

    //
    errno = 0;  
    long val = strtol(str, &endptr, 10);

    if (errno == ERANGE) {
        printf("out of range: ERANGE\n");
    }
    else if (errno != 0) {
        perror("strtol");
    }
    else if (endptr == str) {
        printf("no value\n");
    }
    else {
        printf("the input is: %ld\n", val);
    }
}
