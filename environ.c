#include "main.h"
/**
 * _getenv - finds environment variable
 *@name: env variable name
 *@vars: struct address
 * Return: NULL on failure pointer on sucess
 */
char *_getenv(var_t *vars, const char *name)
{
	char **s = vars->env;

	for (; *s; s++)
	{
		if ((strncmp(name, *s, strlen(name)) == 0) && (*s[strlen(name)] == '='))
		{
			return (*s + strlen(name) + 1);
		}
	}
	return (NULL);
}
