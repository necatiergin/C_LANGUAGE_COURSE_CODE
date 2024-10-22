#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void log_vals(const char* fmt, ...)
{
    char msg[50];
    time_t cln_tm;
    time(&cln_tm);
    strftime(msg, sizeof msg, "%F %T", localtime(&cln_tm));
    printf("[%s] ", msg);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

int main(void)
{
    int ival = 34;
    double dval = 5.6;
    char str[] = "necati ergin";

    log_vals("log %d %f %s...\n", ival, dval, str);
}
