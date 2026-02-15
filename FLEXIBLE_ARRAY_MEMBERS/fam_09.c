// deep copy

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Packet {
    uint32_t type;
    size_t   len;     // payload byte sayısı
    unsigned char data[];
};

static size_t packet_bytes(const struct Packet* p)
{
    // header + payload
    return sizeof(*p) + p->len;
}

struct Packet* packet_clone(const struct Packet* src)
{
    if (!src) 
        return NULL;

    size_t total = packet_bytes(src);

    struct Packet* dst = (struct Packet*)malloc(total);
    if (!dst) 
        return NULL;

    return memcpy(dst, src, total);
 }
