struct Student {
	int no;
	int grades[];
};

int main()
{
	struct Student s = { 12, {1, 5, 6, 7} }; //invalid
}
