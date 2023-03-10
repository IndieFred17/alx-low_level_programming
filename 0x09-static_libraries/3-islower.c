#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: the character
 * Return: 1 for lowercase character, 0 for otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
