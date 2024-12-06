//from cppreference.com

#include <stdio.h>
#include <setjmp.h>

jmp_buf my_jump_buffer;

void foo(int status)
{
    printf("foo(%d) called\n", status);
    longjmp(my_jump_buffer, status + 1); // will return status+1 out of setjmp
}

int main(void)
{
    volatile int count = 0; // modified local vars in setjmp scope must be volatile
    if (setjmp(my_jump_buffer) != 5) // compare against constant in an if
        foo(++count);
}
