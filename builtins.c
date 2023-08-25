#include "main.h"
/**
 * _my_exit - implements exit and arguments
 * @vars: global variables struct
 * Return: 0
 */
int _my_exit(var_t *vars)
{
	if (vars->args[1])
	{ 
		vars->e_status = _atoi(vars->args[1]);

		if ((vars->e_status < 0) || (_isalpha(vars->args[1])))
		{
			vars->e_status = 2;
			print_error(vars, "Illegal number: ");
			_errputs(vars->args[1]);
			_errputs("\n");
		}
		else if(vars->e_status > 255)
		{
			vars->e_status = 232;
		}

		
	}
	vars->err_num = -2;
	/*free_vars(vars, 1);
	exit(vars->e_status);*/
	return (0);
	
}

/**
 * _my_env - prints environment variables
 * @vars: global variables struct
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
 * _my_alias - finds alias of fxn
 * @vars: global variables struct
 * Return: 0 on sucess and -1 failure
 */
int _my_alias(var_t *vars)
{
	(void) vars;
	return (0);
}

/**
 * _my_cd - changes working directory
 * @vars: global variables struct
 * Return: 0 on sucess and -1 failure
 */
int _my_cd(var_t *vars)
{
	char *dir_path;

	if (vars->argsc == 1)
	{
		if(!(dir_path = _getenv(vars, "HOME")))
		{
			dir_path = _getenv(vars, "PWD");
		}
	} 
	else if (_strcmp(vars->args[1], "-") == 0)
	{
		if (!(dir_path = _getenv(vars, "OLDPWD")))
		{
			_puts(_getenv(vars, "PWD"));
			_puts("\n");
			return (0);
		}
		_puts(dir_path);
		_puts("\n");
	}
	else
	{
		dir_path = vars->args[1];
	}
	return (_chdir(vars, dir_path));
}

/**
 * execute_builtin - finds and execute builtin fxn
 * @vars: global variables struct
 * Return: 0 on success -1 on failure
 */
int execute_builtin(var_t *vars)
{
	builtin_t builtins[] = {
		{"exit", _my_exit},
		{"env", _my_env},
		{"cd", _my_cd},
		{"alias", _my_alias},
		{"setenv", _my_setenv},
		{"unsetenv", _my_unsetenv},
		{NULL, NULL}
};
	int i = 0;

	for (; builtins[i].name; i++)
	{
		if (_strcmp(vars->args[0], builtins[i].name) == 0)
		{
			vars->line_count++;
			return (builtins[i].func(vars));
		}
	}
	return (1);
}
