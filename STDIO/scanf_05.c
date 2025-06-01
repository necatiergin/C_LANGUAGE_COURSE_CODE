int main(void) 
{
    const char* input = "isim: mustafa, yas: 30";
    char name[50];
    int age;

    sscanf(input, "isim: %[^,], yas: %d", name, &age);
    printf("isim: %s, yas: %d\n", name, age);
}
