void f(void)
{
    int *p;
    extern int func(void);
    {
 	p = &(int) { func() };
	*p = 1;   //sorun yok
    }
    // p is dangling
	
    *p = 2;   //u.b.
}
