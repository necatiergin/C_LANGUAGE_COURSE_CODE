#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm t = { 0 };

    t.tm_year = 2025 - 1900;
    t.tm_mon = 2;        // March
    t.tm_mday = 30;
    t.tm_hour = 2;
    t.tm_min = 30;
    t.tm_sec = 0;

    t.tm_isdst = -1;      

    time_t ts = mktime(&t);

    printf("timestamp = %lld\n", (long long)ts);
    printf("tm_isdst after mktime = %d\n", t.tm_isdst);
}
