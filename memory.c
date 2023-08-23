#include "main.h"

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 * Return: nothing
 */
void ffree(char ***pp)
{
	/*char **a = pp;*/
	int i = 0;
	while(*pp && (*pp)[i] != NULL)
	{
		free((*pp)[i]);
		i++;
	}
	free(*pp);
	/*

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);*/
}
