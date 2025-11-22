#include <stddef.h>

int strncmp(const char* s1, const char* s2, size_t n)
{
    if (n == 0)
        return 0;

    while (n--) {
        unsigned char c1 = (unsigned char)*s1++;
        unsigned char c2 = (unsigned char)*s2++;

        if (c1 != c2)
            return c1 - c2;

        if (c1 == '\0')   
            return 0;
    }

    return 0;
}
