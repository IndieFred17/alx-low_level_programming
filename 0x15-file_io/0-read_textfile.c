#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

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

	char *buffer = malloc(letters + 1);

	if (buffer == NULL)
		return (0);

	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		free(buffer);
		return (0);
	}

	ssize_t num_read = fread(buffer, sizeof(char), letters, fp);

	if (num_read < 0)
	{
		free(buffer);
		fclose(fp);
		return (0);
	}

	ssize_t num_written = write(STDOUT_FILENO, buffer, num_read);

	if (num_written < 0 || num_written != num_read)
	{
		free(buffer);
		fclose(fp);
		return (0);
	}

	free(buffer);
	fclose(fp);
	return (num_read);
}
