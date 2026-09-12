#include <stdint.h>

struct Header {
    uint16_t type;
    uint16_t length;
    uint32_t sequence;
};

static_assert(sizeof(struct Header) == 8,
              "Header beklenen binary formata uymuyor");
