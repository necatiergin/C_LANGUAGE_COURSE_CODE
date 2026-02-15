#include <stddef.h>

void mat_add(size_t r, size_t c,
    double a[r][c], double b[r][c], double out[r][c])
{
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            out[i][j] = a[i][j] + b[i][j];
}

int main(void)
{
    int main()
    {
        size_t row = 3, ccol = 4;
        double a[row][col];
        double b[row][col];
        double c[row][col];
        //...
        mat_add(row, col, a, b, c);
    }
}
