int n = 5;

struct Nec {
	int a[n]; //error - Vla cannot be a structure member
	int(*p)[n]; //error Vm type variables cannot be a structure member
};
