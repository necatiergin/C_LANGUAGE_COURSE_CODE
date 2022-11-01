#include <stdio.h>
#include <stdarg.h>

#define			BUFFER_SIZE		    512

void print_error(const char* fmt, ...)
{
    char buffer[BUFFER_SIZE];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    perror(buffer);
    va_end(args);
}

int main(void)
{
    FILE* pf;
    char file_name[] = "necati.txt";

    pf = fopen(file_name, "r");
    if (!pf) {
        print_error("Error opening the file '%s'", file_name);
        return 1;
    }
    
    //code

    fclose(pf);
}
