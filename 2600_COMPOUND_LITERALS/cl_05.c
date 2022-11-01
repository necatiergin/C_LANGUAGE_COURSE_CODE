int bar(void);

void foo(void)
{
    int* p;
    {
        p = &(int) { bar };
        *p = 1;   //no problem
    }
    // p is a dangling pointer here

    *p = 2;   //undefined behavior
}
