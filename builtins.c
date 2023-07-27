#include "main.h"
int _my_exit(char **ag)
{
	int exit_status = 0;

	if (ag[1])
	{
		exit_status = atoi(ag[1]);
	}

	exit(exit_status);
}

int _my_env(char **ag)
{
	(void) ag;
	char **env = environ;

	for (; *env; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

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

int _my_alias(char **ag)
{
	(void) ag;
	return (0);
}

int _my_cd(char **ag)
{
	(void) ag;
	return (0);
}
