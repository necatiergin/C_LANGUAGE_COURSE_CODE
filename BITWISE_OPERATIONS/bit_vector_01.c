#include <stdio.h>
#include <stdint.h>

#define FEATURE_A   (1 << 0)
#define FEATURE_B   (1 << 1)
#define FEATURE_C   (1 << 2)
#define FEATURE_D   (1 << 3)

void print_flags(uint8_t flags) 
{
    printf("A:%d B:%d C:%d D:%d\n",
        !!(flags & FEATURE_A),
        !!(flags & FEATURE_B),
        !!(flags & FEATURE_C),
        !!(flags & FEATURE_D)
    );
}

int main() 
{
    uint8_t flags = 0;

    // A ve C özelliklerini aktif et
    flags |= FEATURE_A | FEATURE_C;

    print_flags(flags);  // A:1 B:0 C:1 D:0

    // B özelligini aktif et
    flags |= FEATURE_B;
    print_flags(flags);  // A:1 B:1 C:1 D:0

    // C özelligini kapat
    flags &= ~FEATURE_C;
    print_flags(flags);  // A:1 B:1 C:0 D:0

    // D'yi toggle et (0 → 1)
    flags ^= FEATURE_D;
    print_flags(flags);  // A:1 B:1 C:0 D:1
}
