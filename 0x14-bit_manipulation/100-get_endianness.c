#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;

	if (*c)
		return (1); / Little endian /
	else
		return (0); / Big endian * /
}
