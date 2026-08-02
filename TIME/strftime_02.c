#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
    struct tm* ptm = localtime(&t);

    char str[100];

    strftime(str, sizeof str, "%d/%m/%Y %H:%M:%S", ptm);

    printf("%s\n", str);
}
