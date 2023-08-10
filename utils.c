#include "main.h"
/**
 * reset_vars- initializes var_t struct
 * @vars: struct address
 */
void reset_vars(var_t *vars)
{
	/*printf("Reseting vars ...");*/
	vars->line = NULL;
	vars->args = NULL;
	vars->path = NULL;
	/*printf("\nSuccess\n");*/
	/*vars->line = NULL;*/
}
/**
 * set_vars - initializes reset_vars struct
 * @vars: struct address
 * @argv: argument vector
 */
void set_vars(var_t *vars, char **argv)
{
	/*int i = 0;*/
	/*printf("\nsetting variables ...\n");*/

	vars->myname = argv[0];
	/*printf("NAme set, building path ...\n");*/
	/*vars->PATH = build_path_list(vars);*/
	/*printf("path built\n");*/
	if (vars->line)
	{
		vars->args = parse(vars->line, DELIM);
		if (!vars->args)
		{

			vars->args = malloc(sizeof(char *) * 2);
			if (vars->args)
			{
				vars->args[0] = strdup(vars->line);
				vars->args[1] = NULL;
			}
		}
		/*for (i = 0; vars->argv && vars->argv[i]; i++)*/
		/*	;*/
		/*info->argc = i;*/

		/*replace_alias(info);*/
		/*replace_vars(info);*/
	}
}

/**
 * free_vars - frees var_t struct fields
 * @vars: struct address
 * @all: true if freeing all fields
 */
void free_vars(var_t *vars, int all)
{
	ffree(vars->args);
	vars->args= NULL;
	vars->path = NULL;
	if (all)
	{
		free(vars->line);
		if (vars->PATH)
			free_list(vars->PATH);

		ffree(vars->env);
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
