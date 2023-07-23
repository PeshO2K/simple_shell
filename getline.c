#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t my_getline(char **store, size_t *input_len, FILE *stream)
{

	if (input_len == NULL || stream == NULL)
	{
		fprintf(stderr, "Invalid parameters\n");
		return (-1);
	}

	/* arbitrary buffer size */
	*input_len = 1024;

	/* allocate buffer */
	*store = malloc(sizeof(char) * (*input_len));

	if (*store == NULL)
	{
		perror("memory allocation failed");
		return (-1);
	}

	/* read from stream */
	if (fgets(*store, *input_len, stream) == NULL)
	{
		/* free buffer if nothing is read */
		free(*store);
		return (-1);
	}
	/* get the length of the string */
	*input_len = strlen(*store);

	/* resize buffer to fit the string */
	*store = realloc(*store, sizeof(char) * (*input_len + 1));

	if (*store == NULL)
	{
		perror("memory allocation failed");
		return (-1);
	}

	/*removes the newline character*/
	char *newline = strchr(*store, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
	return ((ssize_t)*input_len);
}

int main(void)
{
	char *line = NULL;
	size_t n = 0;

	while (my_getline(&line, &n, stdin) != -1)
	{
		printf("You entered: %s\n", line);
	}

	free(line);

	return (0);
}
