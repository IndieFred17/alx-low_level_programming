#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 * followed by a new line
 * Return: 0-14 ten times
 */

void more_numbers(void)
{
	int i, k;

	for (i = 1; i < 10; i++)
	{
		for (k = 0; k < 15; k++)
		{
			if (k >= 10)
				_putchar(k / 10 + '0');
				_putchar(k % 10 + '0');
		}
				_putchar('\n');
	}
}
