#include <stddef.h>

int mymemcmp(const void* vp1, const void* vp2, size_t n)
{
    const unsigned char* p1 = vp1;
    const unsigned char* p2 = vp2;

    while (n--) {
        if (*p1 != *p2)
            return (int)*p1 - (int)*p2;  

        p1++;
        p2++;
    }

    return 0; 
}
