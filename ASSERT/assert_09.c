#include <assert.h>

int gcd(int x, int y)
{
    assert(x > 0);
    assert(y > 0);

    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}
