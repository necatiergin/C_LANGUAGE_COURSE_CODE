#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
    for (int i = 0; env[i] != NULL; ++i)
        printf("env[%d] = %s\n", i, env[i]);
}
