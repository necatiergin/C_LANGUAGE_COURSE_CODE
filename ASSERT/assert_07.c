#include <assert.h>
#include <stddef.h>

int get_element(const int* a, size_t size, size_t index)
{
    assert(a != NULL);
    assert(index < size);

    return a[index];
}
