#include <stdlib.h>

struct Matrix {
    size_t rows;
    size_t cols;
    double data[];
};

int main(void)
{
    size_t rows = 10;
    size_t cols = 20;

    struct Matrix* m =
        malloc(sizeof(*m) + rows * cols * sizeof(double));
    //...
}
