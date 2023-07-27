#include "main.h"

/**
 * execute_cmd - creates child process and executes command
 * @args: arguments
 * @env: environment variable
 * Return: 0 on success and -1 on failure
 */
int execute_cmd(char **args, char **env)
{
	int status;
	pid_t child_pid;


	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(_getenv("_"));
		}
	}
	else if (child_pid < 0)
	{
		printf("No forking");
	}
	else
	{
		wait(&status);
		return (0);
	}

	return (-1);

}
