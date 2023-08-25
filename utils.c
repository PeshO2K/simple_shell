#include "main.h"
/**
 * reset_vars- initializes var_t struct
 * @vars: struct address
 * Return: nothing
 */
void reset_vars(var_t *vars)
{
	vars->line = NULL;
	vars->args = NULL;
	vars->path = NULL;
	vars->err_num = 0;
}
/**
 * set_vars - initializes reset_vars struct
 * @vars: struct address
 * @argv: argument vector
 * Return: nothing
 */
void set_vars(var_t *vars, char **argv)
{
	int i = 0;
	vars->myname = argv[0];
	if (vars->line)
	{
		vars->args = parse(vars->line, DELIM);
		if (!(vars->args))
		{
			ffree(vars->args);
			vars->args = NULL;
			vars->args = malloc(sizeof(char *) * 2);
			if (vars->args)
			{
				vars->args[0] = _strdup(vars->line);
				vars->args[1] = NULL;
			}
		}
		for (i = 0; vars->args && vars->args[i]; i++)
		{
			/*printf("My args: %d: %s\n", i, vars->args[i])*/;
		}
		vars->argsc = i;
	}
}

/**
 * free_vars - frees var_t struct fields
 * @vars: struct address
 * @all: true if freeing all fields
 * Return: nothing
 */
void free_vars(var_t *vars, int all)
{
	/* don't forget to free args*/
	if (vars->args)
	{
		ffree(vars->args);
		vars->args = NULL;
	}

	if (all)
	{
		if (vars->path)
		{
			free(vars->path);
		}
		if (vars->PATH)
		{
			free_list(vars->PATH);
		}

		ffree((vars->env));
		vars->env = NULL;
	}
}
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
}
/**
 * interactive - returns true if shell is interactive mode
 * @vars: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(var_t __attribute__((__unused__)) *vars)
{
	int mode;

	mode = isatty(STDIN_FILENO);

	return (mode && 1);
}
