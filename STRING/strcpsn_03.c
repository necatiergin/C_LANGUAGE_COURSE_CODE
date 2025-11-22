#include <stddef.h>

size_t my_strcspn(const char* s, const char* reject)
{
    const char* p = s;

    for (; *p != '\0'; ++p) {
        const char* r = reject;

        while (*r != '\0') {
            if (*p == *r)
                return (size_t)(p - s);
            ++r;
        }
    }
    return (size_t)(p - s); 
}
