#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t1 = time(NULL);

    // simulate delay
    for (volatile int i = 0; i < 100000000; ++i)
        for (volatile int k = 0; k < 100; ++k)
            ; // null statement

    time_t t2 = time(NULL);

    double elapsed = difftime(t2, t1);

    printf("Elapsed time: %f seconds\n", elapsed);
}
