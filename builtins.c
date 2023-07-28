#include "main.h"
/**
 * _my_exit - implements exit and arguments
 *@ag: takes arguments
 * Return: Exit status
 */
int _my_exit(char **ag)
{
	int exit_status = 0;

	if (ag[1])
	{
		exit_status = atoi(ag[1]);
	}

	exit(exit_status);
}

/**
 * _my_env - prints environment variables
 *@ag: takes arguments
 * Return: 0 always
 */
int _my_env(char **ag)
{
	char **env = environ;
	(void) ag;


	for (; *env; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * execute_builtin - finds and execute builtin fxn
 *@ag: takes arguments
 * Return: 0 on success -1 on failure
 */
int execute_builtin(char **ag)
{

	builtin_t builtins[] = {
		{"exit", _my_exit},
		{"env", _my_env},
		{"cd", _my_cd},
		{"alias", _my_alias},
		{NULL, NULL}
};
	int i = 0;

	/*printf("\nIn builtins\n");*/
	for (; builtins[i].name; i++)
	{
		if (strcmp(ag[0], builtins[i].name) == 0)
		{
			return ((builtins[i].func)(ag));
		}
	}
	/*printf("\nI am not a builtin\n");*/
	return (-1);
}

/**
 * _my_alias - finds alias of fxn
 *@ag: takes arguments
 * Return: 0 on sucess and -1 failure
 */
int _my_alias(char **ag)
{
	(void) ag;
	return (0);
}

/**
 * _my_cd - changes working directory
 *@ag: takes arguments
 * Return: 0 on sucess and -1 failure
 */
int _my_cd(char **ag)
{
	(void) ag;
	return (0);
}
