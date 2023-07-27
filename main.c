#include "main.h"
/**
 * main - Entry point
 * @ac: number of arguments
 * @ag: argument vector
 * Return: 0 Success
 */
int main(int ac  __attribute__((unused)), char **ag __attribute__((unused)))
{
	char *line, *filepath = NULL;
	size_t line_size = 0;
	char **args;
	int int_mode = 1;/* i;*/

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
		{
			printf("$ ");
		}
		my_getline(&line, &line_size, stdin);
		args = parse(line, " \n");
		if (strncmp(args[0], "/", 1) == 0)
		{
			filepath = args[0];
		}
		else
		{
			if (execute_builtin(args) == -1)
			{
				filepath = find_file_in_path(args[0]);
				if (!filepath)
				{
					perror(_getenv("_"));
				}
				else
				{
					args[0] = filepath;
				}
			}
		}
		if (filepath)
		{
			execute_cmd(args, environ);
		}
		free(line);
		free(filepath);
		free(args);
	}
	return (0);
}
