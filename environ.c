#include "main.h"
/**
 * _getenv - finds environment variable
 *@name: env variable name
 *@vars: struct address
 * Return: NULL on failure pointer on sucess
 */
char *_getenv(var_t *vars, const char *name)
{
	/*printf("getting emvironment variable\n");*/
	char **s = vars->env;
	size_t len = strlen(name);

	/*printf("starting for loop...\n");*/

	for (; *s; s++)
	{
		if ((strncmp(name, *s, len) == 0) && ((*s)[len] == '='))
		{
			return (*s + len + 1);
		}
	}
	return (NULL);
}
