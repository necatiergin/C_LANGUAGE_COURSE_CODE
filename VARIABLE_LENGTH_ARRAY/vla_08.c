#include <stddef.h>

void mat_add(size_t r, size_t c,
    double a[r][c], double b[r][c], double out[r][c])
{
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            out[i][j] = a[i][j] + b[i][j];
}
