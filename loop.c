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
	int mode;
	char *buf;
	(void) argv;

	mode = isatty(STDIN_FILENO);
	/*printf("\n In loop, mode: %d\n", mode);*/
	

	while(r != -1)
	{
		if (mode == 1)
		{
			_puts("$ ");
		}
		

		/*signal(SIGINT,sigintHandler);*/
		

		getline(&buf, 0, stdin);
		if ((buf))
		{
			printf("%s",buf);
			return (0);
		}
		
		if (r != -1)
		{
			set_vars(vars, argv);
			execute_cmd(vars);

		}
		r = -1;
	}

	return (0);
}
