#include <stdlib.h>
#include <stdint.h>

struct Message {
    uint32_t type;
    uint32_t length;
    unsigned char payload[];
};

int main(void)
{
    size_t n = 100;
    struct Message* pm = malloc(sizeof(struct Message) + n);
    //...
    pm->length = n;
}
