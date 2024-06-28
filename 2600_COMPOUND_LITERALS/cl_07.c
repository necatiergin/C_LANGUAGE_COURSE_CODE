void f(void)
{
    int *p;
    extern int func(void);
    {
 	p = &(int) { func() };
	*p = 1;   //sorun yok
    }
    // p pointer değişkeni dangling durumda.
	
    *p = 2;   //tanımsız davranış
}
