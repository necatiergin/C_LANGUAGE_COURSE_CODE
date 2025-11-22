int strcmp(const char* s1, const char* s2)
{
    const unsigned char* p1 = (const unsigned char*)s1;
    const unsigned char* p2 = (const unsigned char*)s2;

    while (*p1 == *p2) {
        if (*p1 == '\0')   // ya da *p2 == '\0'
            return 0;
        ++p1;
        ++p2;
    }

    return (int)(*p1) - (int)(*p2);
}
