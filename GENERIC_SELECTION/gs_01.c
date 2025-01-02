#include <stdio.h>

#define get_min(x, y) _Generic((x), \
    int: min_int, \
    float: min_float, \
    long: min_long, \
    double: min_double \
)(x, y)

static inline int min_int(int x, int y) 
{
    return x < y ? x : y;
}

static inline long min_long(long x, long y) 
{
    return x < y ? x : y;
}

static inline double min_float(float x, float y)
{
    return x < y ? x : y;
}

static inline double min_double(double x, double y) 
{
    return x < y ? x : y;
}

int main() 
{
    printf("Min (int): %d\n", get_min(5, 9));
    printf("Min (long): %ld\n", get_min(32L, 21L));
    printf("Min (float): %f\n", get_min(3.4f, 2.6f));
    printf("Min (double): %f\n", get_min(4.56, 5.98));
    //printf("Min (long double): %f\n", get_min(4.56L, 5.98L)); //error
}
