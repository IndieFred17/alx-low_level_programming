#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	char *buf = calloc(letters + 1, sizeof(char));

	if (buf == NULL)
		return (0);

	ssize_t t = read(fd, buf, letters);

	if (t == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	ssize_t w = write(STDOUT_FILENO, buf, t);

	if (w == -1 || w != t)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (w);
}
