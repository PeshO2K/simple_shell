#include "main.h"

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 * Return: nothing
 */
void ffree(char **pp)
{
	int i;
	if (!pp)
	{
		return;
	}
	for (i = 0; pp[i]; i++)
	{
		free(pp[i]);
	}
	free(pp);
}
