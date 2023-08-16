#include "main.h"


/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: argument vector
 * @environ: env variable
 * Return: 0 Success
 */
int main(int __attribute__((__unused__)) argc, char **argv, char **environ)
{
	var_t vars [] = { VAR_INIT };
	/*int fd;
	 * */ 
	/*(void) vars;*/

	/*printf("Initialized %s",argv[0]);*/

	/*populate_env_list(info);*/
	/*read_history(info);*/
	/*_puts(environ[0]);*/
	/*
	 * if (argc == 2)
	 * {
	 * 	if((fd = open(argv[1]))
	 * 	
	 * }*/
	vars->env = copyenv(environ);

	if(*(vars->env))
	{
		
		vars->PATH = build_path_list(vars);
	}
	
	/*vars->PATH = build_path_list(vars);*/
	

	shell_loop(vars, argv);
	return (EXIT_SUCCESS);
}
