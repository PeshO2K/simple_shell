#include "main.h"
builtin_t builtins[] = {
	{"exit", _exit},
	{"env", _env},
};
void _exit(char **ag)
{
	int exit_status = 0;

	if (ag[1])
	{
		exit_status = atoi(ag[1]);
	}

	exit(exit_status);
}

void _env(char **ag)
{
	char **env = environ;

	for (; *env; env++)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	
}
