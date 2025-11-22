char* strncpy(char* restrict dest, const char* restrict src, size_t n)
{
    char* ret = dest;

    while (n && (*dest = *src)) {
        dest++;
        src++;
        n--;
    }

    while (n) {
        *dest = '\0';
        dest++;
        n--;
    }

    return ret;
}
