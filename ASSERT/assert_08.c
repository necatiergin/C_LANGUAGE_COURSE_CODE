#include <assert.h>
#include <stddef.h>

#define CAPACITY    100

struct Stack {
    int data[CAPACITY];
    size_t size;
};

void stack_push(struct Stack* sp, int value)
{
    assert(sp != NULL);
    assert(sp->size < CAPACITY);

    sp->data[sp->size++] = value;
}
