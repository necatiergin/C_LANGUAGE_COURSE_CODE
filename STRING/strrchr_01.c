#include <stddef.h>


char* strrchr(const char* s, int c)
{
    unsigned char ch = (unsigned char)c;
    const char* last = NULL;

    while (*s) {
        if ((unsigned char)*s == ch)
            last = s;            
        ++s;
    }
    
    if (ch == '\0')
        return (char*)s;

    return (char*)last;
}

