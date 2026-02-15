#include <stdio.h>

#define LOG0(msg) \
    fprintf(stderr, "[%s:%d] %s", __FILE__, __LINE__, (msg))

#define LOGF(fmt, ...) \
    fprintf(stderr, "[%s:%d] " fmt, __FILE__, __LINE__, __VA_ARGS__)

int main(void)
{
    LOG0("hello\n");
    LOGF("x=%d\n", 42);
}
