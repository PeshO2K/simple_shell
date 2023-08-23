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
	

	mode = isatty(STDIN_FILENO);

	while(r != -1)
	{
		reset_vars(vars);

		if (mode == 1)
		{
			_puts("$ ");
		}
		

		signal(SIGINT,sigintHandler);
		
		/*printf("Bginning line reading \n");*/
		r = getline(&(vars->line), &len, stdin);

		/*printf("Success reading line\n");*/

		
		if (r != -1)
		{
			
			set_vars(vars, argv);
			/*handle command separators here**/
			execute_cmd(vars);

		}
		
	}

	free_vars(vars, 1);

	return (0);
}
