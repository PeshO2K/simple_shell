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
	static char *next;
	char *start;

	if (str)
	{
		next = str;
	}
	if (!next)
	{
		return (NULL);
	}
	while (*next && strchr(delim, *next))
	{
		next++;
	}
	if (!*next)
	{
		return (NULL);
	}
	start = next;
	while (*next && !strchr(delim, *next))
	{
		next++;
	}
	if (*next)
	{
		{
			*next++ = '\0';
		}
	}
	return (start);
}
/**
 * parse - returns argument vector
 * @cmd: the string to split, or NULL to continue with the previous string
 * @delim: the delimiter string that contains the characters to split by
 *
 * Return: a pointer to the next token in the string, or NULL if there are none
 */
char **parse(const char *cmd, const char *delim)
{
	char **tokens; /*[];*/
	char *token, *str;
	int i = 0;

	tokens = malloc(strlen(cmd) * sizeof(char *));
	str = malloc(sizeof(char) * sizeof(cmd));
	strcpy(str, cmd);

	for (;; i++, str = NULL)

	{
		token = my_strtok(str, delim);
		tokens[i] = token;/*strtok (str, delim);*/
		if (token == NULL)
		{
			break;
		}
		/* printf("arg[%d] -> %s\n",i,tokens[i]);*/
	}
	free(str);
	return (tokens);
}
