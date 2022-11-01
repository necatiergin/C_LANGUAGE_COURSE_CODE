#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double stddev(int argc_cnt, ...)
{
    double sum = 0.;
    va_list  args1;
    va_start(args1, argc_cnt);
    va_list args2;
    va_copy(args2, args1); 

    for (int i = 0; i < argc_cnt; ++i) {
        sum += va_arg(args1, double);
    }
    va_end(args1);
    
    const double mean = sum / argc_cnt;

    double sum_diff_sq = 0.;
    for (int i = 0; i < argc_cnt; ++i) {
        const double num = va_arg(args2, double);
        sum_diff_sq += (num - mean) * (num - mean);
    }
    va_end(args2);
    return sqrt(sum_diff_sq / argc_cnt);
}

int main(void)
{
    printf("%f\n", stddev(7, 1.93, 2.87, 16.3, 37.45, 5.6, 81.2, .99));
}
