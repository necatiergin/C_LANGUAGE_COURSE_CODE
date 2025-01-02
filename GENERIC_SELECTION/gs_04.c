#include <stdio.h>

#define printf_dec_format(x)    _Generic((x), \
    char                        : "%c", \
    signed char                 : "%hhd", \
    unsigned char               : "%hhu", \
    signed short                : "%hd", \
    unsigned short              : "%hu", \
    signed int                  : "%d", \
    unsigned int                : "%u", \
    long int                    : "%ld", \
    unsigned long int           : "%lu", \
    long long int               : "%lld", \
    unsigned long long int      : "%llu", \
    float                       : "%f", \
    double                      : "%f", \
    long double                 : "%Lf", \
    char *                      : "%s", \
    void *                      : "%p")

#define print(x) printf(printf_dec_format(x), x)
#define println(x) printf(printf_dec_format(x), x), printf("\n");

int main()
{
    println('b');    
    println((char)'B');  
    println(987);    
    println(34.87);  
}
