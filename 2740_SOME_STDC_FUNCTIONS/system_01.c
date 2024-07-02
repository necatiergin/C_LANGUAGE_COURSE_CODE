#include <stdio.h>
#include <string.h>

#define  MAX_COMMAND_LENGTH		80

void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		; //null statement
}

int main(void)
{
	char command_entry[MAX_COMMAND_LENGTH + 1];

	for (;;) {
		printf("enter your command > ");
		(void)scanf("%[^\n]s", command_entry);
		if (!strcmp(command_entry, "terminate"))
			break;
		
		system(command_entry);
		clear_input_buffer();
	}
}
