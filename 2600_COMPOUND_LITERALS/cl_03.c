#include <stdio.h>

typedef struct {
    char name[40];
    int id;
    double wage;
}Employee;

void print_employee(const Employee* p)
{
    printf("%d %s %.2f\n", p->id, p->name, p->wage);
}

int main(void)
{
    print_employee(&(Employee) { "Burhan Koc", 1345, 45.60 });
    print_employee(&(Employee) { .id = 7651, .name = "Can Demirci" });
}
