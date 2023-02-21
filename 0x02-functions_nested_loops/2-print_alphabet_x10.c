#include "main.h"

/**
 * print_alphabet_x10 - print 10 times the alphabet, in lowercase
 */

void print_alphabet_x10(void)
{
	char letter;
	int n;

	for (n = 0; n <= 9; n++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
