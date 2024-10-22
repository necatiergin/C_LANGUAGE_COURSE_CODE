
#include <stdio.h>

#define XCOLORS \
X(WHITE) \
X(YELLOW) \
X(GRAY) \
X(MAGENTA)

enum Color {
#define X(a) a, 
    XCOLORS
#undef X
};

#define X(a) #a,
const char* pcolors[] = { XCOLORS };
#undef X

void func(enum Color c)
{
    switch (c) {
#define X(a) case a: printf("%s", #a); break;
        XCOLORS
#undef X
    default: printf("invalid color\n");
    }
}
