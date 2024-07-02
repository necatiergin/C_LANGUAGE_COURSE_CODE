
#include <stdio.h>
#include <time.h>

int main(void)
{
	if (!freopen("nec.txt", "r", stdin)) {
		perror("freopen failed");
		return 1;
	}

	int x, y, z;

	scanf("%d%d%d", &x, &y, &z);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
}
