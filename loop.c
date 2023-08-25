#include "main.h"
/**
 * shell_loop - main shell loop
 * @vars: the parameter & return info struct
 * @argv: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */

int shell_loop(var_t *vars, char **argv)
{
	ssize_t r = 0;
	size_t len = 0;
	int mode;

	mode = isatty(STDIN_FILENO);
	while (r != -1)
	{
		reset_vars(vars);

		if (mode == 1)
		{
			_puts("$ ");
		}
		signal(SIGINT, sigintHandler);
		r = getline(&(vars->line), &len, stdin);
		/*printf("\tthe line length:%lu\t\n", r);*/
		if (r != -1)
		{
			comment_handler(vars->line);
			separator_handler(vars->line);
			set_vars(vars, argv);
			execute_cmd(vars);
		}
		if ((vars->line))
		{
			free(vars->line);
		}
		free_vars(vars, 0);
		if (vars->err_num == -2)
		{
			break;
		}
	}
	free_vars(vars, 1);
	if (vars->e_status || vars->err_num == -2)
	{
		exit(vars->e_status);
	}
	return (0);
}
