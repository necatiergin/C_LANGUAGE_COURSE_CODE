#include <stddef.h>

char* strstr(const char* haystack, const char* needle)
{
    if (!*needle)  
        return (char*)haystack;

    for (; *haystack; ++haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*h && *n && (*h == *n)) {
            ++h;
            ++n;
        }

        if (!*n)  
            return (char*)haystack;
    }

    return NULL;
}
