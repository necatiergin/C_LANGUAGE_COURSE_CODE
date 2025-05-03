#include<stddef.h>

int* search1(const int* pa, int size, int key)
{
    for (int i = 0; i < size; ++i) {
        if (pa[i] == key)
            return (int*)(pa + i);
    }
    return NULL;
}

int* search2(const int* pa, int size, int key)
{
    while (size--) {
        if (*pa == key) {
            return (int*)pa;
        }
        ++pa;
    }
    return NULL;
}
