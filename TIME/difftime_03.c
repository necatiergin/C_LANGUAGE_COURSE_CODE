#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm date1 = { 0 };
    struct tm date2 = { 0 };

    date1.tm_year = 2025 - 1900;
    date1.tm_mon = 0;   // January
    date1.tm_mday = 1;

    date2.tm_year = 2026 - 1900;
    date2.tm_mon = 0;
    date2.tm_mday = 1;

    time_t t1 = mktime(&date1);
    time_t t2 = mktime(&date2);

    double days = difftime(t2, t1) / (60 * 60 * 24);

    printf("Days between dates: %.0f\n", days);
}
