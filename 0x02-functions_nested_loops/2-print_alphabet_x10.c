#include "main.h"

/**
 * print_alphabet_x10 - print 10 times the alphabet, in lowercase
 * Return: void
 */

void print_alphabet_x10(void)
{
	char letter;
	int n = 0;

	while (n <= 9)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		_putchar('\n');
		n++;
	}
}
