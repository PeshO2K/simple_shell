#include "main.h"
char *_getenv(const char *name)
{
	char *s = *environ;

	for (; s; s++)
	{
		if((strncmp(name, s, strlen(name)) == 0) && (s[strlen(name)] == '='))
		{
			return (&s[strlen(name) + 1]);
		}
	}
	return (NULL);
}
