#include <stddef.h>

char* strchr(const char* s, int c)
{
    unsigned char ch = (unsigned char)c;  

    while (*s) {
        if ((unsigned char)*s == ch)
            return (char*)s;             
        ++s;
    }

    if (ch == '\0')
        return (char*)s;

    return NULL;
}
