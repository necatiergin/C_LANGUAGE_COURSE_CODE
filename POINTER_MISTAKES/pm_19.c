int main(void)
{
	char str[] = "man plans and God laughs";

	char* pd = (char*)malloc(strlen(str));
	//...
	strcpy(pd, str); //ub

	puts(pd);
	free(pd);
}
