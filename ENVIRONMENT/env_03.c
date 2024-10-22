#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char* const p_env[] = {
    "PATH", "OS" "COMPUTErNAME", "USERNAME", "SYSTEMROOT", "HOMEDRIVE", "HOMEPATH",
    };

    const char* penv_str;

    for (size_t i = 0; i < sizeof(p_env) / sizeof(*p_env); ++i) {
        if ((penv_str = getenv(p_env[i])) != NULL)
            printf("%-16s = %s\n\n", p_env[i], getenv(p_env[i]));
    }
}
