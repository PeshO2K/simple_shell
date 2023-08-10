#include "main.h"
/**
 * _my_exit - implements exit and arguments
 *@vars: takes arguments
 * Return: Exit status
 */
int _my_exit(var_t *vars)
{
	int exit_status;

	if (vars->args[1])
	{
		exit_status = _atoi(vars->args[1]);
		if (exit_status == -1)
		{
			vars->e_status = 2;
			print_error(vars, ": Illegal number: ");
			_errputs(vars->args[1]);
			_errputs("\n");
			return (1);
		}
		vars->err_num = exit_status;
		return (-2);
	}
	vars->err_num = -1;
	return (-2);
}

/**
 * _my_env - prints environment variables
 *@vars: takes arguments
 * Return: 0 always
 */
int _my_env(var_t *vars)
{
	unsigned int i;

	
	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->e_status = 0;
	return (0);
}

/**
 * execute_builtin - finds and execute builtin fxn
 *@vars: takes arguments
 * Return: 0 on success -1 on failure
 */
int execute_builtin(var_t *vars)
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
		if (strcmp(vars->args[0], builtins[i].name) == 0)
		{
			vars->line_count++;
			return (builtins[i].func(vars));
		}
	}
	/*printf("\nI am not a builtin\n");*/
	return (-1);
}

/**
 * _my_alias - finds alias of fxn
 *@vars: takes arguments
 * Return: 0 on sucess and -1 failure
 */
int _my_alias(var_t *vars)
{
	(void) vars;
	return (0);
}

/**
 * _my_cd - changes working directory
 *@vars: takes arguments
 * Return: 0 on sucess and -1 failure
 */
int _my_cd(var_t *vars)
{
	(void) vars;
	return (0);
}
