#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char* const name = "PATH";
    const char* const env_path = getenv(name);
    
    if (env_path != NULL)
        printf("%s = %s\n", name, env_path);
}
