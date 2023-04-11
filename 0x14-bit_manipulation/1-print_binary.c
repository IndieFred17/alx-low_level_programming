#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: the number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int printed = 0;

	while (mask != 0)
	{
		if (n & mask)
		{
			putchar('1');
			printed = 1;
		}
		else if (printed)
		{
			putchar('0');
		}
		mask >>= 1;
	}

	if (!printed)
	{
		putchar('0');
	}
}
