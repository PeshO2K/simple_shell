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
	/*while (*pp)
	{
		free(*pp++);
	}
	free(a);
	
	int i = 0;
	while(*pp && (*pp)[i] != NULL)
	{
		free((*pp)[i]);
		i++;
	}
	free(*pp);
	*/
}
