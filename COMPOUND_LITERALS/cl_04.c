typedef struct
{
	const char* pname;
	int no;
} Student;

int main(void)
{
	Student a[] = {
	[0] .pname = "Metin",[0].no = 13,
	[5].pname = "Sade",[0].no = 21,
	[7].pname = "Kagan",[0].no = 34,
	[9].pname = "Aleyna",[0].no = 77,
	};
	//...
	a[1] = (Student){ "Seher", 45 };
	a[2] = (Student){ "Cihan", 98 };
	//...
}
