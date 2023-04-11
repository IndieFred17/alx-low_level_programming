#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a pointer to a string containing the binary number
 *
 * Return: the converted number, or 0 if an error occurs
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	const char *ptr = b;

	if (b == NULL)
		return (0);

	while (*ptr != '\0')
	{
		if (*ptr != '0' && *ptr != '1')
			return (0);
		result = (result << 1) + (*ptr - '0');
		ptr++;
	}

	return (result);
}
