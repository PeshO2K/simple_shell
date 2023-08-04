#include "main.h"

/**
 * do_fork - creates child process and executes command
 * @vars: var struct arguments
 * Return: 0 on success and -1 on failure
 */
int do_fork(var_t *vars)
{
	int status;
	pid_t child_pid;


	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(vars->path, vars->args, vars->env) == -1)
		{
			print_error(vars, NULL);
			return (-1);
		}
	}
	else if (child_pid < 0)
	{
		print_error(vars, NULL);
		return (-1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
/**
 * execute_cmd - creates child process and executes command
 * @vars: var struct arguments
 *
 * Return: 0 on success and -1 on failure
 */
int execute_cmd(var_t *vars)
{
	char *cmd_path;


	if (vars->args[0] && (execute_builtin(vars) == -1))
	{
		vars->line_count++;
		if (strncmp(vars->args[0], "/", 1) != 0)
		{
			cmd_path = find_file_in_path(vars);

			if (cmd_path)
			{
				vars->path = cmd_path;
			}
		}
		else
		{
			if (test_path(vars) == 0)
			{
				vars->path = vars->args[0];
			}
		}
		if (vars->path)
		{
			return (do_fork(vars));
		}
		else
		{
			vars->e_status = 127;
			print_error(vars, "not found\n");
		}
	}
	return (-1);
}

/**
 * test_path - test path provided
 * @vars: arguments
 * Return: 0 on success and -1 on failure
 */
int test_path(var_t *vars)
{
	struct stat st;

	return (stat(vars->args[0], &st));
}
