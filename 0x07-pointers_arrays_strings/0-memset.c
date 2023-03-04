#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: first address
 * @b: value to be used
 * @n: required changes
 * Return: changed array with new value for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
