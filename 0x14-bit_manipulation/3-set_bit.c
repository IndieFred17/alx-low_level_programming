#include "main.h"

/**
 * set_bit - sets the bit at a given index in a number to 1
 * @n: a pointer to the number to modify
 * @index: the index of the bit to set (starting from 0)
 *
 * Return: 1 for success, or -1 if the index is out of range
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n |= (1UL << index);
	return (1);
}
