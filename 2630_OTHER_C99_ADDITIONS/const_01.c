//void func(const int *p)
void func(const int p[])
{
	++p;  //legal
	*p = 20; //error
}

//C99
void func(int p[const])
{
	++p;  //error
	*p = 20; //legal
}
