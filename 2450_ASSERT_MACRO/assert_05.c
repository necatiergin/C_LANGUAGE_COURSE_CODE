#include <stdio.h>
#include <assert.h>

int main(void)
{
    int cnt = 5;
    //
    assert(--cnt > 0); //side effect

    printf("cnt = %d\n", cnt);
}
