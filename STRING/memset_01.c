#include <stddef.h>

void* memset(void* pdest, int ch, size_t count)
{
    unsigned char* p = pdest;
    unsigned char value = (unsigned char)ch;

    while (count--) {
        *p++ = value;
    }

    return pdest;
}
