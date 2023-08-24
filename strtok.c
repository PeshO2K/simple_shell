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
	while (*next && _strchr(delim, *next))
	{
		next++;
	}
	if (!*next)
	{
		return (NULL);
	}
	start = next;
	while (*next && !_strchr(delim, *next))
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
	char **tokens, *token, *str; 
	int i = 0, j, size = 10;
	/*printf("\t\tThe command: %s\n", cmd);*/
	if(!(tokens = malloc((size + 1) * sizeof(char *))))
	{
		return (NULL);
	}
	if (!(str = malloc((_strlen(cmd) + 1))))
	{
		ffree(tokens);
		return (NULL);
	}
	_strcpy(str, cmd);
	for (;; i++, str = NULL)
	{
		if ((token = my_strtok(str, delim)) == NULL)
		{
			break;
		}
		else
		{
			if(!(tokens[i] = _strdup(token)))
			{
				for (j = 0; j < 1; j++)
				{
					free(tokens[j]);
				}
				free(tokens);
				free(str);
				return (NULL);
			}
		}
	}
	tokens[i] = NULL;
	free(str);
	return (tokens);	
}
/**
 * _isalpha - if string is alphabet
 * @s: string
 * Return: 1 if true and 0 false
 */
int _isalpha(char *s)
{
	while (*s)
	{
		if (((*s > 64) && (*s < 91)) || ((*s > 96) && (*s < 123)))
		{
			return (1);
		}
		s++;
	}
	return (0);

}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy
 * Return: pointer of an array of chars
 */
char *_strdup(const char *str)
{
	size_t len;
	char *str2;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str) + 1;
	str2 = malloc(len * sizeof(char));

	if (str2)
	{
		_memcpy(str2, str, len);
	}
	else 
	{
		free(str2);
		return (NULL);
	}
	return (str2);
}
/**
 * _memcpy - copies n bytes from src to dest
 * @n: no of bytes
 * @src: source
 * @dest: destination
 * Return: dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	char *cdest = (char *)dest;
	char *csrc = (char *)src;


	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}
	return (dest);
}
