#include <stddef.h>

void* memmove(void* vpdest, const void* vpsource, size_t n)
{
    unsigned char* pd = vpdest;
    const unsigned char* ps = vpsource;

    if (pd == ps || n == 0)
        return vpdest;

    if (pd < ps) {
        while (n--) {
            *pd++ = *ps++;
        }
    }
    else {
        pd += n;
        ps += n;

        while (n--) {
            *--pd = *--ps;
        }
    }

    return vpdest;
}
