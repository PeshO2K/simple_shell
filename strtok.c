#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * my_strtok - splits a string into tokens using a delimiter
 * @str: the string to split, or NULL to continue with the previous string
 * @delim: the delimiter string that contains the characters to split by
 *
 * Return: a pointer to the next token in the string, or NULL if there are none
 */
char *my_strtok(char *str, const char *delim)
{
	char *start_of_token;
	char *end_of_token;
	static char *next_token;

	if (delim == NULL || *delim == '\0')
		return (NULL);

	if (str == NULL && next_token == NULL)
		return (NULL);

	if (str != NULL)
		next_token = strdup(str);

	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	start_of_token = next_token;
	end_of_token = strpbrk(next_token, delim);
	if (end_of_token != NULL)
	{
		*end_of_token = '\0';
		next_token = end_of_token + 1;
	}
	else
	{
		next_token = NULL;
	}
	return (start_of_token);
}
