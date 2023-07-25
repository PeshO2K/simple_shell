#include "main.h"
int _exit(char **ag)
{
	int exit_status = 0;

	if (ag[1])
	{
		exit_status = atoi(ag[1]);
	}

	exit(exit_status);
}

int _env(char **ag)
{
	char **env = environ;

	for (; *env; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

int execute_builtin(char **ag)
{
	builtin_t builtins[] = {
		{"exit", _exit},
		{"env", _env},
		{"cd", _cd},
		{"alias", _alias},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
};
	int i = 0;

	for (; builtins[i].name; i++)
	{
		if (strcmp(ag[0], builtins[i].name) == 0)
		{
			return ((*builtins[i].func)(ag));
		}
	}
	return (-1);
}

int _alias(char **ag)
{
	return (0);
}

int _cd(char **ag)
{
	return (0);
}
