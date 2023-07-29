#include "main.h"


/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: argument vector
 * @environ: env variable
 * Return: 0 Success
 */
int main(int argc, char **argv, char **environ)
{
	var_t vars = { VAR_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_errputs(argv[0]);
				_errputs(": 0: Can't open ");
				_errputs(argv[1]);
				_errputs('\n');
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		var->rdfd = fd;
	}
	/*populate_env_list(info);*/
	/*read_history(info);*/
	shell_loop(vars, argv);
	return (EXIT_SUCCESS);
}
