#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	size_t row, col;

	srand((unsigned)time(NULL));

	printf("enter the row size and the column size: ");
	scanf("%zu%zu", &row, &col);
	int(*p)[row][col] = malloc(sizeof(*p));
	//int *pd = malloc(row * col * sizeof(int));
	if (!p) {
		fprintf(stderr, "bellek yetersiz\n");
		return 1;
	}

	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			//pd[i * col + k] = rand() % 10;
			(*p)[i][k] = rand() % 10;
		}
	}

	//...

	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", (*p)[i][k]);
		}
		printf("\n");
	}

	free(p);
}
