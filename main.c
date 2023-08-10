#include "main.h"


/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: argument vector
 * @environ: env variable
 * Return: 0 Success
 */
int main(int __attribute__((__unused__)) argc, char **argv)
{
	var_t vars [] = { VAR_INIT };
	/*(void) vars;*/

	/*printf("Initialized %s",argv[0]);*/

	/*populate_env_list(info);*/
	/*read_history(info);*/
	vars->env = copyenv(environ);
	
	vars->PATH = build_path_list(vars);

	shell_loop(vars, argv);
	return (EXIT_SUCCESS);
}
