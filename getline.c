#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_getline - Read a line from a file or a stream.
 * @store: Double pointer to store the read line.
 * @input_len: Pointer to the length of the buffer.
 * @stream: Pointer to the input stream (e.g., file pointer).
 *
 * Return: Number of characters read, including the newline character,
 *         or -1 if an error occurs or the end of the file is reached.
 */
ssize_t my_getline(char **store, size_t *input_len, FILE *stream)
{
	*input_len = 1024;

	if (input_len == NULL || stream == NULL)
	{
		fprintf(stderr, "Invalid parameters\n");
		return (-1);
	}

	*store = malloc(sizeof(char) * (*input_len));

	if (*store == NULL)
	{
		perror("memory allocation failed");
		return (-1);
	}

	if (fgets(*store, *input_len, stream) == NULL)
	{
		free(*store);
		return (-1);
	}
	*input_len = strlen(*store);

	*store = realloc(*store, sizeof(char) * (*input_len + 1));
	if (*store == NULL)
	{
		perror("memory allocation failed");
		return (-1);
	}

	char *newline = strchr(*store, '\n');

	if (newline != NULL)
		*newline = '\0';

	return ((ssize_t)*input_len);
}
