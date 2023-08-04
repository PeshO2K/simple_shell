#include "main.h"


/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: argument vector
 * @environ: env variable
 * Return: 0 Success
 */
int main(int argc, char **argv)
{
	(void) argc;
	var_t vars [] = { VAR_INIT };
	/*(void) vars;*/

	/*printf("Initialized %s",argv[0]);*/

	/*populate_env_list(info);*/
	/*read_history(info);*/
	vars->env = environ;
	shell_loop(vars, argv);
	return (EXIT_SUCCESS);
}
