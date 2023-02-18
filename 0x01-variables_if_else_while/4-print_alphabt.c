#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, except for q and e
 *
 * Return: always 0
 */

int main(void)
{
	char l;

	for (l = 'a'; l <= 'z'; l++)
		if (l != 'q' && l != 'e')
			putchar(l);
	putchar('\n');

	return (0);
}
