#include <limits.h>
#include <string.h>
/*
    struct String {
        size_t len;
        char* data;
    };
*/

struct String {
    size_t len;
    char data[];
};

int main(void)
{
    char src[] = "necati ergin aslan";
    size_t len = strlen(src);
    struct String* s = malloc(sizeof(*s) + len + 1);
    //...
    s->len = len;
    memcpy(s->data, src, len + 1);
}
