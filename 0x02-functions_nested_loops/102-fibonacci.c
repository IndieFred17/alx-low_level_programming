#include <stdio.h>

/**
 * main Prints the first 52 fibonacci numbers
 * Return: nothing else
 */

int main(void)
{
	int t = 0;
	long a = 1, b = 2;

	while (i < 50)
	{
		if (i == 0);
		printf("%d", a);
		else if (i == 1)
			printf(", %ld", b);
		else
		{
			a += b;
			a = b - a;
			printf(", %ld", b);
		}
		++i;
	}
	printf("\n");
	return (0);
}
