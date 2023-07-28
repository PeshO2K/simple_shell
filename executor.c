#include "main.h"

/**
 * do_fork - creates child process and executes command
 * @args: arguments
 * @env: environment variable
 * Return: 0 on success and -1 on failure
 */
int do_fork(char **args, char **env)
{
	int status;
	pid_t child_pid;


	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(_getenv("_"));
			return (1);
		}
	}
	else if (child_pid < 0)
	{
		printf("No forking");
	}
	else
	{
		wait(&status);
	}
	return (1);
}
/**
 * execute_cmd - creates child process and executes command
 * @args: arguments
 * @env: environment variable
 * Return: 0 on success and -1 on failure
 */
int execute_cmd(char **args, char **env)
{
	if (args[0] && (execute_builtin(args) == -1))
	{
		if (strncmp(args[0], "/", 1) != 0)
		{
			args[0] = find_file_in_path(args[0]);

			if (!args[0])
			{
				/*printf("None fork null\n");*/
				perror(_getenv("_"));
				return (1);
			}
		}
		return (do_fork(args, env));
	}
	return (1);
}
