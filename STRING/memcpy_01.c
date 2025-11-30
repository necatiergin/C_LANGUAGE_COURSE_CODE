#include <stddef.h>

void* mymemcpy(void* vpdest, const void* vpsource, size_t n)
{
    unsigned char* dest = vpdest;
    const unsigned char* source = vpsource;

    while (n--) {
        *dest++ = *source++;
    }

    return vpdest;
}
