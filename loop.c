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
	ssize_t ret = 0;
	int bin_ret = 0;

	while (ret != -1 && bin_ret != -2)
	{
		reset_vars(vars);
		if (interactive(vars))
			_puts("$ ");

		ret = get_input(vars);
		if (ret != -1)
		{
			set_vars(vars, argv);
			bin_ret = execute_builtin(vars);
		}
		else if (interactive(vars))
			_putchar('\n');
		free_vars(vars, 0);
	}
	free_vars(vars, 1);
	if (!interactive(vars) && vars->e_status)
		exit(vars->e_status);
	if (bin_ret == -2)
	{
		if (vars->err_num == -1)
			exit(vars->e_status);
		exit(vars->err_num);
	}
	return (bin_ret);
}
