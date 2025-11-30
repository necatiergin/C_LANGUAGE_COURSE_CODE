#include <stddef.h>

void *memchr(const void *ptr, int ch, size_t count)
{
    const unsigned char *p = ptr;
    unsigned char value = (unsigned char)ch;

    while (count--) {
        if (*p == value)
            return (void*)p;
        p++;
    }

    return NULL;
}
