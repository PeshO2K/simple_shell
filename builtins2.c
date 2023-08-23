#include "main.h"
int _my_setenv(var_t *vars)
{
	if (vars->argsc != 3)
	{
		print_error(vars, "Usage: setenv VARIABLE VALUE");
		return (-1);
	}
	_setenv(vars, vars->args[1], vars->args[2]);
	return (0);
}
int _my_unsetenv(var_t *vars)
{
	if (vars->argsc != 2)
	{
		print_error(vars, "Usage: unsetenv VARIABLE");
		return (-1);
	}
	_unsetenv(vars, vars->args[1]);
	return (0);
}

