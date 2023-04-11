/**
 * get_bit - returns the value of a bit at a given index in a number
 * @n: the number to search
 * @index: the index of the bit to retrieve (starting from 0)
 *
 * Return: value of the bit at index, or -1 if the index is out of range
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	return ((n >> index) & (1));
}

