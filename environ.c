#include "main.h"
/**
 * _getenv - finds environment variable
 *@name: env variable name
 * Return: NULL on failure pointer on sucess
 */
char *_getenv(const char *name)
{
	char *s = *environ;

	for (; s; s++)
	{
		if ((strncmp(name, s, strlen(name)) == 0) && (s[strlen(name)] == '='))
		{
			return (&s[strlen(name) + 1]);
		}
	}
	return (NULL);
}
