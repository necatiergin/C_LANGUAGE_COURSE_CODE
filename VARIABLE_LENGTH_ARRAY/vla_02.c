#include <stddef.h>

void func(size_t size)
{
    int a[size] = {1, 5, 7, 9}; //error: variable-sized object may not be initialized
    //...
}
