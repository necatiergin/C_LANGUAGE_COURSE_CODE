#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("Bir tam sayi girin: ");

    int c = getchar();

    if (isdigit(c)) {
        ungetc(c, stdin);   
        int x;
        scanf("%d", &x);    
        printf("Okunan sayi: %d\n", x);
    }
    else {
        ungetc(c, stdin);   
        char buf[100];
        scanf("%s", buf);
        printf("'%s' Sayi degil\n", buf);
    }
}
