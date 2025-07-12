#include <stdio.h>

#define OFFSETOF(type, member)  ((size_t)&(((type *)0)->member))

typedef struct {
    char    gender;
    int     age;
    double  weight;
}Person;

int main(void) 
{
    printf("gender offset: %zu\n", OFFSETOF(Person, gender));
    printf("age offset   : %zu\n", OFFSETOF(Person, age));
    printf("weight offset: %zu\n", OFFSETOF(Person, weight));
}
