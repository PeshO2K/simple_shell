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
	char *buf = NULL; 
	

	mode = isatty(STDIN_FILENO);
	/*printf("\n In loop, mode: %d\n", mode);*/
	

	while(r != -1)
	{
		reset_vars(vars);

		if (mode == 1)
		{
			_puts("$ ");
		}
		

		signal(SIGINT,sigintHandler);
		
		/*printf("Bginning line reading \n");*/
		r = my_getline(&(vars->line), &len, stdin);
		/*printf("Success reading line\n");*/

		if (buf != NULL)
		{
			printf ("Printing buffer\n");
			printf("%s\n",buf);
			return (0);
		}
		
		if (r != -1)
		{
			/*rintf("Executing cmd \n");*/
			set_vars(vars, argv);
			execute_cmd(vars);

		}
		
	}

	return (0);
}
