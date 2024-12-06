#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE* f;
    f = fopen("unexist.xyz", "rb");
    if (!f)
        fprintf(stderr, "Error opening file unexist.ent: %s\n", strerror(errno));
    //...
}
