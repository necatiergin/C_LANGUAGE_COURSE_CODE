#include <stddef.h>

size_t my_strcspn_fast(const char* s, const char* reject)
{
    unsigned char table[256] = { 0 };

    // reject karakterlerini işaretle
    for (const unsigned char* r = (const unsigned char*)reject; *r; ++r)
        table[*r] = 1;

    const char* p = s;
    while (*p) {
        if (table[(unsigned char)*p])
            break;
        ++p;
    }

    return (size_t)(p - s);
}
