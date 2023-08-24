#include "main.h"

/**
 * do_fork - creates child process and executes command
 * @vars: global variables struct
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

			if (errno == ENOENT)
			{
				vars->e_status = 2;
			}
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
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			if (status == ENOENT)
			{
				vars->e_status = 2;
			}
		}
		return (0);
	}
	print_error(vars, NULL);
	vars->e_status = 127;
	return (-1);
}
/**
 * execute_cmd - executes command
 * @vars: global variables struct
 * Return: 0 on success and -1 on failure
 */
int execute_cmd(var_t *vars)
{
	int a , b , c, d;
	int e, status;
	


	if (vars->args[0] && (execute_builtin(vars) == 1))
	{
		vars->line_count++;
		if ((vars->args[0][0] != '/')  && (vars->args[0][0] != '.'))
		{
			vars->path = find_file_in_path(vars);
		}
		else
		{
			if (test_path(vars))
			{
				vars->path = vars->args[0];
			}
		}
		a = ((access(vars->path, X_OK) == 0) && (vars->path != NULL));
		b = isatty(STDIN_FILENO);
		c = (vars->PATH != NULL);
		d = (vars->args[0][0] == '/');
		e = (vars->args[0][0] == '.');

		if (a && (b || c || d))
		{
			status = do_fork(vars);
			if (!d && !e)
			{
				free(vars->path);
			}

			return (status);
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
 * @vars: global variables struct
 * Return: 0 on success and -1 on failure
 */
int test_path(var_t *vars)
{
	struct stat st;

	stat(vars->args[0], &st);

	return (S_ISREG(st.st_mode));
}
