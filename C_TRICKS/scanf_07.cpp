#include <stdio.h>

int main()
{
    char buf[64];

    printf("yaziyi girin: : ");
    scanf("%[$1234567890.,]", buf);
    printf("Input: [%s]\n", buf);
}
